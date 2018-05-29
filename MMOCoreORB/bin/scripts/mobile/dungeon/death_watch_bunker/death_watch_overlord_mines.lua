death_watch_overlord = Creature:new {
	objectName = "",
	customName = "Drartih Oure (a Death Watch Overlord)",
	socialGroup = "death_watch",
	pvpFaction = "death_watch",
	faction = "",
	level = 330,
	chanceHit = 190,
	damageMin = 1700,
	damageMax = 2700,
	baseXp = 35000,
	baseHAM = 400000,
	baseHAMmax = 400000,
	armor = 3,
	resists = {60,70,70,65,35,25,60,10,5},--kinetic,energy,blast,heat,cold,electric,acid,stun,ls
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
	optionsBitmask = AIENABLED,
	diet = HERBIVORE,
	scale = 2.0,

	templates = {"object/mobile/dressed_death_watch_gold.iff"},
	lootGroups = {
		{
			groups = {
				{group = "death_watch_bunker_overlord_shared", chance =  10000000}
			},
			lootChance = 5000000
		},
		{
			groups = {
				{group = "death_watch_bunker_overlord_shared", chance =  500000},
				{group = "death_watch_bunker_overlord_quest", chance  = 9500000}
			},
			lootChance = 5000000
		},
		{
			groups = {
				{group = "clothing_attachments", chance = 5000000}
				{group = "clothing_attachments", chance = 5000000},
			},
			lootChance = 2000000
		},
		{
			groups = {
				{group = "clothing_attachments", chance = 5000000}
				{group = "armor_attachments", chance = 5000000},
			},
			lootChance = 2000000
		},
		{
			groups = {
				{group = "axkva_min", chance = 10000000},
			},
			lootChance = 2000000
		},
		{
	       		groups = {
				{group = "krayt_tissue_rare", chance = 4000000},
				{group = "pearls_flawless", chance = 6000000}				
			},
			lootChance = 2000000
		}
		},
	weapons = {"dark_trooper_weapons"},
	conversationTemplate = "",
	attacks = merge(riflemanmaster,pistoleermaster,carbineermaster,brawlermaster,fencermaster,marksmanmaster)
}

CreatureTemplates:addCreatureTemplate(death_watch_overlord, "death_watch_overlord")
