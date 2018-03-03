death_watch_battle_droid = Creature:new {
	objectName = "@mob/creature_names:mand_bunker_battle_droid",
	socialGroup = "death_watch",
	pvpFaction = "death_watch",
	faction = "",
	level = 150,
	chanceHit = 5.5,
	damageMin = 595,
	damageMax = 1000,
	baseXp = 11000,
	baseHAM = 34000,
	baseHAMmax = 38000,
	armor = 2,
	resists = {50,50,50,50,50,25,40,50,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ATTACKABLE + ENEMY,
	creatureBitmask = KILLER,
	optionsBitmask = 128,
	diet = HERBIVORE,

	templates = {
		"object/mobile/death_watch_battle_droid.iff",
		"object/mobile/death_watch_battle_droid_02.iff",
		"object/mobile/death_watch_battle_droid_03.iff"},
	lootGroups = {
		{
			groups = {
				{group = "death_watch_bunker_commoners", chance = 10000000}
			},
			lootChance = 1000000
		},
		{
			groups = {
				{group = "clothing_attachments", chance = 5000000}
				{group = "clothing_attachments", chance = 5000000},
			},
			lootChance = 500000
		}
	},
	weapons = {"battle_droid_weapons"},
	conversationTemplate = "",
	attacks = merge(riflemanmaster,pistoleermaster,carbineermaster,brawlermaster)
}

CreatureTemplates:addCreatureTemplate(death_watch_battle_droid, "death_watch_battle_droid")
