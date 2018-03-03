dark_jedi_knight = Creature:new {
	objectName = "@mob/creature_names:dark_jedi_knight",
	socialGroup = "Dark Jedi",
	pvpFaction = "",
	faction = "",
	level = 290,
	chanceHit = 135,
	damageMin = 1045,
	damageMax = 1500,
	baseXp = 25266,
	baseHAM = 261000,
	baseHAMmax = 320000,
	armor = 1,
	resists = {70,70,70,70,70,70,70,70,25},
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
	creatureBitmask = KILLER + STALKER,
	optionsBitmask = 128,
	diet = HERBIVORE,

	templates = {
		"object/mobile/dressed_dark_jedi_human_male_01.iff",
		"object/mobile/dressed_dark_jedi_human_female_01.iff"},
	lootGroups = {
		{
			groups = {
				{group = "clothing_attachments", chance = 5000000}
				{group = "clothing_attachments", chance = 5000000},
			},
			lootChance = 300000
		},
		{
			groups = {
				{group = "clothing_attachments", chance = 5000000}
				{group = "clothing_attachments", chance = 5000000},
			},
			lootChance = 300000
		},
		{
			groups = {
				{group = "axkva_min", chance = 10000000},
			},
			lootChance = 3000000
		},
		{
	       		groups = {
				{group = "krayt_tissue_rare", chance = 4000000},
				{group = "pearls_flawless", chance = 6000000}				
			},
			lootChance = 3000000
		},
	weapons = {"dark_jedi_weapons_gen3"},
	conversationTemplate = "",
	attacks = merge(lightsabermaster)
}

CreatureTemplates:addCreatureTemplate(dark_jedi_knight, "dark_jedi_knight")
