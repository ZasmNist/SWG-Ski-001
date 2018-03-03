death_watch_wraith = Creature:new {
	objectName = "@mob/creature_names:mand_bunker_dthwatch_silver",
	socialGroup = "death_watch",
	pvpFaction = "death_watch",
	faction = "",
	level = 200,
	chanceHit = 85,
	damageMin = 1095,
	damageMax = 1400,
	baseXp = 13000,
	baseHAM = 145000,
	baseHAMmax = 150000,
	armor = 1,
	resists = {50,50,50,50,35,35,50,50,25},
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

	templates = {"object/mobile/dressed_death_watch_silver.iff"},
	lootGroups = {
		{
			groups = {
				{group = "death_watch_bunker_commoners",   chance = 6300000},
				{group = "death_watch_bunker_lieutenants", chance = 3500000},
				{group = "death_watch_bunker_ingredient_protective",  chance = 100000},
				{group = "death_watch_bunker_ingredient_binary",  chance = 100000}
			},
			lootChance = 2500000
		},
		{
			groups = {
				{group = "clothing_attachments", chance = 5000000}
				{group = "clothing_attachments", chance = 5000000},
			},
			lootChance = 500000
		}
	},
	weapons = {"pirate_weapons_heavy"},
	conversationTemplate = "",
	attacks = {
		{"defaultattack", ""},
		{"intimidationattack","intimidationChance=50"},
		{"knockdownattack","knockdownChance=50"}
	}
}

CreatureTemplates:addCreatureTemplate(death_watch_wraith, "death_watch_wraith")
