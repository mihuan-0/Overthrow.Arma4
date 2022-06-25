[BaseContainerProps(configRoot:true)]
class OVT_FactionCompositionConfig
{
	[Attribute("", UIWidgets.Object)]
	ref array<ref OVT_FactionComposition> m_aCompositions;
}

[BaseContainerProps(), SCR_BaseContainerCustomTitleField("m_sTag")]
class OVT_FactionComposition
{
	[Attribute()]
	string m_sTag;
	
	[Attribute(defvalue:"5", desc:"Resource cost (multiplied by difficulty base resources)")]
	int m_iCost;
	
	[Attribute(uiwidget: UIWidgets.ResourceAssignArray, desc: "Prefabs", params: "et")]
	ref array<ResourceName> m_aPrefabs;
	
	[Attribute(uiwidget: UIWidgets.ResourceAssignArray, desc: "Groups", params: "et")]
	ref array<ResourceName> m_aGroupPrefabs;
}

class OVT_Faction : SCR_Faction
{
	[Attribute(uiwidget: UIWidgets.ResourceAssignArray, desc: "Faction groups (all)", params: "et", category: "Faction Groups")]
	ref array<ResourceName> m_aGroupPrefabSlots;
	
	[Attribute(uiwidget: UIWidgets.ResourceAssignArray, desc: "Faction groups (Light Infantry)", params: "et", category: "Faction Groups")]
	ref array<ResourceName> m_aGroupInfantryPrefabSlots;
	
	[Attribute(uiwidget: UIWidgets.ResourceAssignArray, desc: "Faction groups (Heavy Infantry)", params: "et", category: "Faction Groups")]
	ref array<ResourceName> m_aHeavyInfantryPrefabSlots;
	
	[Attribute(uiwidget: UIWidgets.ResourceAssignArray, desc: "Faction groups (AT)", params: "et", category: "Faction Groups")]
	ref array<ResourceName> m_aGroupATPrefabSlots;
	
	[Attribute(uiwidget: UIWidgets.ResourceAssignArray, desc: "Faction groups (Special Forces)", params: "et", category: "Faction Groups")]
	ref array<ResourceName> m_aGroupSpecialPrefabSlots;
	
	[Attribute(uiwidget: UIWidgets.ResourceNamePicker, desc: "Faction group (Sniper)", params: "et", category: "Faction Groups")]
	ResourceName m_aGroupSniperPrefab;
	
	[Attribute(uiwidget: UIWidgets.ResourceNamePicker, desc: "Faction group (Light Town Patrol)", params: "et", category: "Faction Groups")]
	ResourceName m_aLightTownPatrolPrefab;
	
	[Attribute(uiwidget: UIWidgets.ResourceAssignArray, desc: "Faction vehicles (all)", params: "et", category: "Faction Vehicles")]
	ref array<ResourceName> m_aVehiclePrefabSlots;
	
	[Attribute(uiwidget: UIWidgets.ResourceAssignArray, desc: "Faction vehicles (Cars)", params: "et", category: "Faction Vehicles")]
	ref array<ResourceName> m_aVehicleCarPrefabSlots;
	
	[Attribute(uiwidget: UIWidgets.ResourceAssignArray, desc: "Faction vehicles (Trucks)", params: "et", category: "Faction Vehicles")]
	ref array<ResourceName> m_aVehicleTruckPrefabSlots;
	
	[Attribute(uiwidget: UIWidgets.ResourceAssignArray, desc: "Faction vehicles (Lightly Armed)", params: "et", category: "Faction Vehicles")]
	ref array<ResourceName> m_aVehicleLightPrefabSlots;
	
	[Attribute(uiwidget: UIWidgets.ResourceAssignArray, desc: "Faction vehicles (Heavy Armed)", params: "et", category: "Faction Vehicles")]
	ref array<ResourceName> m_aVehicleHeavyPrefabSlots;
	
	[Attribute(uiwidget: UIWidgets.ResourceAssignArray, desc: "Faction gun tripods (Light)", params: "et", category: "Faction Vehicles")]
	ref array<ResourceName> m_aTripodLightPrefabSlots;
	
	[Attribute(uiwidget: UIWidgets.ResourceAssignArray, desc: "Faction gun tripods (Heavy)", params: "et", category: "Faction Vehicles")]
	ref array<ResourceName> m_aTripodHeavyPrefabSlots;
		
	[Attribute(uiwidget: UIWidgets.ResourceNamePicker, desc: "Flag Pole Prefab", params: "et", category: "Faction Objects")]
	ResourceName m_aFlagPolePrefab;
	
	[Attribute(uiwidget: UIWidgets.ResourceNamePicker, desc: "Medium Checkpoint Prefab", params: "et", category: "Faction Objects")]
	ResourceName m_aMediumCheckpointPrefab;
	
	[Attribute(uiwidget: UIWidgets.ResourceNamePicker, desc: "Large Checkpoint Prefab", params: "et", category: "Faction Objects")]
	ResourceName m_aLargeCheckpointPrefab;
	
	[Attribute()]
	ref OVT_FactionCompositionConfig m_aCompositionConfig;
	
	OVT_FactionComposition GetCompositionConfig(string tag)
	{
		if(!m_aCompositionConfig) return null;
		foreach(OVT_FactionComposition config :  m_aCompositionConfig.m_aCompositions)
		{
			if(config.m_sTag == tag) return config;
		}
		return null;
	}
}