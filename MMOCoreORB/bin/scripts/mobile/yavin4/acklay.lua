acklay = Creature:new {
	objectName = "@mob/creature_names:",
	customName = "Acklay",
	socialGroup = "geonosian_creature",
	pvpFaction = "geonosian_creature",
	faction = "",
	level = 200,
	chanceHit = 92.5,
	damageMin = 1335,
	damageMax = 1980,
	baseXp = 17884,
	baseHAM = 126000,
	baseHAMmax = 168000,
	armor = 1,
	resists = {60,60,65,65,60,55,40,40,50},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 25,
	pvpBitmask = AGGRESSIVE + ATTACKABLE + ENEMY,
	creatureBitmask = PACK + KILLER,
	optionsBitmask = 128,
	diet = CARNIVORE,

	templates = {"object/mobile/acklay_hue.iff"},
	lootGroups = {
		{
			groups = {
				{group = "acklay", chance = 10000000}
			},
			lootChance = 7500000
		},
		{
			groups = {
				{group = "acklay", chance = 10000000}
			},
			lootChance = 7500000
		}
	},
	weapons = {},
	conversationTemplate = "",
	attacks = {
		{"creatureareacombo",""},
		{"posturedownattack","postureDownChance=50"}
	}
}

CreatureTemplates:addCreatureTemplate(acklay, "acklay")
