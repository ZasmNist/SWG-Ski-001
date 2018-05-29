death_watch_mine_rat = Creature:new {
	objectName = "@mob/creature_names:death_watch_quenker",
	socialGroup = "death_watch",
	faction = "",
	level = 102,
	chanceHit = 1,
	damageMin = 645,
	damageMax = 1000,
	baseXp = 9708,
	baseHAM = 24000,
	baseHAMmax = 30000,
	armor = 1,
	resists = {55,55,50,35,35,35,10,15,15},
	meatType = "meat_wild",
	meatAmount = 200,
	hideType = "hide_scaley",
	hideAmount = 200,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ATTACKABLE + ENEMY,
	creatureBitmask = PACK + KILLER,
	optionsBitmask = AIENABLED,
	diet = CARNIVORE,

	templates = {"object/mobile/womp_rat.iff"},
	lootGroups = {},
	weapons = {},
	conversationTemplate = "",
	attacks = {
		{"intimidationattack",""},
		{"knockdownattack",""}
	}
}

CreatureTemplates:addCreatureTemplate(death_watch_mine_rat, "death_watch_mine_rat")
