death_watch_s_battle_droid_alt = Creature:new {
	objectName = "@mob/creature_names:mand_bunker_super_battle_droid",
	socialGroup = "death_watch",
	pvpFaction = "death_watch",
	faction = "",
	level = 200,
	chanceHit = 18,
	damageMin = 900,
	damageMax = 1900,
	baseXp = 15000,
	baseHAM = 100000,
	baseHAMmax = 110000,
	armor = 2,
	resists = {60,60,60,60,60,25,40,60,5},--kinetic,energy,blast,heat,cold,electric,acid,stun,ls
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ATTACKABLE,
	creatureBitmask = KILLER,
	optionsBitmask = 128,
	diet = NONE,

	templates = {
		"object/mobile/death_watch_s_battle_droid.iff",
		"object/mobile/death_watch_s_battle_droid_02.iff",
		"object/mobile/death_watch_s_battle_droid_03.iff"},
	lootGroups = {
		{
			groups = {
				{group = "death_watch_bunker_commoners", chance = 10000000}
			},
			lootChance = 500000
		},
		{
			groups = {
				{group = "clothing_attachments", chance = 5000000}
				{group = "clothing_attachments", chance = 5000000},
			},
			lootChance = 500000
		}
	},
	conversationTemplate = "",
	defaultWeapon = "object/weapon/ranged/droid/droid_droideka_ranged.iff",
	defaultAttack = "creaturerangedattack"
}

CreatureTemplates:addCreatureTemplate(death_watch_s_battle_droid_alt, "death_watch_s_battle_droid_alt")
