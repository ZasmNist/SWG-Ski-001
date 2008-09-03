/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
 */

#include "RadialManager.h"

#include "../../packets/object/ObjectMenuResponse.h"
#include "../../packets/trade/BeginTradeMessage.h"

#include "../../Zone.h"
#include "../../objects.h"

#include "../../objects/player/sui/listbox/SuiListBoxImplementation.h"
#include "../../objects/player/sui/colorpicker/SuiColorPickerImplementation.h"
#include "../../objects/player/sui/banktransferbox/SuiBankTransferBoxImplementation.h"

#include "../bazaar/BazaarManager.h"
#include "../bazaar/BazaarManagerImplementation.h"
#include "../bank/BankManager.h"
#include "../bank/BankManagerImplementation.h"

RadialManager::RadialManager() {
}

void RadialManager::handleRadialRequest(Player* player, Packet* pack) {
	pack->shiftOffset(12); // skip ObjectID and size

	uint64 objectid = pack->parseLong();
	uint64 playerid = pack->parseLong();

	ObjectMenuResponse* omr;
	omr = parseDefaults(player, objectid, pack);

	Zone* zone = player->getZone();

	if (zone == NULL) {
		delete omr;
		return;
	}

	SceneObject* object = zone->lookupObject(objectid);

	if (object == NULL)
		object = player->getPlayerItem(objectid);

	if (object == NULL) {
		sendDefaultRadialResponse(player, omr);
	} else {
		try {
			if (object != player)
				object->wlock(player);

			object->sendRadialResponseTo(player, omr);

			if (object != player)
				object->unlock();
		} catch (...) {
			if (object != player)
				object->unlock();
			cout << "unreported exception caught in RadialManager::handleRadialRequest\n";
		}
	}
}

void RadialManager::handleRadialSelect(Player* player, Packet* pack) {
	SceneObject* obj = NULL;

	try {
		player->wlock();

		uint64 objectID = pack->parseLong();
		uint8 radialID = pack->parseByte();

		Zone* zone = player->getZone();

		if (zone == NULL) {
			player->unlock();
			return;
		}

		obj = zone->lookupObject(objectID);

		//TODO: Get a bazaar object to pass to the next functions
		BazaarManager* bazaarManager = zone->getZoneServer()->getBazaarManager();

		if (bazaarManager->isBazaarTerminal(objectID)) {
			sendRadialResponseForBazaar(objectID, player);

			player->unlock();
			return;
		}

		BankManager* bankManager = zone->getZoneServer()->getBankManager();

		if (bankManager->isBankTerminal(objectID)) {
			sendRadialResponseForBank(objectID, player);

			player->unlock();
			return;
		}

		if (obj == NULL) {
			obj = player->getInventoryItem(objectID);

			if (obj == NULL)
				obj = player->getDatapadItem(objectID);

			if (obj == NULL) {
				player->unlock();
				return;
			}
		}

		handleSelection(radialID, player, obj);

	} catch (...) {
		cout << "unreported exception on ZonePacketHandler:::handleUseItem(Message* pack)\n";
		player->unlock();
	}
}

void RadialManager::handleSelection(int radialID, Player* player, SceneObject* obj) {
	// Pre: player is wlocked, obj is unlocked
	// Post: player and obj unlocked

	switch (radialID) {
	case 7: // EXAMINE
		break;
	case 8: // TRADE
		handleTrade(player, obj);
		break;
	case 14: // DESTROY
		break;
	case 20: // ITEM_USE
		obj->useObject(player);
		break;
	case 35:  // LOOT
		player->lootCorpse();
		break;
	case 36:  // LOOT_ALL
		player->lootCorpse(true);
		break;
	case 45: // Open vendor
		sendRadialResponseForBazaar(obj->getObjectID(), player);
		break;
	case 60: // VEHICLE_GENERATE
		player->unlock();

		handleVehicleGenerate(obj);
		return;
	case 61: // VEHICLE_STORE
		player->unlock();

		handleVehicleStore(obj);
		return;
	case 68: // SERVER_MENU1 using to change color on wearables (temporary)
		handleWearableColorChange(player, obj);
		break;
	case 69: // SLICING
		handleSlicing(player, obj);
		break;
	case 70: // REPAIR
		handleRepair(player, obj);
		break;
	case 71: // REMOVE POWERUP
		handleRemovePowerup(player, obj);
		break;
	case 108: // Harvest Meat
		handleHarvest(player, obj, 1);
		break;
	case 109: // Harvest Hide
		handleHarvest(player, obj, 2);
		break;
	case 110: // Harvest Bone
		handleHarvest(player, obj, 3);
		break;
	case 130: // Crafting tool hopper item retrieval
		handleOpenCraftingToolHopper(player, obj);
		break;
	case 136: // SURVEY_TOOL_OPTIONS
		break;
	case 137: // SURVEY_TOOL_SET_RANGE
		sendRadialResponseForSurveyToolRange(player, obj);
		break;
	case 148: // Harvest
		handleHarvest(player, obj, 0);
		break;
	case 187: // SERVER_GUILD_INFO
		break;
	case 188: // SERVER_GUILD_MEMBERS
		break;
	case 190: // SERVER_GUILD_ENEMIES
		break;
	case 194: // SERVER_GUILD_GUILD_MANAGEMENT
		break;
	case 195: // SERVER_GUILD_MEMBER_MANAGEMENT
		break;
	default:
		//cout << "Unkown radial selection received:" << radialID << "\n";
		break;
	}

	player->unlock();
}

ObjectMenuResponse* RadialManager::parseDefaults(Player* player, uint64 objectid, Packet* pack) {
	int size = pack->parseInt();

	ObjectMenuResponse* omr = new ObjectMenuResponse(player, objectid, 0);

	for (int i = 0; i < size; i++) {
		uint8 index = pack->parseByte();
		uint8 parentid = pack->parseByte();
		uint8 radialid = pack->parseByte();
		uint8 callback = pack->parseByte();

		//if (radialid == 20)
		callback = 3;

		pack->shiftOffset(4); // shift unicode command

		omr->addRadialItem(parentid, radialid, callback);
	}

	uint8 counter = pack->parseByte();
	omr->setCounter(counter);

	return omr;
}

void RadialManager::sendDefaultRadialResponse(Player* player, ObjectMenuResponse* omr) {
	omr->finish();

	player->sendMessage(omr);
}

void RadialManager::sendRadialResponseForBazaar(uint64 objectId, Player* player) {
	Zone* zone = player->getZone();

	BazaarManager* bazaarManager = zone->getZoneServer()->getBazaarManager();

	RegionBazaar* bazaar = bazaarManager->getBazaar(objectId);

	if (bazaar != NULL)
		bazaar->newBazaarRequest(objectId, player, player->getZoneID());
}

void RadialManager::sendRadialResponseForBank(uint64 objectId, Player* player) {
	Zone* zone = player->getZone();

	SuiBankTransferBox* sui = new SuiBankTransferBox(player, 0xD65E);

	sui->addCash(player->getCashCredits());
	sui->addBank(player->getBankCredits());

	player->addSuiBox(sui);
	player->sendMessage(sui->generateMessage());
}

void RadialManager::handleVehicleStore(SceneObject* obj) {
	if (obj->isIntangible()) {
		SceneObject* mount = ((IntangibleObject*)obj)->getWorldObject();
		if (mount == NULL)
			return;

		if (!mount->isNonPlayerCreature())
			return;

		if (!((Creature*)mount)->isMount())
			return;

		try {
			mount->wlock();

			((MountCreature*)mount)->store();

			mount->unlock();
		} catch (...) {
			mount->unlock();
		}

		return;
	}

	if (!obj->isNonPlayerCreature())
		return;

	if (!((Creature*)obj)->isMount())
		return;

	try {
		obj->wlock();

		((MountCreature*)obj)->store();

		obj->unlock();
	} catch (...) {
		cout << "Unreported exception caught in RadialManager::handleVehicleStore(Player* player, SceneObject* obj)\n";
		obj->unlock();
	}
}

void RadialManager::handleVehicleGenerate(SceneObject* obj) {
	if (!obj->isIntangible())
		return;

	SceneObject* mount = ((IntangibleObject*)obj)->getWorldObject();

	if (mount == NULL)
		return;

	if (!mount->isNonPlayerCreature())
		return;

	if (!((Creature*)mount)->isMount())
		return;

	try {
		mount->wlock();

		((MountCreature*)mount)->call();

		mount->unlock();
	} catch (...) {
		cout << "Unreported exception caught in RadialManager::handleVehicleGenerate\n";
		mount->unlock();
	}
}

void RadialManager::handleTrade(Player* player, SceneObject* obj) {
	if (!obj->isPlayer())
		return;

	Player* target = (Player*)obj;

	try {
		target->wlock(player);

		uint64 requestedID = target->getTradeRequestedPlayer();
		player->setTradeRequestedPlayer(obj->getObjectID());

		if (requestedID == player->getObjectID()) {
			BeginTradeMessage* msg = new BeginTradeMessage(target->getObjectID());
			player->sendMessage(msg);

			BeginTradeMessage* msg2 = new BeginTradeMessage(player->getObjectID());
			target->sendMessage(msg2);

		} else {
			Player* target = (Player*)obj;

			stringstream msg;
			msg << player->getCharacterName().c_str() << " requested a trade.";
			target->sendSystemMessage(msg.str());
		}

		target->unlock();
	} catch (Exception& e) {
		target->unlock();
		cout << e.getMessage() << "caught in RadialManager::handleTrade(Player* player, SceneObject* obj)\n";
	} catch (...) {
		target->unlock();
		cout << "Unreported exception caught in RadialManager::handleTrade(Player* player, SceneObject* obj)\n";
	}
}

void RadialManager::handleWearableColorChange(Player* player, SceneObject* obj) {
	if (!obj->isTangible())
		return;

	if (player->getTradeSize() != 0)
		return;

	TangibleObject* tano = (TangibleObject*) obj;

	if (!tano->isArmor())
		return;

	Armor* wearable = (Armor*) tano;

	if (player->getInventoryItem(wearable->getObjectID()) == NULL)
		return;

	SuiColorPicker* sui = new SuiColorPicker(player, wearable->getObjectID(), 0xBABE);

	player->addSuiBox(sui);
	player->sendMessage(sui->generateMessage());
}

void RadialManager::handleSlicing(Player* player, SceneObject* obj) {
	if (!obj->isTangible())
		return;

	if (player->getTradeSize() != 0)
		return;

	TangibleObject* tano = (TangibleObject*) obj;


	if (tano->isArmor()) {
		Armor* armor = (Armor*) tano;
		if (!armor->isSliced())
			armor->sliceArmor(player);
	} else if (tano->isWeapon()) {
		Weapon* weapon = (Weapon*) tano;
		if (!weapon->isSliced())
			weapon->sliceWeapon(player);
	}

}

void RadialManager::handleRepair(Player* player, SceneObject* obj) {
	if (!obj->isTangible())
		return;

	if (player->getTradeSize() != 0)
		return;

	TangibleObject* tano = (TangibleObject*) obj;

	try {
		tano->wlock();

		if (tano->isArmor()) {
			Armor* armor = (Armor*) tano;
			armor->repairArmor(player);
		} else if (tano->isWeapon()) {
			Weapon* weapon = (Weapon*) tano;
			weapon->repairWeapon(player);
		}

		tano->unlock();
	} catch (...) {
		cout << "unreported exception caught in RadialManager::handleRepair\n";
		tano->unlock();
	}
}

void RadialManager::handleRemovePowerup(Player* player, SceneObject* obj) {
	if (obj == NULL || !obj->isTangible())
		return;

	if (player->getTradeSize() != 0)
		return;

	TangibleObject* tano = (TangibleObject*) obj;

	if (!tano->isWeapon())
		return;

	Weapon* weapon = (Weapon*) tano;

	try {
		weapon->wlock();

		if (weapon->hasPowerup())
			weapon->removePowerup(player, false);

		weapon->unlock();
	} catch (...) {
		cout << "unreported exception caught in RadialManager::handleRemovePowerup\n";
		weapon->unlock();
	}
}


void RadialManager::sendRadialResponseForSurveyTools(Player* player, SurveyTool* surveyTool, ObjectMenuResponse* omr) {
	omr->addRadialItem(0, 136, 3, "@sui:tool_options");
	omr->addRadialItem(4, 137, 3, "@sui:survey_range");
	omr->finish();

	player->sendMessage(omr);
}

void RadialManager::sendRadialResponseForSurveyToolRange(Player* player, SceneObject* obj) {
	string skillBox = "crafting_artisan_novice";

	if (!player->hasSkillBox(skillBox)) {
		player->sendSystemMessage("error_message", "insufficient_skill");
		return;
	}

	string surveying = "surveying";

	int surveyMod = player->getSkillMod(surveying);

	SuiListBox* suiToolRangeBox = new SuiListBox(player, 0x7259);
	suiToolRangeBox->setPromptTitle("@base_player:swg");
	suiToolRangeBox->setPromptText("@survey:select_range");

	if (surveyMod >= 0)
		suiToolRangeBox->addMenuItem("64m x 3pts");

	if (surveyMod > 20)
		suiToolRangeBox->addMenuItem("128m x 4pts");

	if (surveyMod > 40)
		suiToolRangeBox->addMenuItem("192m x 4pts");

	if (surveyMod > 60)
		suiToolRangeBox->addMenuItem("256m x 5pts");

	if (surveyMod > 80)
		suiToolRangeBox->addMenuItem("320m x 5pts");

	player->addSuiBox(suiToolRangeBox);
	player->sendMessage(suiToolRangeBox->generateMessage());

	player->setSurveyTool((SurveyTool*) obj);
}

void RadialManager::handleOpenCraftingToolHopper(Player* player, SceneObject* obj) {
	if (obj == NULL || !obj->isTangible())
		return;

	TangibleObject* tano = (TangibleObject*)obj;

	if (!tano->isCraftingTool())
		return;

	CraftingTool* craftingTool = (CraftingTool*) tano;

	try {
		craftingTool->wlock();

		craftingTool->retriveHopperItem(player);

		craftingTool->unlock();
	} catch (...) {
		cout << "unreported exception caught in RadialManager::handleOpenCraftingToolHopper\n";
		craftingTool->unlock();
	}
}

void RadialManager::handleHarvest(Player* player, SceneObject* obj, int type) {
	if (obj == NULL)
		return;

	if (!obj->isNonPlayerCreature())
		return;

	Creature* creature = (Creature*)obj;

	ResourceManager* resourceManager = player->getZone()->getZoneServer()->getResourceManager();

	if (resourceManager == NULL)
		return;

	resourceManager->harvestOrganics(player, creature, type);
}

