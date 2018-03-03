death_watch_mine_rat = Creature:new {
	objectName = "@mob/creature_names:death_watch_quenker",
	socialGroup = "death_watch",
	pvpFaction = "death_watch",
	faction = "",
	level = 130,
	chanceHit = 1,
	damageMin = 645,
	damageMax = 1000,
	baseXp = 9708,
	baseHAM = 25000,
	baseHAMmax = 25000,
	armor = 0,
	resists = {45,45,65,35,35,35,70,35,30},
	meatType = "meat_wild",
	meatAmount = 130,
	hideType = "hide_scaley",
	hideAmount = 130,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ATTACKABLE + ENEMY,
	creatureBitmask = PACK + KILLER,
	optionsBitmask = 128,
	diet = CARNIVORE,

	templates = {"object/mobile/womp_rat.iff"},
	lootGroups = {},
	weapons = {},
	conversationTemplate = "",
	attacks = {
		{"intimidationattack","intimidationChance=50"},
		{"knockdownattack","knockdownChance=50"}
	}
}

CreatureTemplates:addCreatureTemplate(death_watch_mine_rat, "death_watch_mine_rat")
