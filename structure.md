D:\.
|   .gitignore
|   CHANGES.md
|   CMakeLists.txt
|   README.md
|   stlport.diff
|
+---build
|   `---(build artifacts - CMake/MSBuild generated files)
+---build_test
|   `---(CMake build artifacts)
+---Generals
|   +---Code
|   |   +---GameEngine
|   |   |   +---Include
|   |   |   |   +---Common
|   |   |   |   |   +---SafeDisk
|   |   |   |   |   |   `---.gitignore
|   |   |   |   |   +---ActionManager.h
|   |   |   |   |   +---ArchiveFile.h
|   |   |   |   |   +---ArchiveFileSystem.h
|   |   |   |   |   +---AsciiString.h
|   |   |   |   |   +---AudioAffect.h
|   |   |   |   |   +---AudioEventInfo.h
|   |   |   |   |   +---AudioEventRTS.h
|   |   |   |   |   +---AudioHandleSpecialValues.h
|   |   |   |   |   +---AudioRandomValue.h
|   |   |   |   |   +---AudioRequest.h
|   |   |   |   |   +---AudioSettings.h
|   |   |   |   |   +---BattleHonors.h
|   |   |   |   |   +---BezFwdIterator.h
|   |   |   |   |   +---BezierSegment.h
|   |   |   |   |   +---BitFlags.h
|   |   |   |   |   +---BitFlagsIO.h
|   |   |   |   |   +---BorderColors.h
|   |   |   |   |   +---BuildAssistant.h
|   |   |   |   |   +---CDManager.h
|   |   |   |   |   +---ClientUpdateModule.h
|   |   |   |   |   +---CommandLine.h
|   |   |   |   |   +---CopyProtection.h
|   |   |   |   |   +---crc.h
|   |   |   |   |   +---CRCDebug.h
|   |   |   |   |   +---CriticalSection.h
|   |   |   |   |   +---CustomMatchPreferences.h
|   |   |   |   |   +---DamageFX.h
|   |   |   |   |   +---DataChunk.h
|   |   |   |   |   +---Debug.h
|   |   |   |   |   +---Dict.h
|   |   |   |   |   +---Directory.h
|   |   |   |   |   +---DisabledTypes.h
|   |   |   |   |   +---DiscreteCircle.h
|   |   |   |   |   +---DrawModule.h
|   |   |   |   |   +---encrypt.h
|   |   |   |   |   +---Energy.h
|   |   |   |   |   +---Errors.h
|   |   |   |   |   +---file.h
|   |   |   |   |   +---FileSystem.h
|   |   |   |   |   +---FunctionLexicon.h
|   |   |   |   |   +---GameAudio.h
|   |   |   |   |   +---GameCommon.h
|   |   |   |   |   +---GameEngine.h
|   |   |   |   |   +---GameLOD.h
|   |   |   |   |   +---GameMemory.h
|   |   |   |   |   +---GameMusic.h
|   |   |   |   |   +---GameSounds.h
|   |   |   |   |   +---GameSpeech.h
|   |   |   |   |   +---GameSpyMiscPreferences.h
|   |   |   |   |   +---GameState.h
|   |   |   |   |   +---GameStateMap.h
|   |   |   |   |   +---GameType.h
|   |   |   |   |   +---Geometry.h
|   |   |   |   |   +---GlobalData.h
|   |   |   |   |   +---Handicap.h
|   |   |   |   |   +---IgnorePreferences.h
|   |   |   |   |   +---INI.h
|   |   |   |   |   +---INIException.h
|   |   |   |   |   +---KindOf.h
|   |   |   |   |   +---LadderPreferences.h
|   |   |   |   |   +---Language.h
|   |   |   |   |   +---LatchRestore.h
|   |   |   |   |   +---List.h
|   |   |   |   |   +---LocalFile.h
|   |   |   |   |   +---LocalFileSystem.h
|   |   |   |   |   +---MapObject.h
|   |   |   |   |   +---MapReaderWriterInfo.h
|   |   |   |   |   +---MessageStream.h
|   |   |   |   |   +---MiniLog.h
|   |   |   |   |   +---MiscAudio.h
|   |   |   |   |   +---MissionStats.h
|   |   |   |   |   +---ModelState.h
|   |   |   |   |   +---Module.h
|   |   |   |   |   +---ModuleFactory.h
|   |   |   |   |   +---Money.h
|   |   |   |   |   +---MultiplayerSettings.h
|   |   |   |   |   +---NameKeyGenerator.h
|   |   |   |   |   +---OSDisplay.h
|   |   |   |   |   +---Overridable.h
|   |   |   |   |   +---Override.h
|   |   |   |   |   +---PartitionSolver.h
|   |   |   |   |   +---PerfMetrics.h
|   |   |   |   |   +---PerfTimer.h
|   |   |   |   |   +---Player.h
|   |   |   |   |   +---PlayerList.h
|   |   |   |   |   +---PlayerTemplate.h
|   |   |   |   |   +---ProductionPrerequisite.h
|   |   |   |   |   +---QuickmatchPreferences.h
|   |   |   |   |   +---QuickTrig.h
|   |   |   |   |   +---QuotedPrintable.h
|   |   |   |   |   +---Radar.h
|   |   |   |   |   +---RAMFile.h
|   |   |   |   |   +---RandomValue.h
|   |   |   |   |   +---Recorder.h
|   |   |   |   |   +---Registry.h
|   |   |   |   |   +---ResourceGatheringManager.h
|   |   |   |   |   +---Science.h
|   |   |   |   |   +---ScopedMutex.h
|   |   |   |   |   +---ScoreKeeper.h
|   |   |   |   |   +---simpleplayer.h
|   |   |   |   |   +---SkirmishBattleHonors.h
|   |   |   |   |   +---SkirmishPreferences.h
|   |   |   |   |   +---Snapshot.h
|   |   |   |   |   +---SparseMatchFinder.h
|   |   |   |   |   +---SpecialPower.h
|   |   |   |   |   +---SpecialPowerMaskType.h
|   |   |   |   |   +---SpecialPowerType.h
|   |   |   |   |   +---StackDump.h
|   |   |   |   |   +---StateMachine.h
|   |   |   |   |   +---StatsCollector.h
|   |   |   |   |   +---STLTypedefs.h
|   |   |   |   |   +---StreamingArchiveFile.h
|   |   |   |   |   +---string.h
|   |   |   |   |   +---SubsystemInterface.h
|   |   |   |   |   +---SystemInfo.h
|   |   |   |   |   +---Team.h
|   |   |   |   |   +---Terrain.h
|   |   |   |   |   +---TerrainTypes.h
|   |   |   |   |   +---Thing.h
|   |   |   |   |   +---ThingFactory.h
|   |   |   |   |   +---ThingSort.h
|   |   |   |   |   +---ThingTemplate.h
|   |   |   |   |   +---TunnelTracker.h
|   |   |   |   |   +---UnicodeString.h
|   |   |   |   |   +---UnitTimings.h
|   |   |   |   |   +---Upgrade.h
|   |   |   |   |   +---urllaunch.h
|   |   |   |   |   +---UserPreferences.h
|   |   |   |   |   +---version.h
|   |   |   |   |   +---WellKnownKeys.h
|   |   |   |   |   +---Xfer.h
|   |   |   |   |   +---XferCRC.h
|   |   |   |   |   +---XferDeepCRC.h
|   |   |   |   |   +---XferLoad.h
|   |   |   |   |   `---XferSave.h
|   |   |   |   +---GameClient
|   |   |   |   |   +---Module
|   |   |   |   |   |   +---AnimatedParticleSysBoneClientUpdate.h
|   |   |   |   |   |   +---BeaconClientUpdate.h
|   |   |   |   |   |   `---SwayClientUpdate.h
|   |   |   |   |   +---Anim2D.h
|   |   |   |   |   +---AnimateWindowManager.h
|   |   |   |   |   +---CampaignManager.h
|   |   |   |   |   +---CDCheck.h
|   |   |   |   |   +---ClientRandomValue.h
|   |   |   |   |   +---Color.h
|   |   |   |   |   +---CommandXlat.h
|   |   |   |   |   +---ControlBar.h
|   |   |   |   |   +---ControlBarResizer.h
|   |   |   |   |   +---ControlBarScheme.h
|   |   |   |   |   +---Credits.h
|   |   |   |   |   +---DebugDisplay.h
|   |   |   |   |   +---Diplomacy.h
|   |   |   |   |   +---DisconnectMenu.h
|   |   |   |   |   +---Display.h
|   |   |   |   |   +---DisplayString.h
|   |   |   |   |   +---DisplayStringManager.h
|   |   |   |   |   +---Drawable.h
|   |   |   |   |   +---DrawableInfo.h
|   |   |   |   |   +---DrawableManager.h
|   |   |   |   |   +---DrawGroupInfo.h
|   |   |   |   |   +---EstablishConnectionsMenu.h
|   |   |   |   |   +---Eva.h
|   |   |   |   |   +---ExtendedMessageBox.h
|   |   |   |   |   +---FontDesc.h
|   |   |   |   |   +---FXList.h
|   |   |   |   |   +---Gadget.h
|   |   |   |   |   +---GadgetCheckBox.h
|   |   |   |   |   +---GadgetComboBox.h
|   |   |   |   |   +---GadgetListBox.h
|   |   |   |   |   +---GadgetProgressBar.h
|   |   |   |   |   +---GadgetPushButton.h
|   |   |   |   |   +---GadgetRadioButton.h
|   |   |   |   |   +---GadgetSlider.h
|   |   |   |   |   +---GadgetStaticText.h
|   |   |   |   |   +---GadgetTabControl.h
|   |   |   |   |   +---GadgetTextEntry.h
|   |   |   |   |   +---GameClient.h
|   |   |   |   |   +---GameFont.h
|   |   |   |   |   +---GameInfoWindow.h
|   |   |   |   |   +---GameText.h
|   |   |   |   |   +---GameWindow.h
|   |   |   |   |   +---GameWindowGlobal.h
|   |   |   |   |   +---GameWindowID.h
|   |   |   |   |   +---GameWindowManager.h
|   |   |   |   |   +---GameWindowTransitions.h
|   |   |   |   |   +---GlobalLanguage.h
|   |   |   |   |   +---GraphDraw.h
|   |   |   |   |   +---GUICallbacks.h
|   |   |   |   |   +---GUICommandTranslator.h
|   |   |   |   |   +---HeaderTemplate.h
|   |   |   |   |   +---HintSpy.h
|   |   |   |   |   +---HotKey.h
|   |   |   |   |   +---Image.h
|   |   |   |   |   +---IMEManager.h
|   |   |   |   |   +---InGameUI.h
|   |   |   |   |   +---Keyboard.h
|   |   |   |   |   +---KeyDefs.h
|   |   |   |   |   +---LanguageFilter.h
|   |   |   |   |   +---Line2D.h
|   |   |   |   |   +---LoadScreen.h
|   |   |   |   |   +---LookAtXlat.h
|   |   |   |   |   +---MapUtil.h
|   |   |   |   |   +---MessageBox.h
|   |   |   |   |   +---MetaEvent.h
|   |   |   |   |   +---Mouse.h
|   |   |   |   |   +---ParticleSys.h
|   |   |   |   |   +---PlaceEventTranslator.h
|   |   |   |   |   +---ProcessAnimateWindow.h
|   |   |   |   |   +---RadiusDecal.h
|   |   |   |   |   +---RayEffect.h
|   |   |   |   |   +---SelectionInfo.h
|   |   |   |   |   +---SelectionXlat.h
|   |   |   |   |   +---Shadow.h
|   |   |   |   |   +---Shell.h
|   |   |   |   |   +---ShellHooks.h
|   |   |   |   |   +---ShellMenuScheme.h
|   |   |   |   |   +---Statistics.h
|   |   |   |   |   +---TerrainRoads.h
|   |   |   |   |   +---TerrainVisual.h
|   |   |   |   |   +---VideoPlayer.h
|   |   |   |   |   +---View.h
|   |   |   |   |   +---Water.h
|   |   |   |   |   +---WindowLayout.h
|   |   |   |   |   +---WindowVideoManager.h
|   |   |   |   |   +---WindowXlat.h
|   |   |   |   |   `---WinInstanceData.h
|   |   |   |   +---GameLogic
|   |   |   |   |   +---Module
|   |   |   |   |   |   +---ActiveBody.h
|   |   |   |   |   |   +---ActiveShroudUpgrade.h
|   |   |   |   |   |   +---AIUpdate.h
|   |   |   |   |   |   +---ArmorUpgrade.h
|   |   |   |   |   |   +---AssaultTransportAIUpdate.h
|   |   |   |   |   |   +---AssistedTargetingUpdate.h
|   |   |   |   |   |   +---AutoDepositUpdate.h
|   |   |   |   |   |   +---AutoFindHealingUpdate.h
|   |   |   |   |   |   +---AutoHealBehavior.h
|   |   |   |   |   |   +---BaikonurLaunchPower.h
|   |   |   |   |   |   +---BaseRegenerateUpdate.h
|   |   |   |   |   |   +---BattlePlanUpdate.h
|   |   |   |   |   |   +---BehaviorModule.h
|   |   |   |   |   |   +---BodyModule.h
|   |   |   |   |   |   +---BoneFXDamage.h
|   |   |   |   |   |   +---BoneFXUpdate.h
|   |   |   |   |   |   +---BridgeBehavior.h
|   |   |   |   |   |   +---BridgeScaffoldBehavior.h
|   |   |   |   |   |   +---BridgeTowerBehavior.h
|   |   |   |   |   |   +---CashBountyPower.h
|   |   |   |   |   |   +---CashHackSpecialPower.h
|   |   |   |   |   |   +---CaveContain.h
|   |   |   |   |   |   +---CheckpointUpdate.h
|   |   |   |   |   |   +---ChinookAIUpdate.h
|   |   |   |   |   |   +---CleanupAreaPower.h
|   |   |   |   |   |   +---CleanupHazardUpdate.h
|   |   |   |   |   |   +---CollideModule.h
|   |   |   |   |   |   +---CommandButtonHuntUpdate.h
|   |   |   |   |   |   +---CommandSetUpgrade.h
|   |   |   |   |   |   +---ContainModule.h
|   |   |   |   |   |   +---ConvertToCarBombCrateCollide.h
|   |   |   |   |   |   +---ConvertToHijackedVehicleCrateCollide.h
|   |   |   |   |   |   +---CostModifierUpgrade.h
|   |   |   |   |   |   +---CrateCollide.h
|   |   |   |   |   |   +---CreateCrateDie.h
|   |   |   |   |   |   +---CreateModule.h
|   |   |   |   |   |   +---CreateObjectDie.h
|   |   |   |   |   |   +---CrushDie.h
|   |   |   |   |   |   +---DamageModule.h
|   |   |   |   |   |   +---DamDie.h
|   |   |   |   |   |   +---DefaultProductionExitUpdate.h
|   |   |   |   |   |   +---DefectorSpecialPower.h
|   |   |   |   |   |   +---DelayedUpgrade.h
|   |   |   |   |   |   +---DelayedWeaponSetUpgradeUpdate.h
|   |   |   |   |   |   +---DeletionUpdate.h
|   |   |   |   |   |   +---DeliverPayloadAIUpdate.h
|   |   |   |   |   |   +---DemoralizeSpecialPower.h
|   |   |   |   |   |   +---DemoTrapUpdate.h
|   |   |   |   |   |   +---DeployStyleAIUpdate.h
|   |   |   |   |   |   +---DestroyDie.h
|   |   |   |   |   |   +---DestroyModule.h
|   |   |   |   |   |   +---DieModule.h
|   |   |   |   |   |   +---DockUpdate.h
|   |   |   |   |   |   +---DozerAIUpdate.h
|   |   |   |   |   |   +---DumbProjectileBehavior.h
|   |   |   |   |   |   +---DynamicGeometryInfoUpdate.h
|   |   |   |   |   |   +---DynamicShroudClearingRangeUpdate.h
|   |   |   |   |   |   +---EjectPilotDie.h
|   |   |   |   |   |   +---EMPUpdate.h
|   |   |   |   |   |   +---EnemyNearUpdate.h
|   |   |   |   |   |   +---ExperienceScalarUpgrade.h
|   |   |   |   |   |   +---FireOCLAfterWeaponCooldownUpdate.h
|   |   |   |   |   |   +---FireSpreadUpdate.h
|   |   |   |   |   |   +---FirestormDynamicGeometryInfoUpdate.h
|   |   |   |   |   |   +---FireWeaponCollide.h
|   |   |   |   |   |   +---FireWeaponUpdate.h
|   |   |   |   |   |   +---FireWeaponWhenDamagedBehavior.h
|   |   |   |   |   |   +---FireWeaponWhenDeadBehavior.h
|   |   |   |   |   |   +---FlammableUpdate.h
|   |   |   |   |   |   +---FloatUpdate.h
|   |   |   |   |   |   +---FXListDie.h
|   |   |   |   |   |   +---GarrisonContain.h
|   |   |   |   |   |   +---GenerateMinefieldBehavior.h
|   |   |   |   |   |   +---GrantUpgradeCreate.h
|   |   |   |   |   |   +---HackInternetAIUpdate.h
|   |   |   |   |   |   +---HealContain.h
|   |   |   |   |   |   +---HealCrateCollide.h
|   |   |   |   |   |   +---HeightDieUpdate.h
|   |   |   |   |   |   +---HelicopterSlowDeathUpdate.h
|   |   |   |   |   |   +---HighlanderBody.h
|   |   |   |   |   |   +---HijackerUpdate.h
|   |   |   |   |   |   +---HiveStructureBody.h
|   |   |   |   |   |   +---HordeUpdate.h
|   |   |   |   |   |   +---ImmortalBody.h
|   |   |   |   |   |   +---InactiveBody.h
|   |   |   |   |   |   +---InstantDeathBehavior.h
|   |   |   |   |   |   +---JetAIUpdate.h
|   |   |   |   |   |   +---JetSlowDeathBehavior.h
|   |   |   |   |   |   +---KeepObjectDie.h
|   |   |   |   |   |   +---LaserUpdate.h
|   |   |   |   |   |   +---LifetimeUpdate.h
|   |   |   |   |   |   +---LocomotorSetUpgrade.h
|   |   |   |   |   |   +---MaxHealthUpgrade.h
|   |   |   |   |   |   +---MinefieldBehavior.h
|   |   |   |   |   |   +---MissileAIUpdate.h
|   |   |   |   |   |   +---MissileLauncherBuildingUpdate.h
|   |   |   |   |   |   +---MobMemberSlavedUpdate.h
|   |   |   |   |   |   +---MobNexusContain.h
|   |   |   |   |   |   +---MoneyCrateCollide.h
|   |   |   |   |   |   +---NeutronMissileSlowDeathUpdate.h
|   |   |   |   |   |   +---NeutronMissileUpdate.h
|   |   |   |   |   |   +---ObjectCreationUpgrade.h
|   |   |   |   |   |   +---ObjectDefectionHelper.h
|   |   |   |   |   |   +---ObjectHelper.h
|   |   |   |   |   |   +---ObjectRepulsorHelper.h
|   |   |   |   |   |   +---ObjectSMCHelper.h
|   |   |   |   |   |   +---ObjectWeaponStatusHelper.h
|   |   |   |   |   |   +---OCLSpecialPower.h
|   |   |   |   |   |   +---OCLUpdate.h
|   |   |   |   |   |   +---OpenContain.h
|   |   |   |   |   |   +---OverchargeBehavior.h
|   |   |   |   |   |   +---OverlordContain.h
|   |   |   |   |   |   +---ParachuteContain.h
|   |   |   |   |   |   +---ParkingPlaceBehavior.h
|   |   |   |   |   |   +---ParticleUplinkCannonUpdate.h
|   |   |   |   |   |   +---PhysicsUpdate.h
|   |   |   |   |   |   +---PilotFindVehicleUpdate.h
|   |   |   |   |   |   +---PointDefenseLaserUpdate.h
|   |   |   |   |   |   +---PoisonedBehavior.h
|   |   |   |   |   |   +---PowerPlantUpdate.h
|   |   |   |   |   |   +---PowerPlantUpgrade.h
|   |   |   |   |   |   +---POWTruckAIUpdate.h
|   |   |   |   |   |   +---POWTruckBehavior.h
|   |   |   |   |   |   +---PreorderCreate.h
|   |   |   |   |   |   +---PrisonBehavior.h
|   |   |   |   |   |   +---PrisonDockUpdate.h
|   |   |   |   |   |   +---ProductionUpdate.h
|   |   |   |   |   |   +---ProjectileStreamUpdate.h
|   |   |   |   |   |   +---ProneUpdate.h
|   |   |   |   |   |   +---PropagandaCenterBehavior.h
|   |   |   |   |   |   +---PropagandaTowerBehavior.h
|   |   |   |   |   |   +---QueueProductionExitUpdate.h
|   |   |   |   |   |   +---RadarUpdate.h
|   |   |   |   |   |   +---RadarUpgrade.h
|   |   |   |   |   |   +---RadiusDecalUpdate.h
|   |   |   |   |   |   +---RailedTransportAIUpdate.h
|   |   |   |   |   |   +---RailedTransportContain.h
|   |   |   |   |   |   +---RailedTransportDockUpdate.h
|   |   |   |   |   |   +---RailroadGuideAIUpdate.h
|   |   |   |   |   |   +---RebuildHoleBehavior.h
|   |   |   |   |   |   +---RebuildHoleExposeDie.h
|   |   |   |   |   |   +---RepairDockUpdate.h
|   |   |   |   |   |   +---SalvageCrateCollide.h
|   |   |   |   |   |   +---ShroudCrateCollide.h
|   |   |   |   |   |   +---SlavedUpdate.h
|   |   |   |   |   |   +---SlowDeathBehavior.h
|   |   |   |   |   |   +---SpawnBehavior.h
|   |   |   |   |   |   +---SpawnPointProductionExitUpdate.h
|   |   |   |   |   |   +---SpecialAbility.h
|   |   |   |   |   |   +---SpecialAbilityUpdate.h
|   |   |   |   |   |   +---SpecialPowerCompletionDie.h
|   |   |   |   |   |   +---SpecialPowerCreate.h
|   |   |   |   |   |   +---SpecialPowerModule.h
|   |   |   |   |   |   +---SpyVisionSpecialPower.h
|   |   |   |   |   |   +---SpyVisionUpdate.h
|   |   |   |   |   |   +---SquishCollide.h
|   |   |   |   |   |   +---StatusBitsUpgrade.h
|   |   |   |   |   |   +---StealthDetectorUpdate.h
|   |   |   |   |   |   +---StealthUpdate.h
|   |   |   |   |   |   +---StealthUpgrade.h
|   |   |   |   |   |   +---StickyBombUpdate.h
|   |   |   |   |   |   +---StructureBody.h
|   |   |   |   |   |   +---StructureCollapseUpdate.h
|   |   |   |   |   |   +---StructureToppleUpdate.h
|   |   |   |   |   |   +---SubObjectsUpgrade.h
|   |   |   |   |   |   +---SupplyCenterCreate.h
|   |   |   |   |   |   +---SupplyCenterDockUpdate.h
|   |   |   |   |   |   +---SupplyCenterProductionExitUpdate.h
|   |   |   |   |   |   +---SupplyTruckAIUpdate.h
|   |   |   |   |   |   +---SupplyWarehouseCreate.h
|   |   |   |   |   |   +---SupplyWarehouseCripplingBehavior.h
|   |   |   |   |   |   +---SupplyWarehouseDockUpdate.h
|   |   |   |   |   |   +---TechBuildingBehavior.h
|   |   |   |   |   |   +---TensileFormationUpdate.h
|   |   |   |   |   |   +---ToppleUpdate.h
|   |   |   |   |   |   +---TransitionDamageFX.h
|   |   |   |   |   |   +---TransportAIUpdate.h
|   |   |   |   |   |   +---TransportContain.h
|   |   |   |   |   |   +---TunnelContain.h
|   |   |   |   |   |   +---UnitCrateCollide.h
|   |   |   |   |   |   +---UnpauseSpecialPowerUpgrade.h
|   |   |   |   |   |   +---UpdateModule.h
|   |   |   |   |   |   +---UpgradeDie.h
|   |   |   |   |   |   +---UpgradeModule.h
|   |   |   |   |   |   +---VeterancyCrateCollide.h
|   |   |   |   |   |   +---VeterancyGainCreate.h
|   |   |   |   |   |   +---WanderAIUpdate.h
|   |   |   |   |   |   +---WaveGuideUpdate.h
|   |   |   |   |   |   +---WeaponBonusUpgrade.h
|   |   |   |   |   |   +---WeaponSetUpgrade.h
|   |   |   |   |   |   `---WorkerAIUpdate.h
|   |   |   |   |   +---AI.h
|   |   |   |   |   +---AIDock.h
|   |   |   |   |   +---AIGuard.h
|   |   |   |   |   +---AIPathfind.h
|   |   |   |   |   +---AIPlayer.h
|   |   |   |   |   +---AISkirmishPlayer.h
|   |   |   |   |   +---AIStateMachine.h
|   |   |   |   |   +---AITNGuard.h
|   |   |   |   |   +---Armor.h
|   |   |   |   |   +---ArmorSet.h
|   |   |   |   |   +---CaveSystem.h
|   |   |   |   |   +---CrateSystem.h
|   |   |   |   |   +---Damage.h
|   |   |   |   |   +---ExperienceTracker.h
|   |   |   |   |   +---FiringTracker.h
|   |   |   |   |   +---FPUControl.h
|   |   |   |   |   +---GameLogic.h
|   |   |   |   |   +---GhostObject.h
|   |   |   |   |   +---Locomotor.h
|   |   |   |   |   +---LocomotorSet.h
|   |   |   |   |   +---LogicRandomValue.h
|   |   |   |   |   +---Object.h
|   |   |   |   |   +---ObjectCreationList.h
|   |   |   |   |   +---ObjectIter.h
|   |   |   |   |   +---ObjectScriptStatusBits.h
|   |   |   |   |   +---ObjectStatusBits.h
|   |   |   |   |   +---ObjectTypes.h
|   |   |   |   |   +---PartitionManager.h
|   |   |   |   |   +---PolygonTrigger.h
|   |   |   |   |   +---Powers.h
|   |   |   |   |   +---RankInfo.h
|   |   |   |   |   +---ScriptActions.h
|   |   |   |   |   +---ScriptConditions.h
|   |   |   |   |   +---ScriptEngine.h
|   |   |   |   |   +---Scripts.h
|   |   |   |   |   +---SidesList.h
|   |   |   |   |   +---Squad.h
|   |   |   |   |   +---TerrainLogic.h
|   |   |   |   |   +---TurretAI.h
|   |   |   |   |   +---VictoryConditions.h
|   |   |   |   |   +---Weapon.h
|   |   |   |   |   +---WeaponBonusConditionFlags.h
|   |   |   |   |   +---WeaponSet.h
|   |   |   |   |   +---WeaponSetFlags.h
|   |   |   |   |   +---WeaponSetType.h
|   |   |   |   |   `---WeaponStatus.h
|   |   |   |   +---GameNetwork
|   |   |   |   |   +---GameSpy
|   |   |   |   |   |   +---BuddyDefs.h
|   |   |   |   |   |   +---BuddyThread.h
|   |   |   |   |   |   +---GameResultsThread.h
|   |   |   |   |   |   +---GSConfig.h
|   |   |   |   |   |   +---LadderDefs.h
|   |   |   |   |   |   +---LobbyUtils.h
|   |   |   |   |   |   +---MainMenuUtils.h
|   |   |   |   |   |   +---PeerDefs.h
|   |   |   |   |   |   +---PeerDefsImplementation.h
|   |   |   |   |   |   +---PeerThread.h
|   |   |   |   |   |   +---PersistentStorageDefs.h
|   |   |   |   |   |   +---PersistentStorageThread.h
|   |   |   |   |   |   +---PingThread.h
|   |   |   |   |   |   +---StagingRoomGameInfo.h
|   |   |   |   |   |   `---ThreadUtils.h
|   |   |   |   |   +---WOLBrowser
|   |   |   |   |   |   +---FEBDispatch.h
|   |   |   |   |   |   `---WebBrowser.h
|   |   |   |   |   +---Connection.h
|   |   |   |   |   +---ConnectionManager.h
|   |   |   |   |   +---DisconnectManager.h
|   |   |   |   |   +---DownloadManager.h
|   |   |   |   |   +---FileTransfer.h
|   |   |   |   |   +---FirewallHelper.h
|   |   |   |   |   +---FrameData.h
|   |   |   |   |   +---FrameDataManager.h
|   |   |   |   |   +---FrameMetrics.h
|   |   |   |   |   +---GameInfo.h
|   |   |   |   |   +---GameMessageParser.h
|   |   |   |   |   +---GameSpy.h
|   |   |   |   |   +---GameSpyChat.h
|   |   |   |   |   +---GameSpyGameInfo.h
|   |   |   |   |   +---GameSpyGP.h
|   |   |   |   |   +---GameSpyOverlay.h
|   |   |   |   |   +---GameSpyPersistentStorage.h
|   |   |   |   |   +---GameSpyThread.h
|   |   |   |   |   +---GUIUtil.h
|   |   |   |   |   +---IPEnumeration.h
|   |   |   |   |   +---LANAPI.h
|   |   |   |   |   +---LANAPICallbacks.h
|   |   |   |   |   +---LANGameInfo.h
|   |   |   |   |   +---LANPlayer.h
|   |   |   |   |   +---NAT.h
|   |   |   |   |   +---NetCommandList.h
|   |   |   |   |   +---NetCommandMsg.h
|   |   |   |   |   +---NetCommandRef.h
|   |   |   |   |   +---NetCommandWrapperList.h
|   |   |   |   |   +---NetPacket.h
|   |   |   |   |   +---NetworkDefs.h
|   |   |   |   |   +---NetworkInterface.h
|   |   |   |   |   +---networkutil.h
|   |   |   |   |   +---RankPointValue.h
|   |   |   |   |   +---Transport.h
|   |   |   |   |   +---udp.h
|   |   |   |   |   `---User.h
|   |   |   |   `---Precompiled
|   |   |   |       `---PreRTS.h
|   |   |   +---Source
|   |   |   |   +---Common
|   |   |   |   |   +---Audio
|   |   |   |   |   |   +---AudioEventRTS.cpp
|   |   |   |   |   |   +---AudioRequest.cpp
|   |   |   |   |   |   +---GameAudio.cpp
|   |   |   |   |   |   +---GameMusic.cpp
|   |   |   |   |   |   +---GameSounds.cpp
|   |   |   |   |   |   +---GameSpeech.cpp
|   |   |   |   |   |   +---simpleplayer.cpp
|   |   |   |   |   |   `---urllaunch.cpp
|   |   |   |   |   +---Bezier
|   |   |   |   |   |   +---BezFwdIterator.cpp
|   |   |   |   |   |   `---BezierSegment.cpp
|   |   |   |   |   +---INI
|   |   |   |   |   |   +---INI.cpp
|   |   |   |   |   |   +---INIAiData.cpp
|   |   |   |   |   |   +---INIAnimation.cpp
|   |   |   |   |   |   +---INIAudioEventInfo.cpp
|   |   |   |   |   |   +---INICommandButton.cpp
|   |   |   |   |   |   +---INICommandSet.cpp
|   |   |   |   |   |   +---INIControlBarScheme.cpp
|   |   |   |   |   |   +---INICrate.cpp
|   |   |   |   |   |   +---INIDamageFX.cpp
|   |   |   |   |   |   +---INIDrawGroupInfo.cpp
|   |   |   |   |   |   +---INIGameData.cpp
|   |   |   |   |   |   +---INIMapCache.cpp
|   |   |   |   |   |   +---INIMapData.cpp
|   |   |   |   |   |   +---INIMappedImage.cpp
|   |   |   |   |   |   +---INIMiscAudio.cpp
|   |   |   |   |   |   +---INIModel.cpp
|   |   |   |   |   |   +---INIMultiplayer.cpp
|   |   |   |   |   |   +---INIObject.cpp
|   |   |   |   |   |   +---INIParticleSys.cpp
|   |   |   |   |   |   +---INISpecialPower.cpp
|   |   |   |   |   |   +---INITerrain.cpp
|   |   |   |   |   |   +---INITerrainBridge.cpp
|   |   |   |   |   |   +---INITerrainRoad.cpp
|   |   |   |   |   |   +---INIUpgrade.cpp
|   |   |   |   |   |   +---INIVideo.cpp
|   |   |   |   |   |   +---INIWater.cpp
|   |   |   |   |   |   +---INIWeapon.cpp
|   |   |   |   |   |   `---INIWebpageURL.cpp
|   |   |   |   |   +---RTS
|   |   |   |   |   |   +---ActionManager.cpp
|   |   |   |   |   |   +---Energy.cpp
|   |   |   |   |   |   +---Handicap.cpp
|   |   |   |   |   |   +---MissionStats.cpp
|   |   |   |   |   |   +---Money.cpp
|   |   |   |   |   |   +---Player.cpp
|   |   |   |   |   |   +---PlayerList.cpp
|   |   |   |   |   |   +---PlayerTemplate.cpp
|   |   |   |   |   |   +---ProductionPrerequisite.cpp
|   |   |   |   |   |   +---ResourceGatheringManager.cpp
|   |   |   |   |   |   +---Science.cpp
|   |   |   |   |   |   +---ScoreKeeper.cpp
|   |   |   |   |   |   +---SpecialPower.cpp
|   |   |   |   |   |   +---Team.cpp
|   |   |   |   |   |   `---TunnelTracker.cpp
|   |   |   |   |   +---System
|   |   |   |   |   |   +---SaveGame
|   |   |   |   |   |   |   +---GameState.cpp
|   |   |   |   |   |   |   `---GameStateMap.cpp
|   |   |   |   |   |   +---ArchiveFile.cpp
|   |   |   |   |   |   +---ArchiveFileSystem.cpp
|   |   |   |   |   |   +---AsciiString.cpp
|   |   |   |   |   |   +---BuildAssistant.cpp
|   |   |   |   |   |   +---CDManager.cpp
|   |   |   |   |   |   +---Compression.cpp
|   |   |   |   |   |   +---CopyProtection.cpp
|   |   |   |   |   |   +---CriticalSection.cpp
|   |   |   |   |   |   +---DataChunk.cpp
|   |   |   |   |   |   +---Debug.cpp
|   |   |   |   |   |   +---Directory.cpp
|   |   |   |   |   |   +---DisabledTypes.cpp
|   |   |   |   |   |   +---encrypt.cpp
|   |   |   |   |   |   +---File.cpp
|   |   |   |   |   |   +---FileSystem.cpp
|   |   |   |   |   |   +---FunctionLexicon.cpp
|   |   |   |   |   |   +---GameCommon.cpp
|   |   |   |   |   |   +---GameMemory.cpp
|   |   |   |   |   |   +---GameType.cpp
|   |   |   |   |   |   +---Geometry.cpp
|   |   |   |   |   |   +---KindOf.cpp
|   |   |   |   |   |   +---List.cpp
|   |   |   |   |   |   +---LocalFile.cpp
|   |   |   |   |   |   +---LocalFileSystem.cpp
|   |   |   |   |   |   +---MemoryInit.cpp
|   |   |   |   |   |   +---QuickTrig.cpp
|   |   |   |   |   |   +---QuotedPrintable.cpp
|   |   |   |   |   |   +---Radar.cpp
|   |   |   |   |   |   +---RAMFile.cpp
|   |   |   |   |   |   +---registry.cpp
|   |   |   |   |   |   +---Snapshot.cpp
|   |   |   |   |   |   +---StackDump.cpp
|   |   |   |   |   |   +---StreamingArchiveFile.cpp
|   |   |   |   |   |   +---String.cpp
|   |   |   |   |   |   +---SubsystemInterface.cpp
|   |   |   |   |   |   +---Trig.cpp
|   |   |   |   |   |   +---UnicodeString.cpp
|   |   |   |   |   |   +---Upgrade.cpp
|   |   |   |   |   |   +---Xfer.cpp
|   |   |   |   |   |   +---XferCRC.cpp
|   |   |   |   |   |   +---XferLoad.cpp
|   |   |   |   |   |   `---XferSave.cpp
|   |   |   |   |   +---Thing
|   |   |   |   |   |   +---DrawModule.cpp
|   |   |   |   |   |   +---Module.cpp
|   |   |   |   |   |   +---ModuleFactory.cpp
|   |   |   |   |   |   +---Thing.cpp
|   |   |   |   |   |   +---ThingFactory.cpp
|   |   |   |   |   |   `---ThingTemplate.cpp
|   |   |   |   |   +---BitFlags.cpp
|   |   |   |   |   +---CommandLine.cpp
|   |   |   |   |   +---crc.cpp
|   |   |   |   |   +---CRCDebug.cpp
|   |   |   |   |   +---DamageFX.cpp
|   |   |   |   |   +---Dict.cpp
|   |   |   |   |   +---DiscreteCircle.cpp
|   |   |   |   |   +---GameEngine.cpp
|   |   |   |   |   +---GameLOD.cpp
|   |   |   |   |   +---GameMain.cpp
|   |   |   |   |   +---GlobalData.cpp
|   |   |   |   |   +---Language.cpp
|   |   |   |   |   +---MessageStream.cpp
|   |   |   |   |   +---MiniLog.cpp
|   |   |   |   |   +---MultiplayerSettings.cpp
|   |   |   |   |   +---NameKeyGenerator.cpp
|   |   |   |   |   +---PartitionSolver.cpp
|   |   |   |   |   +---PerfTimer.cpp
|   |   |   |   |   +---RandomValue.cpp
|   |   |   |   |   +---Recorder.cpp
|   |   |   |   |   +---SkirmishBattleHonors.cpp
|   |   |   |   |   +---StateMachine.cpp
|   |   |   |   |   +---StatsCollector.cpp
|   |   |   |   |   +---TerrainTypes.cpp
|   |   |   |   |   +---UserPreferences.cpp
|   |   |   |   |   `---version.cpp
|   |   |   |   +---GameClient
|   |   |   |   |   +---Drawable
|   |   |   |   |   |   +---Update
|   |   |   |   |   |   |   +---AnimatedParticleSysBoneClientUpdate.cpp
|   |   |   |   |   |   |   +---BeaconClientUpdate.cpp
|   |   |   |   |   |   |   `---SwayClientUpdate.cpp
|   |   |   |   |   |   `---DrawableManager.cpp
|   |   |   |   |   +---GUI
|   |   |   |   |   |   +---ControlBar
|   |   |   |   |   |   |   +---ControlBar.cpp
|   |   |   |   |   |   |   +---ControlBarBeacon.cpp
|   |   |   |   |   |   |   +---ControlBarCommand.cpp
|   |   |   |   |   |   |   +---ControlBarCommandProcessing.cpp
|   |   |   |   |   |   |   +---ControlBarMultiSelect.cpp
|   |   |   |   |   |   |   +---ControlBarObserver.cpp
|   |   |   |   |   |   |   +---ControlBarOCLTimer.cpp
|   |   |   |   |   |   |   +---ControlBarPrintPositions.cpp
|   |   |   |   |   |   |   +---ControlBarResizer.cpp
|   |   |   |   |   |   |   +---ControlBarScheme.cpp
|   |   |   |   |   |   |   +---ControlBarStructureInventory.cpp
|   |   |   |   |   |   |   `---ControlBarUnderConstruction.cpp
|   |   |   |   |   |   +---DisconnectMenu
|   |   |   |   |   |   |   `---DisconnectMenu.cpp
|   |   |   |   |   |   +---EstablishConnectionsMenu
|   |   |   |   |   |   |   `---EstablishConnectionsMenu.cpp
|   |   |   |   |   |   +---Gadget
|   |   |   |   |   |   |   +---GadgetCheckBox.cpp
|   |   |   |   |   |   |   +---GadgetComboBox.cpp
|   |   |   |   |   |   |   +---GadgetHorizontalSlider.cpp
|   |   |   |   |   |   |   +---GadgetListBox.cpp
|   |   |   |   |   |   |   +---GadgetProgressBar.cpp
|   |   |   |   |   |   |   +---GadgetPushButton.cpp
|   |   |   |   |   |   |   +---GadgetRadioButton.cpp
|   |   |   |   |   |   |   +---GadgetStaticText.cpp
|   |   |   |   |   |   |   +---GadgetTabControl.cpp
|   |   |   |   |   |   |   +---GadgetTextEntry.cpp
|   |   |   |   |   |   |   `---GadgetVerticalSlider.cpp
|   |   |   |   |   |   +---GUICallbacks
|   |   |   |   |   |   |   +---Menus
|   |   |   |   |   |   |   |   +---CreditsMenu.cpp
|   |   |   |   |   |   |   |   +---DifficultySelect.cpp
|   |   |   |   |   |   |   |   +---DisconnectWindow.cpp
|   |   |   |   |   |   |   |   +---DownloadMenu.cpp
|   |   |   |   |   |   |   |   +---EstablishConnectionsWindow.cpp
|   |   |   |   |   |   |   |   +---GameInfoWindow.cpp
|   |   |   |   |   |   |   |   +---KeyboardOptionsMenu.cpp
|   |   |   |   |   |   |   |   +---LanGameOptionsMenu.cpp
|   |   |   |   |   |   |   |   +---LanLobbyMenu.cpp
|   |   |   |   |   |   |   |   +---LanMapSelectMenu.cpp
|   |   |   |   |   |   |   |   +---MainMenu.cpp
|   |   |   |   |   |   |   |   +---MapSelectMenu.cpp
|   |   |   |   |   |   |   |   +---NetworkDirectConnect.cpp
|   |   |   |   |   |   |   |   +---OptionsMenu.cpp
|   |   |   |   |   |   |   |   +---PopupCommunicator.cpp
|   |   |   |   |   |   |   |   +---PopupHostGame.cpp
|   |   |   |   |   |   |   |   +---PopupJoinGame.cpp
|   |   |   |   |   |   |   |   +---PopupLadderSelect.cpp
|   |   |   |   |   |   |   |   +---PopupPlayerInfo.cpp
|   |   |   |   |   |   |   |   +---PopupReplay.cpp
|   |   |   |   |   |   |   |   +---PopupSaveLoad.cpp
|   |   |   |   |   |   |   |   +---QuitMenu.cpp
|   |   |   |   |   |   |   |   +---ReplayMenu.cpp
|   |   |   |   |   |   |   |   +---ScoreScreen.cpp
|   |   |   |   |   |   |   |   +---SinglePlayerMenu.cpp
|   |   |   |   |   |   |   |   +---SkirmishGameOptionsMenu.cpp
|   |   |   |   |   |   |   |   +---SkirmishMapSelectMenu.cpp
|   |   |   |   |   |   |   |   +---WOLBuddyOverlay.cpp
|   |   |   |   |   |   |   |   +---WOLCustomScoreScreen.cpp
|   |   |   |   |   |   |   |   +---WOLGameSetupMenu.cpp
|   |   |   |   |   |   |   |   +---WOLLadderScreen.cpp
|   |   |   |   |   |   |   |   +---WOLLobbyMenu.cpp
|   |   |   |   |   |   |   |   +---WOLLocaleSelectPopup.cpp
|   |   |   |   |   |   |   |   +---WOLLoginMenu.cpp
|   |   |   |   |   |   |   |   +---WOLMapSelectMenu.cpp
|   |   |   |   |   |   |   |   +---WOLMessageWindow.cpp
|   |   |   |   |   |   |   |   +---WOLQMScoreScreen.cpp
|   |   |   |   |   |   |   |   +---WOLQuickMatchMenu.cpp
|   |   |   |   |   |   |   |   +---WOLStatusMenu.cpp
|   |   |   |   |   |   |   |   `---WOLWelcomeMenu.cpp
|   |   |   |   |   |   |   +---ControlBarCallback.cpp
|   |   |   |   |   |   |   +---ControlBarPopupDescription.cpp
|   |   |   |   |   |   |   +---Diplomacy.cpp
|   |   |   |   |   |   |   +---ExtendedMessageBox.cpp
|   |   |   |   |   |   |   +---GeneralsExpPoints.cpp
|   |   |   |   |   |   |   +---IMECandidate.cpp
|   |   |   |   |   |   |   +---InGameChat.cpp
|   |   |   |   |   |   |   +---InGamePopupMessage.cpp
|   |   |   |   |   |   |   +---MessageBox.cpp
|   |   |   |   |   |   |   `---ReplayControls.cpp
|   |   |   |   |   |   +---Shell
|   |   |   |   |   |   |   +---Shell.cpp
|   |   |   |   |   |   |   `---ShellMenuScheme.cpp
|   |   |   |   |   |   +---AnimateWindowManager.cpp
|   |   |   |   |   |   +---GameFont.cpp
|   |   |   |   |   |   +---GameWindow.cpp
|   |   |   |   |   |   +---GameWindowGlobal.cpp
|   |   |   |   |   |   +---GameWindowManager.cpp
|   |   |   |   |   |   +---GameWindowManagerScript.cpp
|   |   |   |   |   |   +---GameWindowTransitions.cpp
|   |   |   |   |   |   +---GameWindowTransitionsStyles.cpp
|   |   |   |   |   |   +---HeaderTemplate.cpp
|   |   |   |   |   |   +---IMEManager.cpp
|   |   |   |   |   |   +---LoadScreen.cpp
|   |   |   |   |   |   +---ProcessAnimateWindow.cpp
|   |   |   |   |   |   +---WindowLayout.cpp
|   |   |   |   |   |   +---WindowVideoManager.cpp
|   |   |   |   |   |   `---WinInstanceData.cpp
|   |   |   |   |   +---Input
|   |   |   |   |   |   +---Keyboard.cpp
|   |   |   |   |   |   `---Mouse.cpp
|   |   |   |   |   +---MessageStream
|   |   |   |   |   |   +---CommandXlat.cpp
|   |   |   |   |   |   +---GUICommandTranslator.cpp
|   |   |   |   |   |   +---HintSpy.cpp
|   |   |   |   |   |   +---HotKey.cpp
|   |   |   |   |   |   +---LookAtXlat.cpp
|   |   |   |   |   |   +---MetaEvent.cpp
|   |   |   |   |   |   +---PlaceEventTranslator.cpp
|   |   |   |   |   |   +---SelectionXlat.cpp
|   |   |   |   |   |   `---WindowXlat.cpp
|   |   |   |   |   +---System
|   |   |   |   |   |   +---Debug Displayers
|   |   |   |   |   |   |   `---AudioDebugDisplay.cpp
|   |   |   |   |   |   +---Anim2D.cpp
|   |   |   |   |   |   +---CampaignManager.cpp
|   |   |   |   |   |   +---DebugDisplay.cpp
|   |   |   |   |   |   +---Image.cpp
|   |   |   |   |   |   +---ParticleSys.cpp
|   |   |   |   |   |   `---RayEffect.cpp
|   |   |   |   |   +---Terrain
|   |   |   |   |   |   +---TerrainRoads.cpp
|   |   |   |   |   |   `---TerrainVisual.cpp
|   |   |   |   |   +---Color.cpp
|   |   |   |   |   +---Credits.cpp
|   |   |   |   |   +---Display.cpp
|   |   |   |   |   +---DisplayString.cpp
|   |   |   |   |   +---DisplayStringManager.cpp
|   |   |   |   |   +---Drawable.cpp
|   |   |   |   |   +---DrawableManager.cpp
|   |   |   |   |   +---DrawGroupInfo.cpp
|   |   |   |   |   +---Eva.cpp
|   |   |   |   |   +---FXList.cpp
|   |   |   |   |   +---GameClient.cpp
|   |   |   |   |   +---GameClientDispatch.cpp
|   |   |   |   |   +---GameText.cpp
|   |   |   |   |   +---GlobalLanguage.cpp
|   |   |   |   |   +---GraphDraw.cpp
|   |   |   |   |   +---InGameUI.cpp
|   |   |   |   |   +---LanguageFilter.cpp
|   |   |   |   |   +---Line2D.cpp
|   |   |   |   |   +---MapUtil.cpp
|   |   |   |   |   +---RadiusDecal.cpp
|   |   |   |   |   +---SelectionInfo.cpp
|   |   |   |   |   +---Statistics.cpp
|   |   |   |   |   +---VideoPlayer.cpp
|   |   |   |   |   +---VideoStream.cpp
|   |   |   |   |   +---View.cpp
|   |   |   |   |   `---Water.cpp
|   |   |   |   +---GameLogic
|   |   |   |   |   +---AI
|   |   |   |   |   |   +---AI.cpp
|   |   |   |   |   |   +---AIDock.cpp
|   |   |   |   |   |   +---AIGroup.cpp
|   |   |   |   |   |   +---AIGuard.cpp
|   |   |   |   |   |   +---AIPathfind.cpp
|   |   |   |   |   |   +---AIPlayer.cpp
|   |   |   |   |   |   +---AISkirmishPlayer.cpp
|   |   |   |   |   |   +---AIStates.cpp
|   |   |   |   |   |   +---AITNGuard.cpp
|   |   |   |   |   |   +---Squad.cpp
|   |   |   |   |   |   `---TurretAI.cpp
|   |   |   |   |   +---Map
|   |   |   |   |   |   +---PolygonTrigger.cpp
|   |   |   |   |   |   +---SidesList.cpp
|   |   |   |   |   |   `---TerrainLogic.cpp
|   |   |   |   |   +---Object
|   |   |   |   |   |   +---Behavior
|   |   |   |   |   |   |   +---AutoHealBehavior.cpp
|   |   |   |   |   |   |   +---BehaviorModule.cpp
|   |   |   |   |   |   |   +---BridgeBehavior.cpp
|   |   |   |   |   |   |   +---BridgeScaffoldBehavior.cpp
|   |   |   |   |   |   |   +---BridgeTowerBehavior.cpp
|   |   |   |   |   |   |   +---DumbProjectileBehavior.cpp
|   |   |   |   |   |   |   +---FireWeaponWhenDamagedBehavior.cpp
|   |   |   |   |   |   |   +---FireWeaponWhenDeadBehavior.cpp
|   |   |   |   |   |   |   +---GenerateMinefieldBehavior.cpp
|   |   |   |   |   |   |   +---InstantDeathBehavior.cpp
|   |   |   |   |   |   |   +---JetSlowDeathBehavior.cpp
|   |   |   |   |   |   |   +---MinefieldBehavior.cpp
|   |   |   |   |   |   |   +---OverchargeBehavior.cpp
|   |   |   |   |   |   |   +---ParkingPlaceBehavior.cpp
|   |   |   |   |   |   |   +---PoisonedBehavior.cpp
|   |   |   |   |   |   |   +---POWTruckBehavior.cpp
|   |   |   |   |   |   |   +---PrisonBehavior.cpp
|   |   |   |   |   |   |   +---PropagandaCenterBehavior.cpp
|   |   |   |   |   |   |   +---PropagandaTowerBehavior.cpp
|   |   |   |   |   |   |   +---RebuildHoleBehavior.cpp
|   |   |   |   |   |   |   +---SlowDeathBehavior.cpp
|   |   |   |   |   |   |   +---SpawnBehavior.cpp
|   |   |   |   |   |   |   +---SupplyWarehouseCripplingBehavior.cpp
|   |   |   |   |   |   |   `---TechBuildingBehavior.cpp
|   |   |   |   |   |   +---Body
|   |   |   |   |   |   |   +---ActiveBody.cpp
|   |   |   |   |   |   |   +---BodyModule.cpp
|   |   |   |   |   |   |   +---HighlanderBody.cpp
|   |   |   |   |   |   |   +---HiveStructureBody.cpp
|   |   |   |   |   |   |   +---ImmortalBody.cpp
|   |   |   |   |   |   |   +---InactiveBody.cpp
|   |   |   |   |   |   |   `---StructureBody.cpp
|   |   |   |   |   |   +---Collide
|   |   |   |   |   |   |   +---CrateCollide
|   |   |   |   |   |   |   |   +---ConvertToCarBombCrateCollide.cpp
|   |   |   |   |   |   |   |   +---ConvertToHijackedVehicleCrateCollide.cpp
|   |   |   |   |   |   |   |   +---CrateCollide.cpp
|   |   |   |   |   |   |   |   +---HealCrateCollide.cpp
|   |   |   |   |   |   |   |   +---MoneyCrateCollide.cpp
|   |   |   |   |   |   |   |   +---SalvageCrateCollide.cpp
|   |   |   |   |   |   |   |   +---ShroudCrateCollide.cpp
|   |   |   |   |   |   |   |   +---UnitCrateCollide.cpp
|   |   |   |   |   |   |   |   `---VeterancyCrateCollide.cpp
|   |   |   |   |   |   |   +---CollideModule.cpp
|   |   |   |   |   |   |   +---FireWeaponCollide.cpp
|   |   |   |   |   |   |   `---SquishCollide.cpp
|   |   |   |   |   |   +---Contain
|   |   |   |   |   |   |   +---CaveContain.cpp
|   |   |   |   |   |   |   +---GarrisonContain.cpp
|   |   |   |   |   |   |   +---HealContain.cpp
|   |   |   |   |   |   |   +---MobNexusContain.cpp
|   |   |   |   |   |   |   +---OpenContain.cpp
|   |   |   |   |   |   |   +---OverlordContain.cpp
|   |   |   |   |   |   |   +---ParachuteContain.cpp
|   |   |   |   |   |   |   +---RailedTransportContain.cpp
|   |   |   |   |   |   |   +---TransportContain.cpp
|   |   |   |   |   |   |   `---TunnelContain.cpp
|   |   |   |   |   |   +---Create
|   |   |   |   |   |   |   +---CreateModule.cpp
|   |   |   |   |   |   |   +---GrantUpgradeCreate.cpp
|   |   |   |   |   |   |   +---PreorderCreate.cpp
|   |   |   |   |   |   |   +---SpecialPowerCreate.cpp
|   |   |   |   |   |   |   +---SupplyCenterCreate.cpp
|   |   |   |   |   |   |   +---SupplyWarehouseCreate.cpp
|   |   |   |   |   |   |   `---VeterancyGainCreate.cpp
|   |   |   |   |   |   +---Damage
|   |   |   |   |   |   |   +---BoneFXDamage.cpp
|   |   |   |   |   |   |   +---DamageModule.cpp
|   |   |   |   |   |   |   `---TransitionDamageFX.cpp
|   |   |   |   |   |   +---Destroy
|   |   |   |   |   |   |   `---DestroyModule.cpp
|   |   |   |   |   |   +---Die
|   |   |   |   |   |   |   +---CreateCrateDie.cpp
|   |   |   |   |   |   |   +---CreateObjectDie.cpp
|   |   |   |   |   |   |   +---CrushDie.cpp
|   |   |   |   |   |   |   +---DamDie.cpp
|   |   |   |   |   |   |   +---DestroyDie.cpp
|   |   |   |   |   |   |   +---DieModule.cpp
|   |   |   |   |   |   |   +---EjectPilotDie.cpp
|   |   |   |   |   |   |   +---FXListDie.cpp
|   |   |   |   |   |   |   +---KeepObjectDie.cpp
|   |   |   |   |   |   |   +---RebuildHoleExposeDie.cpp
|   |   |   |   |   |   |   +---SpecialPowerCompletionDie.cpp
|   |   |   |   |   |   |   `---UpgradeDie.cpp
|   |   |   |   |   |   +---Helper
|   |   |   |   |   |   |   +---ObjectDefectionHelper.cpp
|   |   |   |   |   |   |   +---ObjectHelper.cpp
|   |   |   |   |   |   |   +---ObjectRepulsorHelper.cpp
|   |   |   |   |   |   |   +---ObjectSMCHelper.cpp
|   |   |   |   |   |   |   `---ObjectWeaponStatusHelper.cpp
|   |   |   |   |   |   +---SpecialPower
|   |   |   |   |   |   |   +---BaikonurLaunchPower.cpp
|   |   |   |   |   |   |   +---CashBountyPower.cpp
|   |   |   |   |   |   |   +---CashHackSpecialPower.cpp
|   |   |   |   |   |   |   +---CleanupAreaPower.cpp
|   |   |   |   |   |   |   +---DefectorSpecialPower.cpp
|   |   |   |   |   |   |   +---DemoralizeSpecialPower.cpp
|   |   |   |   |   |   |   +---OCLSpecialPower.cpp
|   |   |   |   |   |   |   +---SpecialAbility.cpp
|   |   |   |   |   |   |   +---SpecialPowerModule.cpp
|   |   |   |   |   |   |   `---SpyVisionSpecialPower.cpp
|   |   |   |   |   |   +---Update
|   |   |   |   |   |   |   +---AIUpdate
|   |   |   |   |   |   |   |   +---AssaultTransportAIUpdate.cpp
|   |   |   |   |   |   |   |   +---ChinookAIUpdate.cpp
|   |   |   |   |   |   |   |   +---DeliverPayloadAIUpdate.cpp
|   |   |   |   |   |   |   |   +---DeployStyleAIUpdate.cpp
|   |   |   |   |   |   |   |   +---DozerAIUpdate.cpp
|   |   |   |   |   |   |   |   +---HackInternetAIUpdate.cpp
|   |   |   |   |   |   |   |   +---JetAIUpdate.cpp
|   |   |   |   |   |   |   |   +---MissileAIUpdate.cpp
|   |   |   |   |   |   |   |   +---POWTruckAIUpdate.cpp
|   |   |   |   |   |   |   |   +---RailedTransportAIUpdate.cpp
|   |   |   |   |   |   |   |   +---RailroadGuideAIUpdate.cpp
|   |   |   |   |   |   |   |   +---SupplyTruckAIUpdate.cpp
|   |   |   |   |   |   |   |   +---TransportAIUpdate.cpp
|   |   |   |   |   |   |   |   +---WanderAIUpdate.cpp
|   |   |   |   |   |   |   |   `---WorkerAIUpdate.cpp
|   |   |   |   |   |   |   +---DockUpdate
|   |   |   |   |   |   |   |   +---DockUpdate.cpp
|   |   |   |   |   |   |   |   +---PrisonDockUpdate.cpp
|   |   |   |   |   |   |   |   +---RailedTransportDockUpdate.cpp
|   |   |   |   |   |   |   |   +---RepairDockUpdate.cpp
|   |   |   |   |   |   |   |   +---SupplyCenterDockUpdate.cpp
|   |   |   |   |   |   |   |   `---SupplyWarehouseDockUpdate.cpp
|   |   |   |   |   |   |   +---ProductionExitUpdate
|   |   |   |   |   |   |   |   +---DefaultProductionExitUpdate.cpp
|   |   |   |   |   |   |   |   +---QueueProductionExitUpdate.cpp
|   |   |   |   |   |   |   |   +---SpawnPointProductionExitUpdate.cpp
|   |   |   |   |   |   |   |   `---SupplyCenterProductionExitUpdate.cpp
|   |   |   |   |   |   |   +---AIUpdate.cpp
|   |   |   |   |   |   |   +---AssistedTargetingUpdate.cpp
|   |   |   |   |   |   |   +---AutoDepositUpdate.cpp
|   |   |   |   |   |   |   +---AutoFindHealingUpdate.cpp
|   |   |   |   |   |   |   +---BaseRenerateUpdate.cpp
|   |   |   |   |   |   |   +---BattlePlanUpdate.cpp
|   |   |   |   |   |   |   +---BoneFXUpdate.cpp
|   |   |   |   |   |   |   +---CheckpointUpdate.cpp
|   |   |   |   |   |   |   +---CleanupHazardUpdate.cpp
|   |   |   |   |   |   |   +---CommandButtonHuntUpdate.cpp
|   |   |   |   |   |   |   +---DelayedWeaponSetUpgradeUpdate.cpp
|   |   |   |   |   |   |   +---DeletionUpdate.cpp
|   |   |   |   |   |   |   +---DemoTrapUpdate.cpp
|   |   |   |   |   |   |   +---DynamicGeometryInfoUpdate.cpp
|   |   |   |   |   |   |   +---DynamicShroudClearingRangeUpdate.cpp
|   |   |   |   |   |   |   +---EMPUpdate.cpp
|   |   |   |   |   |   |   +---EnemyNearUpdate.cpp
|   |   |   |   |   |   |   +---FireOCLAfterWeaponCooldownUpdate.cpp
|   |   |   |   |   |   |   +---FireSpreadUpdate.cpp
|   |   |   |   |   |   |   +---FirestormDynamicGeometryInfoUpdate.cpp
|   |   |   |   |   |   |   +---FireWeaponUpdate.cpp
|   |   |   |   |   |   |   +---FlammableUpdate.cpp
|   |   |   |   |   |   |   +---FloatUpdate.cpp
|   |   |   |   |   |   |   +---HeightDieUpdate.cpp
|   |   |   |   |   |   |   +---HelicopterSlowDeathUpdate.cpp
|   |   |   |   |   |   |   +---HijackerUpdate.cpp
|   |   |   |   |   |   |   +---HordeUpdate.cpp
|   |   |   |   |   |   |   +---LaserUpdate.cpp
|   |   |   |   |   |   |   +---LifetimeUpdate.cpp
|   |   |   |   |   |   |   +---MissileLauncherBuildingUpdate.cpp
|   |   |   |   |   |   |   +---MobMemberSlavedUpdate.cpp
|   |   |   |   |   |   |   +---NeutronMissileSlowDeathUpdate.cpp
|   |   |   |   |   |   |   +---NeutronMissileUpdate.cpp
|   |   |   |   |   |   |   +---OCLUpdate.cpp
|   |   |   |   |   |   |   +---ParticleUplinkCannonUpdate.cpp
|   |   |   |   |   |   |   +---PhysicsUpdate.cpp
|   |   |   |   |   |   |   +---PilotFindVehicleUpdate.cpp
|   |   |   |   |   |   |   +---PointDefenseLaserUpdate.cpp
|   |   |   |   |   |   |   +---PowerPlantUpdate.cpp
|   |   |   |   |   |   |   +---ProductionUpdate.cpp
|   |   |   |   |   |   |   +---ProjectileStreamUpdate.cpp
|   |   |   |   |   |   |   +---ProneUpdate.cpp
|   |   |   |   |   |   |   +---RadarUpdate.cpp
|   |   |   |   |   |   |   +---RadiusDecalUpdate.cpp
|   |   |   |   |   |   |   +---SlavedUpdate.cpp
|   |   |   |   |   |   |   +---SpecialAbilityUpdate.cpp
|   |   |   |   |   |   |   +---SpyVisionUpdate.cpp
|   |   |   |   |   |   |   +---StealthDetectorUpdate.cpp
|   |   |   |   |   |   |   +---StealthUpdate.cpp
|   |   |   |   |   |   |   +---StickyBombUpdate.cpp
|   |   |   |   |   |   |   +---StructureCollapseUpdate.cpp
|   |   |   |   |   |   |   +---StructureToppleUpdate.cpp
|   |   |   |   |   |   |   +---TensileFormationUpdate.cpp
|   |   |   |   |   |   |   +---ToppleUpdate.cpp
|   |   |   |   |   |   |   +---UpdateModule.cpp
|   |   |   |   |   |   |   `---WaveGuideUpdate.cpp
|   |   |   |   |   |   +---Upgrade
|   |   |   |   |   |   |   +---ActiveShroudUpgrade.cpp
|   |   |   |   |   |   |   +---ArmorUpgrade.cpp
|   |   |   |   |   |   |   +---CommandSetUpgrade.cpp
|   |   |   |   |   |   |   +---CostModifierUpgrade.cpp
|   |   |   |   |   |   |   +---DelayedUpgrade.cpp
|   |   |   |   |   |   |   +---ExperienceScalarUpgrade.cpp
|   |   |   |   |   |   |   +---LocomotorSetUpgrade.cpp
|   |   |   |   |   |   |   +---MaxHealthUpgrade.cpp
|   |   |   |   |   |   |   +---ObjectCreationUpgrade.cpp
|   |   |   |   |   |   |   +---PowerPlantUpgrade.cpp
|   |   |   |   |   |   |   +---RadarUpgrade.cpp
|   |   |   |   |   |   |   +---StatusBitsUpgrade.cpp
|   |   |   |   |   |   |   +---StealthUpgrade.cpp
|   |   |   |   |   |   |   +---SubObjectsUpgrade.cpp
|   |   |   |   |   |   |   +---UnpauseSpecialPowerUpgrade.cpp
|   |   |   |   |   |   |   +---UpgradeModule.cpp
|   |   |   |   |   |   |   +---WeaponBonusUpgrade.cpp
|   |   |   |   |   |   |   `---WeaponSetUpgrade.cpp
|   |   |   |   |   |   +---Armor.cpp
|   |   |   |   |   |   +---ExperienceTracker.cpp
|   |   |   |   |   |   +---FiringTracker.cpp
|   |   |   |   |   |   +---GhostObject.cpp
|   |   |   |   |   |   +---Locomotor.cpp
|   |   |   |   |   |   +---Object.cpp
|   |   |   |   |   |   +---ObjectCreationList.cpp
|   |   |   |   |   |   +---ObjectTypes.cpp
|   |   |   |   |   |   +---PartitionManager.cpp
|   |   |   |   |   |   +---SimpleObjectIterator.cpp
|   |   |   |   |   |   +---Weapon.cpp
|   |   |   |   |   |   `---WeaponSet.cpp
|   |   |   |   |   +---ScriptEngine
|   |   |   |   |   |   +---ScriptActions.cpp
|   |   |   |   |   |   +---ScriptConditions.cpp
|   |   |   |   |   |   +---ScriptEngine.cpp
|   |   |   |   |   |   +---Scripts.cpp
|   |   |   |   |   |   `---VictoryConditions.cpp
|   |   |   |   |   `---System
|   |   |   |   |       +---CaveSystem.cpp
|   |   |   |   |       +---CrateSystem.cpp
|   |   |   |   |       +---Damage.cpp
|   |   |   |   |       +---GameLogic.cpp
|   |   |   |   |       +---GameLogicDispatch.cpp
|   |   |   |   |       `---RankInfo.cpp
|   |   |   |   +---GameNetwork
|   |   |   |   |   +---GameSpy
|   |   |   |   |   |   +---Thread
|   |   |   |   |   |   |   +---BuddyThread.cpp
|   |   |   |   |   |   |   +---GameResultsThread.cpp
|   |   |   |   |   |   |   +---PeerThread.cpp
|   |   |   |   |   |   |   +---PersistentStorageThread.cpp
|   |   |   |   |   |   |   +---PingThread.cpp
|   |   |   |   |   |   |   `---ThreadUtils.cpp
|   |   |   |   |   |   +---Chat.cpp
|   |   |   |   |   |   +---GSConfig.cpp
|   |   |   |   |   |   +---LadderDefs.cpp
|   |   |   |   |   |   +---LobbyUtils.cpp
|   |   |   |   |   |   +---MainMenuUtils.cpp
|   |   |   |   |   |   +---PeerDefs.cpp
|   |   |   |   |   |   `---StagingRoomGameInfo.cpp
|   |   |   |   |   +---WOLBrowser
|   |   |   |   |   |   `---WebBrowser.cpp
|   |   |   |   |   +---Connection.cpp
|   |   |   |   |   +---ConnectionManager.cpp
|   |   |   |   |   +---DisconnectManager.cpp
|   |   |   |   |   +---DownloadManager.cpp
|   |   |   |   |   +---FileTransfer.cpp
|   |   |   |   |   +---FirewallHelper.cpp
|   |   |   |   |   +---FrameData.cpp
|   |   |   |   |   +---FrameDataManager.cpp
|   |   |   |   |   +---FrameMetrics.cpp
|   |   |   |   |   +---GameInfo.cpp
|   |   |   |   |   +---GameMessageParser.cpp
|   |   |   |   |   +---GameSpy.cpp
|   |   |   |   |   +---GameSpyChat.cpp
|   |   |   |   |   +---GameSpyGameInfo.cpp
|   |   |   |   |   +---GameSpyGP.cpp
|   |   |   |   |   +---GameSpyOverlay.cpp
|   |   |   |   |   +---GameSpyPersistentStorage.cpp
|   |   |   |   |   +---GUIUtil.cpp
|   |   |   |   |   +---IPEnumeration.cpp
|   |   |   |   |   +---LANAPI.cpp
|   |   |   |   |   +---LANAPICallbacks.cpp
|   |   |   |   |   +---LANAPIhandlers.cpp
|   |   |   |   |   +---LANGameInfo.cpp
|   |   |   |   |   +---NAT.cpp
|   |   |   |   |   +---NetCommandList.cpp
|   |   |   |   |   +---NetCommandMsg.cpp
|   |   |   |   |   +---NetCommandRef.cpp
|   |   |   |   |   +---NetCommandWrapperList.cpp
|   |   |   |   |   +---NetMessageStream.cpp
|   |   |   |   |   +---NetPacket.cpp
|   |   |   |   |   +---Network.cpp
|   |   |   |   |   +---NetworkUtil.cpp
|   |   |   |   |   +---Transport.cpp
|   |   |   |   |   +---udp.cpp
|   |   |   |   |   `---User.cpp
|   |   |   |   `---Precompiled
|   |   |   |       `---PreRTS.cpp
|   |   |   `---GameEngine.dsp
|   |   +---GameEngineDevice
|   |   |   +---Include
|   |   |   |   +---MilesAudioDevice
|   |   |   |   |   `---MilesAudioManager.h
|   |   |   |   +---VideoDevice
|   |   |   |   |   `---Bink
|   |   |   |   |       `---BinkVideoPlayer.h
|   |   |   |   +---W3DDevice
|   |   |   |   |   +---Common
|   |   |   |   |   |   +---W3DConvert.h
|   |   |   |   |   |   +---W3DFunctionLexicon.h
|   |   |   |   |   |   +---W3DModuleFactory.h
|   |   |   |   |   |   +---W3DRadar.h
|   |   |   |   |   |   `---W3DThingFactory.h
|   |   |   |   |   +---GameClient
|   |   |   |   |   |   +---Module
|   |   |   |   |   |   |   +---W3DDebrisDraw.h
|   |   |   |   |   |   |   +---W3DDefaultDraw.h
|   |   |   |   |   |   |   +---W3DDependencyModelDraw.h
|   |   |   |   |   |   |   +---W3DLaserDraw.h
|   |   |   |   |   |   |   +---W3DModelDraw.h
|   |   |   |   |   |   |   +---W3DOverlordTankDraw.h
|   |   |   |   |   |   |   +---W3DPoliceCarDraw.h
|   |   |   |   |   |   |   +---W3DProjectileStreamDraw.h
|   |   |   |   |   |   |   +---W3DRopeDraw.h
|   |   |   |   |   |   |   +---W3DScienceModelDraw.h
|   |   |   |   |   |   |   +---W3DSupplyDraw.h
|   |   |   |   |   |   |   +---W3DTankDraw.h
|   |   |   |   |   |   |   +---W3DTankTruckDraw.h
|   |   |   |   |   |   |   +---W3DTracerDraw.h
|   |   |   |   |   |   |   `---W3DTruckDraw.h
|   |   |   |   |   |   +---HeightMap.h
|   |   |   |   |   |   +---TerrainTex.h
|   |   |   |   |   |   +---TileData.h
|   |   |   |   |   |   +---W3DAssetManager.h
|   |   |   |   |   |   +---W3DAssetManagerExposed.h
|   |   |   |   |   |   +---W3DBibBuffer.h
|   |   |   |   |   |   +---W3DBridgeBuffer.h
|   |   |   |   |   |   +---W3DBufferManager.h
|   |   |   |   |   |   +---W3DCustomEdging.h
|   |   |   |   |   |   +---W3DCustomScene.h
|   |   |   |   |   |   +---W3DDebugDisplay.h
|   |   |   |   |   |   +---W3DDebugIcons.h
|   |   |   |   |   |   +---W3DDisplay.h
|   |   |   |   |   |   +---W3DDisplayString.h
|   |   |   |   |   |   +---W3DDisplayStringManager.h
|   |   |   |   |   |   +---W3DDynamicLight.h
|   |   |   |   |   |   +---W3DFileSystem.h
|   |   |   |   |   |   +---W3DGadget.h
|   |   |   |   |   |   +---W3DGameClient.h
|   |   |   |   |   |   +---W3DGameFont.h
|   |   |   |   |   |   +---W3DGameWindow.h
|   |   |   |   |   |   +---W3DGameWindowManager.h
|   |   |   |   |   |   +---W3DGranny.h
|   |   |   |   |   |   +---W3DGUICallbacks.h
|   |   |   |   |   |   +---W3DInGameUI.h
|   |   |   |   |   |   +---W3DMirror.h
|   |   |   |   |   |   +---W3DMouse.h
|   |   |   |   |   |   +---W3DParticleSys.h
|   |   |   |   |   |   +---W3DPoly.h
|   |   |   |   |   |   +---W3DProjectedShadow.h
|   |   |   |   |   |   +---W3DRoadBuffer.h
|   |   |   |   |   |   +---W3DScene.h
|   |   |   |   |   |   +---W3DShaderManager.h
|   |   |   |   |   |   +---W3DShadow.h
|   |   |   |   |   |   +---W3DShroud.h
|   |   |   |   |   |   +---W3DStatusCircle.h
|   |   |   |   |   |   +---W3DTerrainTracks.h
|   |   |   |   |   |   +---W3DTerrainVisual.h
|   |   |   |   |   |   +---W3DTreeBuffer.h
|   |   |   |   |   |   +---W3DVideobuffer.h
|   |   |   |   |   |   +---W3DView.h
|   |   |   |   |   |   +---W3DVolumetricShadow.h
|   |   |   |   |   |   +---W3DWater.h
|   |   |   |   |   |   +---W3DWaterTracks.h
|   |   |   |   |   |   +---W3DWaypointBuffer.h
|   |   |   |   |   |   +---W3DWebBrowser.h
|   |   |   |   |   |   `---WorldHeightMap.h
|   |   |   |   |   `---GameLogic
|   |   |   |   |       +---W3DGameLogic.h
|   |   |   |   |       +---W3DGhostObject.h
|   |   |   |   |       `---W3DTerrainLogic.h
|   |   |   |   `---Win32Device
|   |   |   |       +---Common
|   |   |   |       |   +---Win32BIGFile.h
|   |   |   |       |   +---Win32BIGFileSystem.h
|   |   |   |       |   +---Win32CDManager.h
|   |   |   |       |   +---Win32GameEngine.h
|   |   |   |       |   +---Win32LocalFile.h
|   |   |   |       |   `---Win32LocalFileSystem.h
|   |   |   |       `---GameClient
|   |   |   |           +---Win32DIKeyboard.h
|   |   |   |           +---Win32DIMouse.h
|   |   |   |           `---Win32Mouse.h
|   |   |   +---Source
|   |   |   |   +---MilesAudioDevice
|   |   |   |   |   `---MilesAudioManager.cpp
|   |   |   |   +---VideoDevice
|   |   |   |   |   `---Bink
|   |   |   |   |       `---BinkVideoPlayer.cpp
|   |   |   |   +---W3DDevice
|   |   |   |   |   +---Common
|   |   |   |   |   |   +---System
|   |   |   |   |   |   |   +---W3DFunctionLexicon.cpp
|   |   |   |   |   |   |   `---W3DRadar.cpp
|   |   |   |   |   |   +---Thing
|   |   |   |   |   |   |   +---W3DModuleFactory.cpp
|   |   |   |   |   |   |   `---W3DThingFactory.cpp
|   |   |   |   |   |   `---W3DConvert.cpp
|   |   |   |   |   +---GameClient
|   |   |   |   |   |   +---Drawable
|   |   |   |   |   |   |   `---Draw
|   |   |   |   |   |   |       +---W3DDebrisDraw.cpp
|   |   |   |   |   |   |       +---W3DDefaultDraw.cpp
|   |   |   |   |   |   |       +---W3DDependencyModelDraw.cpp
|   |   |   |   |   |   |       +---W3DLaserDraw.cpp
|   |   |   |   |   |   |       +---W3DModelDraw.cpp
|   |   |   |   |   |   |       +---W3DOverlordTankDraw.cpp
|   |   |   |   |   |   |       +---W3DPoliceCarDraw.cpp
|   |   |   |   |   |   |       +---W3DProjectileStreamDraw.cpp
|   |   |   |   |   |   |       +---W3DRopeDraw.cpp
|   |   |   |   |   |   |       +---W3DScienceModelDraw.cpp
|   |   |   |   |   |   |       +---W3DSupplyDraw.cpp
|   |   |   |   |   |   |       +---W3DTankDraw.cpp
|   |   |   |   |   |   |       +---W3DTankTruckDraw.cpp
|   |   |   |   |   |   |       +---W3DTracerDraw.cpp
|   |   |   |   |   |   |       `---W3DTruckDraw.cpp
|   |   |   |   |   |   +---GUI
|   |   |   |   |   |   |   +---Gadget
|   |   |   |   |   |   |   |   +---W3DCheckBox.cpp
|   |   |   |   |   |   |   |   +---W3DComboBox.cpp
|   |   |   |   |   |   |   |   +---W3DHorizontalSlider.cpp
|   |   |   |   |   |   |   |   +---W3DListBox.cpp
|   |   |   |   |   |   |   |   +---W3DProgressBar.cpp
|   |   |   |   |   |   |   |   +---W3DPushButton.cpp
|   |   |   |   |   |   |   |   +---W3DRadioButton.cpp
|   |   |   |   |   |   |   |   +---W3DStaticText.cpp
|   |   |   |   |   |   |   |   +---W3DTabControl.cpp
|   |   |   |   |   |   |   |   +---W3DTextEntry.cpp
|   |   |   |   |   |   |   |   `---W3DVerticalSlider.cpp
|   |   |   |   |   |   |   +---GUICallbacks
|   |   |   |   |   |   |   |   +---W3DControlBar.cpp
|   |   |   |   |   |   |   |   +---W3DMainMenu.cpp
|   |   |   |   |   |   |   |   `---W3DMOTD.cpp
|   |   |   |   |   |   |   +---W3DGameFont.cpp
|   |   |   |   |   |   |   +---W3DGameWindow.cpp
|   |   |   |   |   |   |   `---W3DGameWindowManager.cpp
|   |   |   |   |   |   +---Shaders
|   |   |   |   |   |   |   +---invmonochrome.nvp
|   |   |   |   |   |   |   +---monochrome.nvp
|   |   |   |   |   |   |   +---motionblur.nvp
|   |   |   |   |   |   |   +---MotionBlur.nvv
|   |   |   |   |   |   |   +---roadnoise2.nvp
|   |   |   |   |   |   |   +---terrain.nvp
|   |   |   |   |   |   |   +---terrainnoise.nvp
|   |   |   |   |   |   |   `---terrainnoise2.nvp
|   |   |   |   |   |   +---Shadow
|   |   |   |   |   |   |   +---W3DBufferManager.cpp
|   |   |   |   |   |   |   +---W3DProjectedShadow.cpp
|   |   |   |   |   |   |   +---W3DShadow.cpp
|   |   |   |   |   |   |   `---W3DVolumetricShadow.cpp
|   |   |   |   |   |   +---Water
|   |   |   |   |   |   |   +---W3DWater.cpp
|   |   |   |   |   |   |   +---W3DWaterTracks.cpp
|   |   |   |   |   |   |   +---wave.nvp
|   |   |   |   |   |   |   `---wave.nvv
|   |   |   |   |   |   +---HeightMap.cpp
|   |   |   |   |   |   +---TerrainTex.cpp
|   |   |   |   |   |   +---TileData.cpp
|   |   |   |   |   |   +---W3DAssetManager.cpp
|   |   |   |   |   |   +---W3DAssetManagerExposed.cpp
|   |   |   |   |   |   +---W3DBibBuffer.cpp
|   |   |   |   |   |   +---W3DBridgeBuffer.cpp
|   |   |   |   |   |   +---W3DCustomEdging.cpp
|   |   |   |   |   |   +---W3DDebugDisplay.cpp
|   |   |   |   |   |   +---W3DDebugIcons.cpp
|   |   |   |   |   |   +---W3DDisplay.cpp
|   |   |   |   |   |   +---W3DDisplayString.cpp
|   |   |   |   |   |   +---W3DDisplayStringManager.cpp
|   |   |   |   |   |   +---W3DDynamicLight.cpp
|   |   |   |   |   |   +---W3DFileSystem.cpp
|   |   |   |   |   |   +---W3DGameClient.cpp
|   |   |   |   |   |   +---W3DGranny.cpp
|   |   |   |   |   |   +---W3DInGameUI.cpp
|   |   |   |   |   |   +---W3DMouse.cpp
|   |   |   |   |   |   +---W3DParticleSys.cpp
|   |   |   |   |   |   +---W3DPoly.cpp
|   |   |   |   |   |   +---W3DRoadBuffer.cpp
|   |   |   |   |   |   +---W3DScene.cpp
|   |   |   |   |   |   +---W3DShaderManager.cpp
|   |   |   |   |   |   +---W3DShroud.cpp
|   |   |   |   |   |   +---W3DStatusCircle.cpp
|   |   |   |   |   |   +---W3DTerrainTracks.cpp
|   |   |   |   |   |   +---W3DTerrainVisual.cpp
|   |   |   |   |   |   +---W3DTreeBuffer.cpp
|   |   |   |   |   |   +---W3DVideoBuffer.cpp
|   |   |   |   |   |   +---W3DView.cpp
|   |   |   |   |   |   +---W3dWaypointBuffer.cpp
|   |   |   |   |   |   +---W3DWebBrowser.cpp
|   |   |   |   |   |   `---WorldHeightMap.cpp
|   |   |   |   |   `---GameLogic
|   |   |   |   |       +---W3DGameLogic.cpp
|   |   |   |   |       +---W3DGhostObject.cpp
|   |   |   |   |       `---W3DTerrainLogic.cpp
|   |   |   |   `---Win32Device
|   |   |   |       +---Common
|   |   |   |       |   +---Win32BIGFile.cpp
|   |   |   |       |   +---Win32BIGFileSystem.cpp
|   |   |   |       |   +---Win32CDManager.cpp
|   |   |   |       |   +---Win32GameEngine.cpp
|   |   |   |       |   +---Win32LocalFile.cpp
|   |   |   |       |   +---Win32LocalFileSystem.cpp
|   |   |   |       |   `---Win32OSDisplay.cpp
|   |   |   |       `---GameClient
|   |   |   |           +---Win32DIKeyboard.cpp
|   |   |   |           +---Win32DIMouse.cpp
|   |   |   |           `---Win32Mouse.cpp
|   |   |   `---GameEngineDevice.dsp
|   |   +---Libraries
|   |   |   +---DX90SDK
|   |   |   |   `---.gitignore
|   |   |   +---Include
|   |   |   |   +---Granny
|   |   |   |   |   `---.gitignore
|   |   |   |   +---Lib
|   |   |   |   |   +---BaseType.h
|   |   |   |   |   `---trig.h
|   |   |   |   `---MSS
|   |   |   |       `---.gitignore
|   |   |   +---max4sdk
|   |   |   |   `---.gitignore
|   |   |   +---Source
|   |   |   |   +---Benchmark
|   |   |   |   |   `---.gitignore
|   |   |   |   +---Compression
|   |   |   |   |   +---EAC
|   |   |   |   |   |   +---btreeabout.cpp
|   |   |   |   |   |   +---btreecodex.h
|   |   |   |   |   |   +---btreedecode.cpp
|   |   |   |   |   |   +---btreeencode.cpp
|   |   |   |   |   |   +---codex.h
|   |   |   |   |   |   +---gimex.h
|   |   |   |   |   |   +---huffabout.cpp
|   |   |   |   |   |   +---huffcodex.h
|   |   |   |   |   |   +---huffdecode.cpp
|   |   |   |   |   |   +---huffencode.cpp
|   |   |   |   |   |   +---refabout.cpp
|   |   |   |   |   |   +---refcodex.h
|   |   |   |   |   |   +---refdecode.cpp
|   |   |   |   |   |   `---refencode.cpp
|   |   |   |   |   +---LZHCompress
|   |   |   |   |   |   +---CompLibHeader
|   |   |   |   |   |   |   `---.gitignore
|   |   |   |   |   |   +---CompLibSource
|   |   |   |   |   |   |   `---.gitignore
|   |   |   |   |   |   +---NoxCompress.cpp
|   |   |   |   |   |   `---NoxCompress.h
|   |   |   |   |   +---ZLib
|   |   |   |   |   |   `---.gitignore
|   |   |   |   |   +---Compression.dsp
|   |   |   |   |   +---Compression.h
|   |   |   |   |   `---CompressionManager.cpp
|   |   |   |   +---EABrowserDispatch
|   |   |   |   |   +---BrowserDispatch.idl
|   |   |   |   |   `---EABrowserDispatch.dsp
|   |   |   |   +---GameSpy
|   |   |   |   |   `---.gitignore
|   |   |   |   +---WPAudio
|   |   |   |   |   +---AUD_Assert.cpp
|   |   |   |   |   +---AUD_Attributes.cpp
|   |   |   |   |   +---AUD_Cache.cpp
|   |   |   |   |   +---AUD_Channel.cpp
|   |   |   |   |   +---AUD_Device.cpp
|   |   |   |   |   +---AUD_DSoundDriver.cpp
|   |   |   |   |   +---AUD_Events.cpp
|   |   |   |   |   +---AUD_Level.cpp
|   |   |   |   |   +---AUD_List.cpp
|   |   |   |   |   +---AUD_Lock.cpp
|   |   |   |   |   +---AUD_Memory.cpp
|   |   |   |   |   +---AUD_Profiler.cpp
|   |   |   |   |   +---AUD_Source.cpp
|   |   |   |   |   +---AUD_StreamBuffering.cpp
|   |   |   |   |   +---AUD_Streamer.cpp
|   |   |   |   |   +---AUD_Time.cpp
|   |   |   |   |   +---AUD_Windows.cpp
|   |   |   |   |   `---WPAudio.dsp
|   |   |   |   +---WWVegas
|   |   |   |   |   +---Miles6
|   |   |   |   |   |   `---.gitignore
|   |   |   |   |   +---WW3D2
|   |   |   |   |   |   +---RequiredAssets
|   |   |   |   |   |   |   +---AddProjectorGradient.tga
|   |   |   |   |   |   |   +---Dazzle.INI
|   |   |   |   |   |   |   +---MultProjectorGradient.tga
|   |   |   |   |   |   |   +---ShatterAVel.tbl
|   |   |   |   |   |   |   +---ShatterPlanes0.w3d
|   |   |   |   |   |   |   +---ShatterVel.tbl
|   |   |   |   |   |   |   `---w3d_missing_texture.tga
|   |   |   |   |   |   +---aabtree.cpp
|   |   |   |   |   |   +---aabtree.h
|   |   |   |   |   |   +---aabtreebuilder.cpp
|   |   |   |   |   |   +---aabtreebuilder.h
|   |   |   |   |   |   +---agg_def.cpp
|   |   |   |   |   |   +---agg_def.h
|   |   |   |   |   |   +---animobj.cpp
|   |   |   |   |   |   +---animobj.h
|   |   |   |   |   |   +---assetmgr.cpp
|   |   |   |   |   |   +---assetmgr.h
|   |   |   |   |   |   +---bitmaphandler.cpp
|   |   |   |   |   |   +---bitmaphandler.h
|   |   |   |   |   |   +---bmp2d.cpp
|   |   |   |   |   |   +---bmp2d.h
|   |   |   |   |   |   +---boxrobj.cpp
|   |   |   |   |   |   +---boxrobj.h
|   |   |   |   |   |   +---bw_render.cpp
|   |   |   |   |   |   +---bw_render.h
|   |   |   |   |   |   +---bwrender.cpp
|   |   |   |   |   |   +---bwrender.h
|   |   |   |   |   |   +---camera.cpp
|   |   |   |   |   |   +---camera.h
|   |   |   |   |   |   +---classid.h
|   |   |   |   |   |   +---collect.cpp
|   |   |   |   |   |   +---collect.h
|   |   |   |   |   |   +---colorspace.h
|   |   |   |   |   |   +---coltest.cpp
|   |   |   |   |   |   +---coltest.h
|   |   |   |   |   |   +---coltype.h
|   |   |   |   |   |   +---composite.cpp
|   |   |   |   |   |   +---composite.h
|   |   |   |   |   |   +---crossplatform.h
|   |   |   |   |   |   +---dazzle.cpp
|   |   |   |   |   |   +---dazzle.h
|   |   |   |   |   |   +---ddsfile.cpp
|   |   |   |   |   |   +---ddsfile.h
|   |   |   |   |   |   +---decalmsh.cpp
|   |   |   |   |   |   +---decalmsh.h
|   |   |   |   |   |   +---decalsys.cpp
|   |   |   |   |   |   +---decalsys.h
|   |   |   |   |   |   +---distlod.cpp
|   |   |   |   |   |   +---distlod.h
|   |   |   |   |   |   +---dllist.h
|   |   |   |   |   |   +---DX8 Rationalizations.txt
|   |   |   |   |   |   +---DX8 Status.txt
|   |   |   |   |   |   +---dx8caps.cpp
|   |   |   |   |   |   +---dx8caps.h
|   |   |   |   |   |   +---dx8fvf.cpp
|   |   |   |   |   |   +---dx8fvf.h
|   |   |   |   |   |   +---dx8indexbuffer.cpp
|   |   |   |   |   |   +---dx8indexbuffer.h
|   |   |   |   |   |   +---dx8list.h
|   |   |   |   |   |   +---dx8polygonrenderer.cpp
|   |   |   |   |   |   +---dx8polygonrenderer.h
|   |   |   |   |   |   +---dx8renderer.cpp
|   |   |   |   |   |   +---dx8renderer.h
|   |   |   |   |   |   +---dx8texman.cpp
|   |   |   |   |   |   +---dx8texman.h
|   |   |   |   |   |   +---DX8ToolModifications.txt
|   |   |   |   |   |   +---dx8vertexbuffer.cpp
|   |   |   |   |   |   +---dx8vertexbuffer.h
|   |   |   |   |   |   +---dx8webbrowser.cpp
|   |   |   |   |   |   +---dx8webbrowser.h
|   |   |   |   |   |   +---dx8wrapper.cpp
|   |   |   |   |   |   +---dx8wrapper.h
|   |   |   |   |   |   +---dynamesh.cpp
|   |   |   |   |   |   +---dynamesh.h
|   |   |   |   |   |   +---font3d.cpp
|   |   |   |   |   |   +---font3d.h
|   |   |   |   |   |   +---formconv.cpp
|   |   |   |   |   |   +---formconv.h
|   |   |   |   |   |   +---FramGrab.cpp
|   |   |   |   |   |   +---framgrab.h
|   |   |   |   |   |   +---hanim.cpp
|   |   |   |   |   |   +---hanim.h
|   |   |   |   |   |   +---hanimmgr.cpp
|   |   |   |   |   |   +---hanimmgr.h
|   |   |   |   |   |   +---hcanim.cpp
|   |   |   |   |   |   +---hcanim.h
|   |   |   |   |   |   +---hlod.cpp
|   |   |   |   |   |   +---hlod.h
|   |   |   |   |   |   +---hmdldef.cpp
|   |   |   |   |   |   +---hmdldef.H
|   |   |   |   |   |   +---hmorphanim.cpp
|   |   |   |   |   |   +---hmorphanim.h
|   |   |   |   |   |   +---hrawanim.cpp
|   |   |   |   |   |   +---hrawanim.h
|   |   |   |   |   |   +---htree.cpp
|   |   |   |   |   |   +---htree.h
|   |   |   |   |   |   +---htreemgr.cpp
|   |   |   |   |   |   +---htreemgr.h
|   |   |   |   |   |   +---intersec.cpp
|   |   |   |   |   |   +---intersec.h
|   |   |   |   |   |   +---intersec.inl
|   |   |   |   |   |   +---inttest.h
|   |   |   |   |   |   +---layer.cpp
|   |   |   |   |   |   +---layer.h
|   |   |   |   |   |   +---light.cpp
|   |   |   |   |   |   +---light.h
|   |   |   |   |   |   +---lightenvironment.cpp
|   |   |   |   |   |   +---lightenvironment.h
|   |   |   |   |   |   +---line3d.cpp
|   |   |   |   |   |   +---line3d.h
|   |   |   |   |   |   +---mapper.cpp
|   |   |   |   |   |   +---mapper.h
|   |   |   |   |   |   +---MAPPERS.TXT
|   |   |   |   |   |   +---matinfo.cpp
|   |   |   |   |   |   +---matinfo.h
|   |   |   |   |   |   +---matpass.cpp
|   |   |   |   |   |   +---matpass.h
|   |   |   |   |   |   +---matrixmapper.cpp
|   |   |   |   |   |   +---matrixmapper.h
|   |   |   |   |   |   +---mesh.cpp
|   |   |   |   |   |   +---mesh.h
|   |   |   |   |   |   +---meshbuild.cpp
|   |   |   |   |   |   +---meshbuild.h
|   |   |   |   |   |   +---meshdam.cpp
|   |   |   |   |   |   +---meshdam.h
|   |   |   |   |   |   +---meshgeometry.cpp
|   |   |   |   |   |   +---meshgeometry.h
|   |   |   |   |   |   +---meshmatdesc.cpp
|   |   |   |   |   |   +---meshmatdesc.h
|   |   |   |   |   |   +---meshmdl.cpp
|   |   |   |   |   |   +---meshmdl.h
|   |   |   |   |   |   +---meshmdlio.cpp
|   |   |   |   |   |   +---metalmap.cpp
|   |   |   |   |   |   +---metalmap.h
|   |   |   |   |   |   +---missingtexture.cpp
|   |   |   |   |   |   +---missingtexture.h
|   |   |   |   |   |   +---motchan.cpp
|   |   |   |   |   |   +---motchan.h
|   |   |   |   |   |   +---nullrobj.cpp
|   |   |   |   |   |   +---nullrobj.h
|   |   |   |   |   |   +---part_buf.cpp
|   |   |   |   |   |   +---part_buf.h
|   |   |   |   |   |   +---part_emt.cpp
|   |   |   |   |   |   +---part_emt.h
|   |   |   |   |   |   +---part_ldr.cpp
|   |   |   |   |   |   +---part_ldr.h
|   |   |   |   |   |   +---pivot.cpp
|   |   |   |   |   |   +---pivot.h
|   |   |   |   |   |   +---pointgr.cpp
|   |   |   |   |   |   +---pointgr.h
|   |   |   |   |   |   +---polyinfo.cpp
|   |   |   |   |   |   +---polyinfo.h
|   |   |   |   |   |   +---predlod.cpp
|   |   |   |   |   |   +---predlod.h
|   |   |   |   |   |   +---prim_anim.cpp
|   |   |   |   |   |   +---prim_anim.h
|   |   |   |   |   |   +---projector.cpp
|   |   |   |   |   |   +---projector.h
|   |   |   |   |   |   +---proto.cpp
|   |   |   |   |   |   +---proto.h
|   |   |   |   |   |   +---proxy.h
|   |   |   |   |   |   +---rddesc.h
|   |   |   |   |   |   +---render2d.cpp
|   |   |   |   |   |   +---render2d.h
|   |   |   |   |   |   +---render2dsentence.cpp
|   |   |   |   |   |   +---render2dsentence.h
|   |   |   |   |   |   +---RenderObjectGuide.txt
|   |   |   |   |   |   +---renderobjectrecycler.cpp
|   |   |   |   |   |   +---renderobjectrecycler.h
|   |   |   |   |   |   +---rendobj.cpp
|   |   |   |   |   |   +---rendobj.h
|   |   |   |   |   |   +---rinfo.cpp
|   |   |   |   |   |   +---rinfo.h
|   |   |   |   |   |   +---ringobj.cpp
|   |   |   |   |   |   +---ringobj.h
|   |   |   |   |   |   +---robjlist.h
|   |   |   |   |   |   +---scene.cpp
|   |   |   |   |   |   +---scene.h
|   |   |   |   |   |   +---segline.cpp
|   |   |   |   |   |   +---segline.h
|   |   |   |   |   |   +---seglinerenderer.cpp
|   |   |   |   |   |   +---seglinerenderer.h
|   |   |   |   |   |   +---shader.cpp
|   |   |   |   |   |   +---shader.h
|   |   |   |   |   |   +---shattersystem.cpp
|   |   |   |   |   |   +---shattersystem.h
|   |   |   |   |   |   +---snappts.cpp
|   |   |   |   |   |   +---snapPts.h
|   |   |   |   |   |   +---sortingrenderer.cpp
|   |   |   |   |   |   +---sortingrenderer.h
|   |   |   |   |   |   +---soundrobj.cpp
|   |   |   |   |   |   +---soundrobj.h
|   |   |   |   |   |   +---sphereobj.cpp
|   |   |   |   |   |   +---sphereobj.h
|   |   |   |   |   |   +---sr_util.cpp
|   |   |   |   |   |   +---sr_util.h
|   |   |   |   |   |   +---State Management.txt
|   |   |   |   |   |   +---statistics.cpp
|   |   |   |   |   |   +---statistics.h
|   |   |   |   |   |   +---streak.cpp
|   |   |   |   |   |   +---streak.h
|   |   |   |   |   |   +---streakRender.cpp
|   |   |   |   |   |   +---streakRender.h
|   |   |   |   |   |   +---stripoptimizer.cpp
|   |   |   |   |   |   +---stripoptimizer.h
|   |   |   |   |   |   +---surfaceclass.cpp
|   |   |   |   |   |   +---surfaceclass.h
|   |   |   |   |   |   +---texfcach.cpp
|   |   |   |   |   |   +---texfcach.h
|   |   |   |   |   |   +---texproject.cpp
|   |   |   |   |   |   +---texproject.h
|   |   |   |   |   |   +---textdraw.cpp
|   |   |   |   |   |   +---textdraw.h
|   |   |   |   |   |   +---texture.cpp
|   |   |   |   |   |   +---texture.h
|   |   |   |   |   |   +---texturefile.cpp
|   |   |   |   |   |   +---texturefile.h
|   |   |   |   |   |   +---textureloader.cpp
|   |   |   |   |   |   +---textureloader.h
|   |   |   |   |   |   +---texturethumbnail.cpp
|   |   |   |   |   |   +---texturethumbnail.h
|   |   |   |   |   |   +---txt.cpp
|   |   |   |   |   |   +---txt.h
|   |   |   |   |   |   +---txt2d.cpp
|   |   |   |   |   |   +---txt2d.h
|   |   |   |   |   |   +---vertmaterial.cpp
|   |   |   |   |   |   +---vertmaterial.h
|   |   |   |   |   |   +---visrasterizer.cpp
|   |   |   |   |   |   +---visrasterizer.h
|   |   |   |   |   |   +---w3d_dep.cpp
|   |   |   |   |   |   +---w3d_dep.h
|   |   |   |   |   |   +---w3d_file.h
|   |   |   |   |   |   +---w3d_obsolete.h
|   |   |   |   |   |   +---w3d_util.cpp
|   |   |   |   |   |   +---w3d_util.h
|   |   |   |   |   |   +---w3derr.h
|   |   |   |   |   |   +---w3dexclusionlist.cpp
|   |   |   |   |   |   +---w3dexclusionlist.h
|   |   |   |   |   |   +---ww3d.cpp
|   |   |   |   |   |   +---ww3d.h
|   |   |   |   |   |   +---ww3d2.dsp
|   |   |   |   |   |   +---ww3dformat.cpp
|   |   |   |   |   |   +---ww3dformat.h
|   |   |   |   |   |   +---ww3dids.h
|   |   |   |   |   |   `---ww3dtrig.h
|   |   |   |   |   +---WWAudio
|   |   |   |   |   |   +---AABTreeSoundCullClass.h
|   |   |   |   |   |   +---AudibleSound.cpp
|   |   |   |   |   |   +---AudibleSound.h
|   |   |   |   |   |   +---AudioEvents.h
|   |   |   |   |   |   +---AudioSaveLoad.cpp
|   |   |   |   |   |   +---AudioSaveLoad.h
|   |   |   |   |   |   +---FilteredSound.cpp
|   |   |   |   |   |   +---FilteredSound.h
|   |   |   |   |   |   +---Listener.cpp
|   |   |   |   |   |   +---Listener.h
|   |   |   |   |   |   +---listenerhandle.cpp
|   |   |   |   |   |   +---listenerhandle.h
|   |   |   |   |   |   +---LogicalListener.cpp
|   |   |   |   |   |   +---LogicalListener.h
|   |   |   |   |   |   +---LogicalSound.cpp
|   |   |   |   |   |   +---LogicalSound.h
|   |   |   |   |   |   +---PriorityVector.h
|   |   |   |   |   |   +---sound2dhandle.cpp
|   |   |   |   |   |   +---sound2dhandle.h
|   |   |   |   |   |   +---Sound3D.cpp
|   |   |   |   |   |   +---Sound3D.h
|   |   |   |   |   |   +---sound3dhandle.cpp
|   |   |   |   |   |   +---sound3dhandle.h
|   |   |   |   |   |   +---SoundBuffer.cpp
|   |   |   |   |   |   +---SoundBuffer.h
|   |   |   |   |   |   +---SoundChunkIDs.h
|   |   |   |   |   |   +---SoundCullObj.h
|   |   |   |   |   |   +---soundhandle.cpp
|   |   |   |   |   |   +---soundhandle.h
|   |   |   |   |   |   +---SoundPseudo3D.cpp
|   |   |   |   |   |   +---SoundPseudo3D.h
|   |   |   |   |   |   +---SoundScene.cpp
|   |   |   |   |   |   +---SoundScene.h
|   |   |   |   |   |   +---SoundSceneObj.cpp
|   |   |   |   |   |   +---SoundSceneObj.h
|   |   |   |   |   |   +---soundstreamhandle.cpp
|   |   |   |   |   |   +---soundstreamhandle.h
|   |   |   |   |   |   +---Threads.cpp
|   |   |   |   |   |   +---Threads.h
|   |   |   |   |   |   +---Utils.cpp
|   |   |   |   |   |   +---Utils.h
|   |   |   |   |   |   +---WWAudio.cpp
|   |   |   |   |   |   +---WWAudio.dsp
|   |   |   |   |   |   `---WWAudio.h
|   |   |   |   |   +---WWDebug
|   |   |   |   |   |   +---wwdebug.cpp
|   |   |   |   |   |   +---wwdebug.dsp
|   |   |   |   |   |   +---wwdebug.h
|   |   |   |   |   |   +---wwhack.h
|   |   |   |   |   |   +---wwmemlog.cpp
|   |   |   |   |   |   +---wwmemlog.h
|   |   |   |   |   |   +---wwprofile.cpp
|   |   |   |   |   |   `---wwprofile.h
|   |   |   |   |   +---WWDownload
|   |   |   |   |   |   +---Download.cpp
|   |   |   |   |   |   +---Download.h
|   |   |   |   |   |   +---DownloadDebug.h
|   |   |   |   |   |   +---downloaddefs.h
|   |   |   |   |   |   +---FTP.CPP
|   |   |   |   |   |   +---ftp.h
|   |   |   |   |   |   +---ftpdefs.h
|   |   |   |   |   |   +---registry.cpp
|   |   |   |   |   |   +---Registry.h
|   |   |   |   |   |   +---urlBuilder.cpp
|   |   |   |   |   |   +---urlBuilder.h
|   |   |   |   |   |   `---WWDownload.dsp
|   |   |   |   |   +---WWLib
|   |   |   |   |   |   +---_convert.cpp
|   |   |   |   |   |   +---_convert.h
|   |   |   |   |   |   +---_mono.cpp
|   |   |   |   |   |   +---_mono.h
|   |   |   |   |   |   +---_timer.cpp
|   |   |   |   |   |   +---_timer.h
|   |   |   |   |   |   +---_xmouse.h
|   |   |   |   |   |   +---always.h
|   |   |   |   |   |   +---argv.cpp
|   |   |   |   |   |   +---argv.h
|   |   |   |   |   |   +---b64pipe.cpp
|   |   |   |   |   |   +---b64pipe.h
|   |   |   |   |   |   +---b64straw.cpp
|   |   |   |   |   |   +---b64straw.h
|   |   |   |   |   |   +---base64.cpp
|   |   |   |   |   |   +---base64.h
|   |   |   |   |   |   +---bfiofile.h
|   |   |   |   |   |   +---binheap.h
|   |   |   |   |   |   +---bittype.h
|   |   |   |   |   |   +---blit.cpp
|   |   |   |   |   |   +---blit.h
|   |   |   |   |   |   +---blitblit.h
|   |   |   |   |   |   +---blitter.h
|   |   |   |   |   |   +---blowfish.cpp
|   |   |   |   |   |   +---blowfish.h
|   |   |   |   |   |   +---blowpipe.h
|   |   |   |   |   |   +---blwstraw.h
|   |   |   |   |   |   +---bool.h
|   |   |   |   |   |   +---borlandc.h
|   |   |   |   |   |   +---bound.h
|   |   |   |   |   |   +---BSEARCH.H
|   |   |   |   |   |   +---bsurface.h
|   |   |   |   |   |   +---buff.cpp
|   |   |   |   |   |   +---BUFF.H
|   |   |   |   |   |   +---bufffile.cpp
|   |   |   |   |   |   +---bufffile.h
|   |   |   |   |   |   +---CallbackHook.h
|   |   |   |   |   |   +---chunkio.cpp
|   |   |   |   |   |   +---chunkio.h
|   |   |   |   |   |   +---convert.cpp
|   |   |   |   |   |   +---Convert.h
|   |   |   |   |   |   +---cpudetect.cpp
|   |   |   |   |   |   +---cpudetect.h
|   |   |   |   |   |   +---crc.cpp
|   |   |   |   |   |   +---CRC.H
|   |   |   |   |   |   +---crcpipe.h
|   |   |   |   |   |   +---crcstraw.h
|   |   |   |   |   |   +---cstraw.cpp
|   |   |   |   |   |   +---cstraw.h
|   |   |   |   |   |   +---data.cpp
|   |   |   |   |   |   +---data.h
|   |   |   |   |   |   +---ddraw.cpp
|   |   |   |   |   |   +---dib.h
|   |   |   |   |   |   +---draw.h
|   |   |   |   |   |   +---dsurface.cpp
|   |   |   |   |   |   +---dsurface.h
|   |   |   |   |   |   +---ffactory.cpp
|   |   |   |   |   |   +---ffactory.h
|   |   |   |   |   |   +---fixed.h
|   |   |   |   |   |   +---FONT.H
|   |   |   |   |   |   +---gcd_lcm.cpp
|   |   |   |   |   |   +---gcd_lcm.h
|   |   |   |   |   |   +---hash.cpp
|   |   |   |   |   |   +---hash.h
|   |   |   |   |   |   +---hashcalc.h
|   |   |   |   |   |   +---HASHLIST.H
|   |   |   |   |   |   +---hashtab.h
|   |   |   |   |   |   +---hashtemplate.h
|   |   |   |   |   |   +---hsv.cpp
|   |   |   |   |   |   +---hsv.h
|   |   |   |   |   |   +---IFF.H
|   |   |   |   |   |   +---incdec.h
|   |   |   |   |   |   +---INDEX.H
|   |   |   |   |   |   +---ini.cpp
|   |   |   |   |   |   +---INI.H
|   |   |   |   |   |   +---inisup.h
|   |   |   |   |   |   +---int.cpp
|   |   |   |   |   |   +---INT.H
|   |   |   |   |   |   +---iostruct.h
|   |   |   |   |   |   +---jshell.cpp
|   |   |   |   |   |   +---keyboard.cpp
|   |   |   |   |   |   +---keyboard.h
|   |   |   |   |   |   +---LaunchWeb.cpp
|   |   |   |   |   |   +---LaunchWeb.h
|   |   |   |   |   |   +---lcw.cpp
|   |   |   |   |   |   +---LCW.H
|   |   |   |   |   |   +---lcwpipe.h
|   |   |   |   |   |   +---LISTNODE.H
|   |   |   |   |   |   +---load.cpp
|   |   |   |   |   |   +---mempool.h
|   |   |   |   |   |   +---misc.h
|   |   |   |   |   |   +---mixfile.cpp
|   |   |   |   |   |   +---mixfile.h
|   |   |   |   |   |   +---mmsys.h
|   |   |   |   |   |   +---mono.cpp
|   |   |   |   |   |   +---MONO.H
|   |   |   |   |   |   +---MONODRVR.H
|   |   |   |   |   |   +---mpmath.cpp
|   |   |   |   |   |   +---MPMATH.H
|   |   |   |   |   |   +---mpu.cpp
|   |   |   |   |   |   +---MPU.H
|   |   |   |   |   |   +---msgloop.cpp
|   |   |   |   |   |   +---msgloop.h
|   |   |   |   |   |   +---multilist.cpp
|   |   |   |   |   |   +---multilist.h
|   |   |   |   |   |   +---mutex.cpp
|   |   |   |   |   |   +---mutex.h
|   |   |   |   |   |   +---noinit.h
|   |   |   |   |   |   +---Notify.h
|   |   |   |   |   |   +---nstrdup.cpp
|   |   |   |   |   |   +---nstrdup.h
|   |   |   |   |   |   +---ntree.h
|   |   |   |   |   |   +---obscure.h
|   |   |   |   |   |   +---palette.cpp
|   |   |   |   |   |   +---PALETTE.H
|   |   |   |   |   |   +---pcx.cpp
|   |   |   |   |   |   +---pcx.H
|   |   |   |   |   |   +---pipe.cpp
|   |   |   |   |   |   +---PIPE.H
|   |   |   |   |   |   +---pk.cpp
|   |   |   |   |   |   +---PK.H
|   |   |   |   |   |   +---pkpipe.h
|   |   |   |   |   |   +---pkstraw.h
|   |   |   |   |   |   +---Point.h
|   |   |   |   |   |   +---ramfile.cpp
|   |   |   |   |   |   +---RAMFILE.H
|   |   |   |   |   |   +---random.cpp
|   |   |   |   |   |   +---RANDOM.H
|   |   |   |   |   |   +---rawfile.cpp
|   |   |   |   |   |   +---RAWFILE.H
|   |   |   |   |   |   +---rc4.cpp
|   |   |   |   |   |   +---rc4.h
|   |   |   |   |   |   +---rcfile.cpp
|   |   |   |   |   |   +---rcfile.h
|   |   |   |   |   |   +---readline.cpp
|   |   |   |   |   |   +---readline.h
|   |   |   |   |   |   +---realcrc.cpp
|   |   |   |   |   |   +---realcrc.h
|   |   |   |   |   |   +---ref_ptr.h
|   |   |   |   |   |   +---refcount.cpp
|   |   |   |   |   |   +---refcount.h
|   |   |   |   |   |   +---registry.cpp
|   |   |   |   |   |   +---registry.h
|   |   |   |   |   |   +---rgb.cpp
|   |   |   |   |   |   +---RGB.H
|   |   |   |   |   |   +---rle.cpp
|   |   |   |   |   |   +---RLE.H
|   |   |   |   |   |   +---rlerle.h
|   |   |   |   |   |   +---RNDSTRAW.H
|   |   |   |   |   |   +---rndstrng.cpp
|   |   |   |   |   |   +---rndstrng.h
|   |   |   |   |   |   +---rng.h
|   |   |   |   |   |   +---rsacrypt.h
|   |   |   |   |   |   +---sampler.cpp
|   |   |   |   |   |   +---sampler.h
|   |   |   |   |   |   +---search.h
|   |   |   |   |   |   +---sha.cpp
|   |   |   |   |   |   +---sha.h
|   |   |   |   |   |   +---shapeset.h
|   |   |   |   |   |   +---shapipe.h
|   |   |   |   |   |   +---sharebuf.h
|   |   |   |   |   |   +---shastraw.h
|   |   |   |   |   |   +---Signaler.h
|   |   |   |   |   |   +---simplevec.h
|   |   |   |   |   |   +---SLIST.H
|   |   |   |   |   |   +---slnode.cpp
|   |   |   |   |   |   +---SLNODE.H
|   |   |   |   |   |   +---smartptr.h
|   |   |   |   |   |   +---srandom.cpp
|   |   |   |   |   |   +---srandom.h
|   |   |   |   |   |   +---stimer.cpp
|   |   |   |   |   |   +---stimer.h
|   |   |   |   |   |   +---stl.h
|   |   |   |   |   |   +---straw.cpp
|   |   |   |   |   |   +---STRAW.H
|   |   |   |   |   |   +---strtok_r.cpp
|   |   |   |   |   |   +---strtok_r.h
|   |   |   |   |   |   +---Surface.h
|   |   |   |   |   |   +---surfrect.h
|   |   |   |   |   |   +---swap.h
|   |   |   |   |   |   +---systimer.cpp
|   |   |   |   |   |   +---systimer.h
|   |   |   |   |   |   +---tagblock.cpp
|   |   |   |   |   |   +---TagBlock.h
|   |   |   |   |   |   +---TARGA.CPP
|   |   |   |   |   |   +---TARGA.H
|   |   |   |   |   |   +---textfile.cpp
|   |   |   |   |   |   +---textfile.h
|   |   |   |   |   |   +---thread.cpp
|   |   |   |   |   |   +---thread.h
|   |   |   |   |   |   +---timer.h
|   |   |   |   |   |   +---trackwin.h
|   |   |   |   |   |   +---trackxy.h
|   |   |   |   |   |   +---trect.h
|   |   |   |   |   |   +---trim.cpp
|   |   |   |   |   |   +---trim.h
|   |   |   |   |   |   +---uarray.h
|   |   |   |   |   |   +---vector.cpp
|   |   |   |   |   |   +---Vector.H
|   |   |   |   |   |   +---verchk.cpp
|   |   |   |   |   |   +---verchk.h
|   |   |   |   |   |   +---visualc.h
|   |   |   |   |   |   +---WATCOM.H
|   |   |   |   |   |   +---widestring.cpp
|   |   |   |   |   |   +---widestring.h
|   |   |   |   |   |   +---win.cpp
|   |   |   |   |   |   +---win.h
|   |   |   |   |   |   +---WWCOMUtil.cpp
|   |   |   |   |   |   +---WWCOMUtil.h
|   |   |   |   |   |   +---wwfile.cpp
|   |   |   |   |   |   +---WWFILE.H
|   |   |   |   |   |   +---wwfont.cpp
|   |   |   |   |   |   +---wwfont.h
|   |   |   |   |   |   +---wwlib.dsp
|   |   |   |   |   |   +---wwmouse.h
|   |   |   |   |   |   +---wwstring.cpp
|   |   |   |   |   |   +---wwstring.h
|   |   |   |   |   |   +---xmouse.h
|   |   |   |   |   |   +---xpipe.cpp
|   |   |   |   |   |   +---XPIPE.H
|   |   |   |   |   |   +---xstraw.cpp
|   |   |   |   |   |   +---XSTRAW.H
|   |   |   |   |   |   +---xsurface.cpp
|   |   |   |   |   |   `---xsurface.h
|   |   |   |   |   +---WWMath
|   |   |   |   |   |   +---aabox.cpp
|   |   |   |   |   |   +---aabox.h
|   |   |   |   |   |   +---aabtreecull.cpp
|   |   |   |   |   |   +---aabtreecull.h
|   |   |   |   |   |   +---aaplane.h
|   |   |   |   |   |   +---cardinalspline.cpp
|   |   |   |   |   |   +---cardinalspline.h
|   |   |   |   |   |   +---castres.h
|   |   |   |   |   |   +---catmullromspline.cpp
|   |   |   |   |   |   +---catmullromspline.h
|   |   |   |   |   |   +---colmath.cpp
|   |   |   |   |   |   +---colmath.h
|   |   |   |   |   |   +---colmathaabox.cpp
|   |   |   |   |   |   +---colmathaabox.h
|   |   |   |   |   |   +---colmathaabtri.cpp
|   |   |   |   |   |   +---colmathfrustum.cpp
|   |   |   |   |   |   +---colmathfrustum.h
|   |   |   |   |   |   +---colmathinlines.h
|   |   |   |   |   |   +---colmathline.cpp
|   |   |   |   |   |   +---colmathline.h
|   |   |   |   |   |   +---colmathobbobb.cpp
|   |   |   |   |   |   +---colmathobbox.cpp
|   |   |   |   |   |   +---colmathobbtri.cpp
|   |   |   |   |   |   +---colmathplane.cpp
|   |   |   |   |   |   +---colmathplane.h
|   |   |   |   |   |   +---colmathsphere.cpp
|   |   |   |   |   |   +---cullsys.cpp
|   |   |   |   |   |   +---cullsys.h
|   |   |   |   |   |   +---culltype.h
|   |   |   |   |   |   +---curve.cpp
|   |   |   |   |   |   +---curve.h
|   |   |   |   |   |   +---euler.cpp
|   |   |   |   |   |   +---euler.h
|   |   |   |   |   |   +---frustum.cpp
|   |   |   |   |   |   +---frustum.h
|   |   |   |   |   |   +---gridcull.cpp
|   |   |   |   |   |   +---gridcull.h
|   |   |   |   |   |   +---hermitespline.cpp
|   |   |   |   |   |   +---hermitespline.h
|   |   |   |   |   |   +---lineseg.cpp
|   |   |   |   |   |   +---lineseg.h
|   |   |   |   |   |   +---lookuptable.cpp
|   |   |   |   |   |   +---lookuptable.h
|   |   |   |   |   |   +---matrix3.cpp
|   |   |   |   |   |   +---matrix3.h
|   |   |   |   |   |   +---matrix3d.cpp
|   |   |   |   |   |   +---matrix3d.h
|   |   |   |   |   |   +---matrix4.cpp
|   |   |   |   |   |   +---matrix4.h
|   |   |   |   |   |   +---obbox.cpp
|   |   |   |   |   |   +---obbox.h
|   |   |   |   |   |   +---ode.cpp
|   |   |   |   |   |   +---ode.h
|   |   |   |   |   |   +---plane.h
|   |   |   |   |   |   +---pot.cpp
|   |   |   |   |   |   +---pot.h
|   |   |   |   |   |   +---quat.cpp
|   |   |   |   |   |   +---quat.h
|   |   |   |   |   |   +---rect.h
|   |   |   |   |   |   +---sphere.h
|   |   |   |   |   |   +---tcbspline.cpp
|   |   |   |   |   |   +---tcbspline.h
|   |   |   |   |   |   +---tri.cpp
|   |   |   |   |   |   +---tri.h
|   |   |   |   |   |   +---v3_rnd.cpp
|   |   |   |   |   |   +---v3_rnd.h
|   |   |   |   |   |   +---vector2.h
|   |   |   |   |   |   +---vector2i.h
|   |   |   |   |   |   +---vector3.h
|   |   |   |   |   |   +---Vector3i.h
|   |   |   |   |   |   +---vector4.h
|   |   |   |   |   |   +---vehiclecurve.cpp
|   |   |   |   |   |   +---vehiclecurve.h
|   |   |   |   |   |   +---vp.cpp
|   |   |   |   |   |   +---vp.h
|   |   |   |   |   |   +---wwmath.cpp
|   |   |   |   |   |   +---wwmath.dsp
|   |   |   |   |   |   +---wwmath.h
|   |   |   |   |   |   `---wwmathids.h
|   |   |   |   |   +---WWSaveLoad
|   |   |   |   |   |   +---definition.cpp
|   |   |   |   |   |   +---definition.h
|   |   |   |   |   |   +---definitionclassids.h
|   |   |   |   |   |   +---definitionfactory.cpp
|   |   |   |   |   |   +---definitionfactory.h
|   |   |   |   |   |   +---definitionfactorymgr.cpp
|   |   |   |   |   |   +---definitionfactorymgr.h
|   |   |   |   |   |   +---definitionmgr.cpp
|   |   |   |   |   |   +---definitionmgr.h
|   |   |   |   |   |   +---editable.h
|   |   |   |   |   |   +---parameter.cpp
|   |   |   |   |   |   +---parameter.h
|   |   |   |   |   |   +---parameterlist.h
|   |   |   |   |   |   +---parametertypes.h
|   |   |   |   |   |   +---persist.h
|   |   |   |   |   |   +---persistfactory.cpp
|   |   |   |   |   |   +---persistfactory.h
|   |   |   |   |   |   +---pointerremap.cpp
|   |   |   |   |   |   +---pointerremap.h
|   |   |   |   |   |   +---postloadable.h
|   |   |   |   |   |   +---saveload.cpp
|   |   |   |   |   |   +---saveload.h
|   |   |   |   |   |   +---saveloadids.h
|   |   |   |   |   |   +---saveloadstatus.cpp
|   |   |   |   |   |   +---saveloadstatus.h
|   |   |   |   |   |   +---saveloadsubsystem.cpp
|   |   |   |   |   |   +---saveloadsubsystem.h
|   |   |   |   |   |   +---simpledefinitionfactory.h
|   |   |   |   |   |   +---simpleparameter.h
|   |   |   |   |   |   +---twiddler.cpp
|   |   |   |   |   |   +---twiddler.h
|   |   |   |   |   |   +---wwsaveload.cpp
|   |   |   |   |   |   +---wwsaveload.dsp
|   |   |   |   |   |   `---wwsaveload.h
|   |   |   |   |   `---Wwutil
|   |   |   |   |       +---mathutil.cpp
|   |   |   |   |       +---mathutil.h
|   |   |   |   |       +---miscutil.cpp
|   |   |   |   |       +---miscutil.h
|   |   |   |   |       `---wwutil.dsp
|   |   |   |   +---template.cpp
|   |   |   |   `---template.h
|   |   |   `---STLport-4.5.3
|   |   |       `---.gitignore
|   |   +---Main
|   |   |   +---Generals.ico
|   |   |   +---resource.h
|   |   |   +---RTS.RC
|   |   |   +---WinMain.cpp
|   |   |   `---WinMain.h
|   |   +---Tools
|   |   |   +---Autorun
|   |   |   |   +---ARGS.CPP
|   |   |   |   +---ARGS.H
|   |   |   |   +---Autorun English.dsp
|   |   |   |   +---autorun.cpp
|   |   |   |   +---autorun.h
|   |   |   |   +---Autorun.ICO
|   |   |   |   +---AUTORUN.RC
|   |   |   |   +---CallbackHook.h
|   |   |   |   +---CDCNTRL.CPP
|   |   |   |   +---CDCNTRL.H
|   |   |   |   +---DrawButton.cpp
|   |   |   |   +---DrawButton.h
|   |   |   |   +---EZGIMEX.cpp
|   |   |   |   +---GameText.cpp
|   |   |   |   +---GameText.h
|   |   |   |   +---GETCD.CPP
|   |   |   |   +---GetCD.h
|   |   |   |   +---gimex.h
|   |   |   |   +---IGR.cpp
|   |   |   |   +---IGR.h
|   |   |   |   +---Jsupport.cpp
|   |   |   |   +---JSUPPORT.H
|   |   |   |   +---leanAndMeanAutorun.h
|   |   |   |   +---Locale_API.cpp
|   |   |   |   +---Locale_API.h
|   |   |   |   +---locale.cpp
|   |   |   |   +---locale.h
|   |   |   |   +---POINT.h
|   |   |   |   +---RECT.h
|   |   |   |   +---resource.h
|   |   |   |   +---TTFont.cpp
|   |   |   |   +---TTFont.h
|   |   |   |   +---Utils.cpp
|   |   |   |   +---Utils.h
|   |   |   |   +---ViewHTML.cpp
|   |   |   |   +---ViewHTML.h
|   |   |   |   +---WinFix.CPP
|   |   |   |   +---WinFix.H
|   |   |   |   +---Wnd_file.cpp
|   |   |   |   +---Wnd_File.h
|   |   |   |   +---WSYS_File.cpp
|   |   |   |   +---WSYS_file.h
|   |   |   |   +---WSYS_FileSystem.cpp
|   |   |   |   +---WSYS_FileSystem.h
|   |   |   |   +---WSYS_RAMFile.cpp
|   |   |   |   +---WSYS_RAMFile.h
|   |   |   |   +---WSYS_StdFile.cpp
|   |   |   |   +---WSYS_StdFile.h
|   |   |   |   +---WSYS_StdFileSystem.cpp
|   |   |   |   `---WSYS_StdFileSystem.h
|   |   |   +---Babylon
|   |   |   |   +---res
|   |   |   |   |   +---bitmap1.bmp
|   |   |   |   |   +---noxstring.ico
|   |   |   |   |   +---noxstring.rc2
|   |   |   |   |   +---pause.bmp
|   |   |   |   |   +---paused.bmp
|   |   |   |   |   +---playd.bmp
|   |   |   |   |   +---playu.bmp
|   |   |   |   |   `---stop.bmp
|   |   |   |   +---BABYLON.XLT
|   |   |   |   +---bin.cpp
|   |   |   |   +---bin.h
|   |   |   |   +---DlgProxy.cpp
|   |   |   |   +---DlgProxy.h
|   |   |   |   +---excel8.cpp
|   |   |   |   +---excel8.h
|   |   |   |   +---expimp.cpp
|   |   |   |   +---expimp.h
|   |   |   |   +---ExportDlg.cpp
|   |   |   |   +---ExportDlg.h
|   |   |   |   +---fileops.cpp
|   |   |   |   +---fileops.h
|   |   |   |   +---GenerateDlg.cpp
|   |   |   |   +---GenerateDlg.h
|   |   |   |   +---iff.cpp
|   |   |   |   +---iff.h
|   |   |   |   +---list.cpp
|   |   |   |   +---list.h
|   |   |   |   +---loadsave.cpp
|   |   |   |   +---loadsave.h
|   |   |   |   +---MatchDlg.cpp
|   |   |   |   +---MatchDlg.h
|   |   |   |   +---noxstring.cpp
|   |   |   |   +---noxstring.dsp
|   |   |   |   +---noxstring.dsw
|   |   |   |   +---noxstring.h
|   |   |   |   +---noxstring.odl
|   |   |   |   +---noxstring.rc
|   |   |   |   +---noxstring.reg
|   |   |   |   +---noxstringDlg.cpp
|   |   |   |   +---noxstringDlg.h
|   |   |   |   +---olestring.cpp
|   |   |   |   +---olestring.h
|   |   |   |   +---ProceedDlg.cpp
|   |   |   |   +---ProceedDlg.h
|   |   |   |   +---Report.cpp
|   |   |   |   +---Report.h
|   |   |   |   +---resource.h
|   |   |   |   +---resource.hm
|   |   |   |   +---RetranslateDlg.cpp
|   |   |   |   +---RetranslateDlg.h
|   |   |   |   +---StdAfx.cpp
|   |   |   |   +---StdAfx.h
|   |   |   |   +---STRCHECK.PL
|   |   |   |   +---transcs.cpp
|   |   |   |   +---transcs.h
|   |   |   |   +---TransDB.cpp
|   |   |   |   +---TransDB.h
|   |   |   |   +---VerifyDlg.cpp
|   |   |   |   +---VerifyDlg.h
|   |   |   |   +---VerifyTextDlg.cpp
|   |   |   |   +---VerifyTextDlg.h
|   |   |   |   +---ViewDBsDlg.cpp
|   |   |   |   +---VIEWDBSII.cpp
|   |   |   |   +---VIEWDBSII.h
|   |   |   |   +---XLStuff.cpp
|   |   |   |   `---XLStuff.h
|   |   |   +---buildVersionUpdate
|   |   |   |   +---buildVersionUpdate.cpp
|   |   |   |   `---buildVersionUpdate.dsp
|   |   |   +---Compress
|   |   |   |   +---Compress.cpp
|   |   |   |   `---Compress.dsp
|   |   |   +---CRCDiff
|   |   |   |   +---bottom.html
|   |   |   |   +---CRCDiff.cpp
|   |   |   |   +---CRCDiff.dsp
|   |   |   |   +---debug.cpp
|   |   |   |   +---debug.h
|   |   |   |   +---expander.cpp
|   |   |   |   +---expander.h
|   |   |   |   +---KVPair.cpp
|   |   |   |   +---KVPair.h
|   |   |   |   +---misc.h
|   |   |   |   +---row.html
|   |   |   |   +---style.css
|   |   |   |   `---top.html
|   |   |   +---DebugWindow
|   |   |   |   +---res
|   |   |   |   |   `---DebugWindow.rc2
|   |   |   |   +---DebugWindow.cpp
|   |   |   |   +---DebugWindow.def
|   |   |   |   +---DebugWindow.dsp
|   |   |   |   +---DebugWindow.h
|   |   |   |   +---DebugWindow.rc
|   |   |   |   +---DebugWindowDialog.cpp
|   |   |   |   +---DebugWindowDialog.h
|   |   |   |   +---DebugWindowExport.h
|   |   |   |   +---post-build.bat
|   |   |   |   +---Resource.h
|   |   |   |   +---StdAfx.cpp
|   |   |   |   `---StdAfx.h
|   |   |   +---GUIEdit
|   |   |   |   +---Include
|   |   |   |   |   +---DialogProc.h
|   |   |   |   |   +---EditWindow.h
|   |   |   |   |   +---GUIEdit.h
|   |   |   |   |   +---GUIEditColor.h
|   |   |   |   |   +---GUIEditDisplay.h
|   |   |   |   |   +---GUIEditWindowManager.h
|   |   |   |   |   +---HierarchyView.h
|   |   |   |   |   +---LayoutScheme.h
|   |   |   |   |   +---Properties.h
|   |   |   |   |   `---WinMain.h
|   |   |   |   +---Resource
|   |   |   |   |   +---GUIEdit.ico
|   |   |   |   |   +---GUIEdit.rc
|   |   |   |   |   +---resource.h
|   |   |   |   |   `---small.ico
|   |   |   |   +---Source
|   |   |   |   |   +---Dialog Procedures
|   |   |   |   |   |   +---CallbackEditor.cpp
|   |   |   |   |   |   +---CheckBoxProperties.cpp
|   |   |   |   |   |   +---ColorDialog.cpp
|   |   |   |   |   |   +---ComboBoxProperties.cpp
|   |   |   |   |   |   +---GenericProperties.cpp
|   |   |   |   |   |   +---GridSettings.cpp
|   |   |   |   |   |   +---ListboxProperties.cpp
|   |   |   |   |   |   +---NewLayoutDialog.cpp
|   |   |   |   |   |   +---ProgressBarProperties.cpp
|   |   |   |   |   |   +---PushButtonProperties.cpp
|   |   |   |   |   |   +---RadioButtonProperties.cpp
|   |   |   |   |   |   +---SliderProperties.cpp
|   |   |   |   |   |   +---StaticTextProperties.cpp
|   |   |   |   |   |   +---TabControlProperties.cpp
|   |   |   |   |   |   `---TextEntryProperties.cpp
|   |   |   |   |   +---EditWindow.cpp
|   |   |   |   |   +---GUIEdit.cpp
|   |   |   |   |   +---GUIEditDisplay.cpp
|   |   |   |   |   +---GUIEditWindowManager.cpp
|   |   |   |   |   +---HierarchyView.cpp
|   |   |   |   |   +---LayoutScheme.cpp
|   |   |   |   |   +---Properties.cpp
|   |   |   |   |   +---Save.cpp
|   |   |   |   |   `---WinMain.cpp
|   |   |   |   `---GUIEdit.dsp
|   |   |   +---ImagePacker
|   |   |   |   +---Include
|   |   |   |   |   +---ImageDirectory.h
|   |   |   |   |   +---ImageInfo.h
|   |   |   |   |   +---ImagePacker.h
|   |   |   |   |   +---TexturePage.h
|   |   |   |   |   +---WindowProc.h
|   |   |   |   |   `---WinMain.h
|   |   |   |   +---Resource
|   |   |   |   |   +---ImagePacker.rc
|   |   |   |   |   `---Resource.h
|   |   |   |   +---Source
|   |   |   |   |   +---Window Procedures
|   |   |   |   |   |   +---DirectorySelect.cpp
|   |   |   |   |   |   +---ImageErrorProc.cpp
|   |   |   |   |   |   +---ImagePackerProc.cpp
|   |   |   |   |   |   +---PageErrorProc.cpp
|   |   |   |   |   |   `---PreviewProc.cpp
|   |   |   |   |   +---ImageInfo.cpp
|   |   |   |   |   +---ImagePacker.cpp
|   |   |   |   |   +---TexturePage.cpp
|   |   |   |   |   `---WinMain.cpp
|   |   |   |   `---ImagePacker.dsp
|   |   |   +---Launcher
|   |   |   |   +---DatGen
|   |   |   |   |   +---DatGen.cpp
|   |   |   |   |   `---DatGen.dsp
|   |   |   |   +---SafeDisk
|   |   |   |   |   `---.gitignore
|   |   |   |   +---Toolkit
|   |   |   |   |   +---Debug
|   |   |   |   |   |   +---DebugPrint.cpp
|   |   |   |   |   |   `---DebugPrint.h
|   |   |   |   |   +---Storage
|   |   |   |   |   |   +---File.cpp
|   |   |   |   |   |   +---File.h
|   |   |   |   |   |   +---Rights.h
|   |   |   |   |   |   `---Stream.h
|   |   |   |   |   `---Support
|   |   |   |   |       +---RefCounted.h
|   |   |   |   |       +---RefPtr.h
|   |   |   |   |       +---StringConvert.cpp
|   |   |   |   |       +---StringConvert.h
|   |   |   |   |       +---UString.cpp
|   |   |   |   |       +---UString.h
|   |   |   |   |       +---UTypes.h
|   |   |   |   |       `---Visualc.h
|   |   |   |   +---BFISH.CPP
|   |   |   |   +---BFISH.H
|   |   |   |   +---configfile.cpp
|   |   |   |   +---configfile.h
|   |   |   |   +---dialog.cpp
|   |   |   |   +---dialog.h
|   |   |   |   +---dictionary.h
|   |   |   |   +---filed.h
|   |   |   |   +---findpatch.cpp
|   |   |   |   +---findpatch.h
|   |   |   |   +---Generals.ico
|   |   |   |   +---launcher.dsp
|   |   |   |   +---launcher1.rc
|   |   |   |   +---loadbmp.cpp
|   |   |   |   +---loadbmp.h
|   |   |   |   +---main.cpp
|   |   |   |   +---monod.cpp
|   |   |   |   +---monod.h
|   |   |   |   +---odevice.h
|   |   |   |   +---patch.cpp
|   |   |   |   +---patch.h
|   |   |   |   +---process.cpp
|   |   |   |   +---process.h
|   |   |   |   +---Protect.cpp
|   |   |   |   +---Protect.h
|   |   |   |   +---resource.h
|   |   |   |   +---streamer.cpp
|   |   |   |   +---streamer.h
|   |   |   |   +---wdebug.cpp
|   |   |   |   +---wdebug.h
|   |   |   |   +---winblows.cpp
|   |   |   |   +---winblows.h
|   |   |   |   +---wstring.cpp
|   |   |   |   +---wstring.h
|   |   |   |   `---wstypes.h
|   |   |   +---mangler
|   |   |   |   +---wlib
|   |   |   |   |   +---arraylist.h
|   |   |   |   |   +---configfile.cpp
|   |   |   |   |   +---configfile.h
|   |   |   |   |   +---critsec.cpp
|   |   |   |   |   +---critsec.h
|   |   |   |   |   +---dictionary.h
|   |   |   |   |   +---filed.h
|   |   |   |   |   +---linkedlist.h
|   |   |   |   |   +---Makefile
|   |   |   |   |   +---mboxd.h
|   |   |   |   |   +---monod.cpp
|   |   |   |   |   +---monod.h
|   |   |   |   |   +---odevice.h
|   |   |   |   |   +---sem4.cpp
|   |   |   |   |   +---sem4.h
|   |   |   |   |   +---stderrd.h
|   |   |   |   |   +---stdoutd.h
|   |   |   |   |   +---streamer.cpp
|   |   |   |   |   +---streamer.h
|   |   |   |   |   +---syslogd.cpp
|   |   |   |   |   +---syslogd.h
|   |   |   |   |   +---threadfac.cpp
|   |   |   |   |   +---threadfac.h
|   |   |   |   |   +---threadsafe.h
|   |   |   |   |   +---timezone.cpp
|   |   |   |   |   +---timezone.h
|   |   |   |   |   +---ustring.h
|   |   |   |   |   +---wdebug.cpp
|   |   |   |   |   +---wdebug.h
|   |   |   |   |   +---wstring.cpp
|   |   |   |   |   +---wstring.h
|   |   |   |   |   +---wstypes.h
|   |   |   |   |   +---wtime.cpp
|   |   |   |   |   +---wtime.h
|   |   |   |   |   +---xtime.cpp
|   |   |   |   |   `---xtime.h
|   |   |   |   +---wnet
|   |   |   |   |   +---field.cpp
|   |   |   |   |   +---field.h
|   |   |   |   |   +---Makefile
|   |   |   |   |   +---packet.cpp
|   |   |   |   |   +---packet.h
|   |   |   |   |   +---tcp.cpp
|   |   |   |   |   +---tcp.h
|   |   |   |   |   +---udp.cpp
|   |   |   |   |   `---udp.h
|   |   |   |   +---crc.cpp
|   |   |   |   +---crc.h
|   |   |   |   +---endian.h
|   |   |   |   +---Makefile
|   |   |   |   +---mangler.cpp
|   |   |   |   +---mangler.dsp
|   |   |   |   +---mangler.dsw
|   |   |   |   +---mangler.h
|   |   |   |   +---manglertest.cpp
|   |   |   |   `---manglertest.dsp
|   |   |   +---MapCacheBuilder
|   |   |   |   +---Include
|   |   |   |   |   `---WinMain.h
|   |   |   |   +---Resource
|   |   |   |   |   +---MapCacheBuilder.rc
|   |   |   |   |   `---Resource.h
|   |   |   |   +---Source
|   |   |   |   |   `---WinMain.cpp
|   |   |   |   `---MapCacheBuilder.dsp
|   |   |   +---matchbot
|   |   |   |   +---wlib
|   |   |   |   |   +---arraylist.h
|   |   |   |   |   +---configfile.cpp
|   |   |   |   |   +---configfile.h
|   |   |   |   |   +---critsec.cpp
|   |   |   |   |   +---critsec.h
|   |   |   |   |   +---dictionary.h
|   |   |   |   |   +---filed.h
|   |   |   |   |   +---linkedlist.h
|   |   |   |   |   +---mboxd.h
|   |   |   |   |   +---monod.cpp
|   |   |   |   |   +---monod.h
|   |   |   |   |   +---odevice.h
|   |   |   |   |   +---sem4.cpp
|   |   |   |   |   +---sem4.h
|   |   |   |   |   +---stderrd.h
|   |   |   |   |   +---stdoutd.h
|   |   |   |   |   +---streamer.cpp
|   |   |   |   |   +---streamer.h
|   |   |   |   |   +---syslogd.cpp
|   |   |   |   |   +---syslogd.h
|   |   |   |   |   +---threadfac.cpp
|   |   |   |   |   +---threadfac.h
|   |   |   |   |   +---threadsafe.h
|   |   |   |   |   +---timezone.cpp
|   |   |   |   |   +---timezone.h
|   |   |   |   |   +---ustring.h
|   |   |   |   |   +---wdebug.cpp
|   |   |   |   |   +---wdebug.h
|   |   |   |   |   +---wstring.cpp
|   |   |   |   |   +---wstring.h
|   |   |   |   |   +---wstypes.h
|   |   |   |   |   +---wtime.cpp
|   |   |   |   |   +---wtime.h
|   |   |   |   |   +---xtime.cpp
|   |   |   |   |   `---xtime.h
|   |   |   |   +---wnet
|   |   |   |   |   +---field.cpp
|   |   |   |   |   +---field.h
|   |   |   |   |   +---packet.cpp
|   |   |   |   |   +---packet.h
|   |   |   |   |   +---tcp.cpp
|   |   |   |   |   +---tcp.h
|   |   |   |   |   +---udp.cpp
|   |   |   |   |   `---udp.h
|   |   |   |   +---debug.cpp
|   |   |   |   +---debug.h
|   |   |   |   +---encrypt.cpp
|   |   |   |   +---encrypt.h
|   |   |   |   +---generals.cpp
|   |   |   |   +---generals.h
|   |   |   |   +---global.cpp
|   |   |   |   +---global.h
|   |   |   |   +---main.cpp
|   |   |   |   +---matcher.cpp
|   |   |   |   +---matcher.h
|   |   |   |   +---mydebug.cpp
|   |   |   |   +---mydebug.h
|   |   |   |   +---rand.cpp
|   |   |   |   `---rand.h
|   |   |   +---NVASM
|   |   |   |   `---.gitignore
|   |   |   +---ParticleEditor
|   |   |   |   +---res
|   |   |   |   |   `---ParticleEditor.rc2
|   |   |   |   +---CButtonShowColor.cpp
|   |   |   |   +---CButtonShowColor.h
|   |   |   |   +---CColorAlphaDialog.cpp
|   |   |   |   +---CColorAlphaDialog.h
|   |   |   |   +---CParticleEditorPage.h
|   |   |   |   +---CSwitchesDialog.cpp
|   |   |   |   +---CSwitchesDialog.h
|   |   |   |   +---EmissionTypePanels.cpp
|   |   |   |   +---EmissionTypePanels.h
|   |   |   |   +---ISwapablePanel.h
|   |   |   |   +---MoreParmsDialog.cpp
|   |   |   |   +---MoreParmsDialog.h
|   |   |   |   +---ParticleEditor.cpp
|   |   |   |   +---ParticleEditor.def
|   |   |   |   +---ParticleEditor.dsp
|   |   |   |   +---ParticleEditor.dsw
|   |   |   |   +---ParticleEditor.h
|   |   |   |   +---ParticleEditor.rc
|   |   |   |   +---ParticleEditorDialog.cpp
|   |   |   |   +---ParticleEditorDialog.h
|   |   |   |   +---ParticleEditorExport.h
|   |   |   |   +---ParticleTypePanels.cpp
|   |   |   |   +---ParticleTypePanels.h
|   |   |   |   +---post-build-Release.bat
|   |   |   |   +---post-build.bat
|   |   |   |   +---Resource.h
|   |   |   |   +---ShaderTypePanels.cpp
|   |   |   |   +---ShaderTypePanels.h
|   |   |   |   +---StdAfx.cpp
|   |   |   |   +---StdAfx.h
|   |   |   |   +---VelocityTypePanels.cpp
|   |   |   |   `---VelocityTypePanels.h
|   |   |   +---PATCHGET
|   |   |   |   +---CHATAPI.CPP
|   |   |   |   +---CHATAPI.H
|   |   |   |   +---COMINIT.CPP
|   |   |   |   +---COMINIT.H
|   |   |   |   +---debug.cpp
|   |   |   |   +---debug.h
|   |   |   |   +---DownloadManager.cpp
|   |   |   |   +---DownloadManager.h
|   |   |   |   +---Generals.ico
|   |   |   |   +---patchgrabber.dsp
|   |   |   |   +---PROCESS.CPP
|   |   |   |   +---PROCESS.H
|   |   |   |   +---registry.cpp
|   |   |   |   +---Registry.h
|   |   |   |   +---RESOURCE.H
|   |   |   |   +---SCRIPT1.RC
|   |   |   |   +---WINBLOWS.CPP
|   |   |   |   +---WINBLOWS.H
|   |   |   |   `---WSTYPES.H
|   |   |   +---textureCompress
|   |   |   |   +---resource.h
|   |   |   |   +---textureCompress.cpp
|   |   |   |   +---textureCompress.dsp
|   |   |   |   +---textureCompress.dsw
|   |   |   |   `---textureCompress.rc
|   |   |   +---timingTest
|   |   |   |   +---StdAfx.cpp
|   |   |   |   +---StdAfx.h
|   |   |   |   +---timingTest.cpp
|   |   |   |   +---timingTest.dsp
|   |   |   |   `---timingTest.dsw
|   |   |   +---versionUpdate
|   |   |   |   +---versionUpdate.cpp
|   |   |   |   `---versionUpdate.dsp
|   |   |   +---wolSetup
|   |   |   |   +---WOLAPI
|   |   |   |   |   +---chatdefs.h
|   |   |   |   |   +---downloaddefs.h
|   |   |   |   |   +---ftpdefs.h
|   |   |   |   |   +---netutildefs.h
|   |   |   |   |   +---wolapi_i.c
|   |   |   |   |   +---wolapi.dll
|   |   |   |   |   +---wolapi.h
|   |   |   |   |   `---woldbg.dll
|   |   |   |   +---makedist.bat
|   |   |   |   +---resource.h
|   |   |   |   +---small.ico
|   |   |   |   +---StdAfx.cpp
|   |   |   |   +---StdAfx.h
|   |   |   |   +---verchk.cpp
|   |   |   |   +---verchk.h
|   |   |   |   +---wolInit.cpp
|   |   |   |   +---wolSetup.cpp
|   |   |   |   +---wolSetup.dsp
|   |   |   |   +---wolSetup.dsw
|   |   |   |   +---wolSetup.h
|   |   |   |   +---wolSetup.ico
|   |   |   |   `---wolSetup.rc
|   |   |   +---WorldBuilder
|   |   |   |   +---include
|   |   |   |   |   +---addplayerdialog.h
|   |   |   |   |   +---AutoEdgeOutTool.h
|   |   |   |   |   +---BaseBuildProps.h
|   |   |   |   |   +---BlendEdgeTool.h
|   |   |   |   |   +---BlendMaterial.h
|   |   |   |   |   +---BorderTool.h
|   |   |   |   |   +---brushoptions.h
|   |   |   |   |   +---BrushTool.h
|   |   |   |   |   +---BuildList.h
|   |   |   |   |   +---BuildListTool.h
|   |   |   |   |   +---CameraOptions.h
|   |   |   |   |   +---CellWidth.h
|   |   |   |   |   +---CFixTeamOwnerDialog.h
|   |   |   |   |   +---ContourOptions.h
|   |   |   |   |   +---CUndoable.h
|   |   |   |   |   +---DrawObject.h
|   |   |   |   |   +---EditAction.h
|   |   |   |   |   +---EditCondition.h
|   |   |   |   |   +---EditCoordParameter.h
|   |   |   |   |   +---EditGroup.h
|   |   |   |   |   +---EditObjectParameter.h
|   |   |   |   |   +---EditParameter.h
|   |   |   |   |   +---euladialog.h
|   |   |   |   |   +---ExportScriptsOptions.h
|   |   |   |   |   +---EyedropperTool.h
|   |   |   |   |   +---FeatherOptions.h
|   |   |   |   |   +---FeatherTool.h
|   |   |   |   |   +---FenceOptions.h
|   |   |   |   |   +---FenceTool.h
|   |   |   |   |   +---FloodFillTool.h
|   |   |   |   |   +---GlobalLightOptions.h
|   |   |   |   |   +---GroveOptions.h
|   |   |   |   |   +---GroveTool.h
|   |   |   |   |   +---HandScrollTool.h
|   |   |   |   |   +---ImpassableOptions.h
|   |   |   |   |   +---LayersList.h
|   |   |   |   |   +---LightOptions.h
|   |   |   |   |   +---MainFrm.h
|   |   |   |   |   +---mapobjectprops.h
|   |   |   |   |   +---MapPreview.h
|   |   |   |   |   +---MapSettings.h
|   |   |   |   |   +---MeshMoldOptions.h
|   |   |   |   |   +---MeshMoldTool.h
|   |   |   |   |   +---MoundOptions.h
|   |   |   |   |   +---MoundTool.h
|   |   |   |   |   +---MyToolbar.h
|   |   |   |   |   +---NewHeightMap.h
|   |   |   |   |   +---ObjectOptions.h
|   |   |   |   |   +---ObjectPreview.h
|   |   |   |   |   +---ObjectTool.h
|   |   |   |   |   +---OpenMap.h
|   |   |   |   |   +---OptionsPanel.h
|   |   |   |   |   +---PickUnitDialog.h
|   |   |   |   |   +---playerlistdlg.h
|   |   |   |   |   +---PointerTool.h
|   |   |   |   |   +---PolygonTool.h
|   |   |   |   |   +---propedit.h
|   |   |   |   |   +---RampOptions.h
|   |   |   |   |   +---RampTool.h
|   |   |   |   |   +---RoadOptions.h
|   |   |   |   |   +---RoadTool.h
|   |   |   |   |   +---SaveMap.h
|   |   |   |   |   +---ScorchOptions.h
|   |   |   |   |   +---ScorchTool.h
|   |   |   |   |   +---ScriptActionsFalse.h
|   |   |   |   |   +---ScriptActionsTrue.h
|   |   |   |   |   +---ScriptConditions.h
|   |   |   |   |   +---ScriptDialog.h
|   |   |   |   |   +---ScriptProperties.h
|   |   |   |   |   +---SelectMacrotexture.h
|   |   |   |   |   +---ShadowOptions.h
|   |   |   |   |   +---SplashScreen.h
|   |   |   |   |   +---StdAfx.h
|   |   |   |   |   +---TeamBehavior.h
|   |   |   |   |   +---TeamGeneric.h
|   |   |   |   |   +---TeamIdentity.h
|   |   |   |   |   +---TeamReinforcement.h
|   |   |   |   |   +---teamsdialog.h
|   |   |   |   |   +---TerrainMaterial.h
|   |   |   |   |   +---TerrainModal.h
|   |   |   |   |   +---TerrainSwatches.h
|   |   |   |   |   +---TileTool.h
|   |   |   |   |   +---Tool.h
|   |   |   |   |   +---WaterOptions.h
|   |   |   |   |   +---WaterTool.h
|   |   |   |   |   +---WaypointOptions.h
|   |   |   |   |   +---WaypointTool.h
|   |   |   |   |   +---WBFrameWnd.h
|   |   |   |   |   +---WBHeightMap.h
|   |   |   |   |   +---WBPopupSlider.h
|   |   |   |   |   +---wbview.h
|   |   |   |   |   +---wbview3d.h
|   |   |   |   |   +---WHeightMapEdit.h
|   |   |   |   |   +---WorldBuilder.h
|   |   |   |   |   +---WorldBuilderDoc.h
|   |   |   |   |   `---WorldBuilderView.h
|   |   |   |   +---res
|   |   |   |   |   +---cross.cur
|   |   |   |   |   +---folder.bmp
|   |   |   |   |   +---foldersc.bmp
|   |   |   |   |   +---IDB_DownArrow.bmp
|   |   |   |   |   +---IDB_ROAD_CORNERS.bmp
|   |   |   |   |   +---IDC_AUTO_EDGE_OUT.cur
|   |   |   |   |   +---IDC_BLEND_EDGE.cur
|   |   |   |   |   +---IDC_BUILD_LIST_TOOL.cur
|   |   |   |   |   +---IDC_BUILD_MOVE.cur
|   |   |   |   |   +---IDC_BUILD_POINTER.cur
|   |   |   |   |   +---IDC_BUILD_ROTATE.cur
|   |   |   |   |   +---IDC_CLIFF.cur
|   |   |   |   |   +---IDC_EYEDROPPER.cur
|   |   |   |   |   +---IDC_FENCE.cur
|   |   |   |   |   +---IDC_FLOOD_FILL.cur
|   |   |   |   |   +---IDC_GROVE.cur
|   |   |   |   |   +---IDC_HAND_SCROLL.cur
|   |   |   |   |   +---IDC_MOLD_POINTER.cur
|   |   |   |   |   +---IDC_MOVE_POINTER.cur
|   |   |   |   |   +---IDC_PLACE_OBJECT.cur
|   |   |   |   |   +---IDC_POINTER.cur
|   |   |   |   |   +---IDC_POLYGON_MOVE.cur
|   |   |   |   |   +---IDC_POLYGON_PLUS.cur
|   |   |   |   |   +---IDC_POLYGON.cur
|   |   |   |   |   +---IDC_RAMP.cur
|   |   |   |   |   +---IDC_ROAD.cur
|   |   |   |   |   +---IDC_ROTATE.cur
|   |   |   |   |   +---IDC_Scorch.cur
|   |   |   |   |   +---IDC_WATER_MOVE.cur
|   |   |   |   |   +---IDC_WATER_PLUS.cur
|   |   |   |   |   +---IDC_WATER.cur
|   |   |   |   |   +---IDC_WAYPOINT.cur
|   |   |   |   |   +---IDI_Hide.ico
|   |   |   |   |   +---IDI_Show.ico
|   |   |   |   |   +---IDI_Thumb.ico
|   |   |   |   |   +---resource.h
|   |   |   |   |   +---TileTool.cur
|   |   |   |   |   +---Toolbar.bmp
|   |   |   |   |   +---toolbar1.bmp
|   |   |   |   |   +---toolbar2.bmp
|   |   |   |   |   +---WorldBuilder.bmp
|   |   |   |   |   +---WorldBuilder.ico
|   |   |   |   |   +---WorldBuilder.rc
|   |   |   |   |   +---WorldBuilder.rc2
|   |   |   |   |   `---WorldBuilderDoc.ico
|   |   |   |   +---src
|   |   |   |   |   +---addplayerdialog.cpp
|   |   |   |   |   +---AutoEdgeOutTool.cpp
|   |   |   |   |   +---BaseBuildProps.cpp
|   |   |   |   |   +---BlendEdgeTool.cpp
|   |   |   |   |   +---BlendMaterial.cpp
|   |   |   |   |   +---BorderTool.cpp
|   |   |   |   |   +---brushoptions.cpp
|   |   |   |   |   +---BrushTool.cpp
|   |   |   |   |   +---BuildList.cpp
|   |   |   |   |   +---BuildListTool.cpp
|   |   |   |   |   +---CameraOptions.cpp
|   |   |   |   |   +---CButtonShowColor.cpp
|   |   |   |   |   +---CButtonShowColor.h
|   |   |   |   |   +---CellWidth.cpp
|   |   |   |   |   +---CFixTeamOwnerDialog.cpp
|   |   |   |   |   +---ContourOptions.cpp
|   |   |   |   |   +---CUndoable.cpp
|   |   |   |   |   +---DrawObject.cpp
|   |   |   |   |   +---EditAction.cpp
|   |   |   |   |   +---EditCondition.cpp
|   |   |   |   |   +---EditCoordParameter.cpp
|   |   |   |   |   +---EditGroup.cpp
|   |   |   |   |   +---EditObjectParameter.cpp
|   |   |   |   |   +---EditParameter.cpp
|   |   |   |   |   +---EulaDialog.cpp
|   |   |   |   |   +---ExportScriptsOptions.cpp
|   |   |   |   |   +---EyedropperTool.cpp
|   |   |   |   |   +---FeatherOptions.cpp
|   |   |   |   |   +---FeatherTool.cpp
|   |   |   |   |   +---FenceOptions.cpp
|   |   |   |   |   +---FenceTool.cpp
|   |   |   |   |   +---FloodFillTool.cpp
|   |   |   |   |   +---GlobalLightOptions.cpp
|   |   |   |   |   +---GroveOptions.cpp
|   |   |   |   |   +---GroveTool.cpp
|   |   |   |   |   +---HandScrollTool.cpp
|   |   |   |   |   +---ImpassableOptions.cpp
|   |   |   |   |   +---LayersList.cpp
|   |   |   |   |   +---LightOptions.cpp
|   |   |   |   |   +---MainFrm.cpp
|   |   |   |   |   +---mapobjectprops.cpp
|   |   |   |   |   +---MapPreview.cpp
|   |   |   |   |   +---MapSettings.cpp
|   |   |   |   |   +---MeshMoldOptions.cpp
|   |   |   |   |   +---MeshMoldTool.cpp
|   |   |   |   |   +---MoundOptions.cpp
|   |   |   |   |   +---MoundTool.cpp
|   |   |   |   |   +---MyToolbar.cpp
|   |   |   |   |   +---NewHeightMap.cpp
|   |   |   |   |   +---ObjectOptions.cpp
|   |   |   |   |   +---ObjectPreview.cpp
|   |   |   |   |   +---ObjectTool.cpp
|   |   |   |   |   +---OpenMap.cpp
|   |   |   |   |   +---OptionsPanel.cpp
|   |   |   |   |   +---PickUnitDialog.cpp
|   |   |   |   |   +---playerlistdlg.cpp
|   |   |   |   |   +---PointerTool.cpp
|   |   |   |   |   +---PolygonTool.cpp
|   |   |   |   |   +---propedit.cpp
|   |   |   |   |   +---RampOptions.cpp
|   |   |   |   |   +---RampTool.cpp
|   |   |   |   |   +---RoadOptions.cpp
|   |   |   |   |   +---RoadTool.cpp
|   |   |   |   |   +---SaveMap.cpp
|   |   |   |   |   +---ScorchOptions.cpp
|   |   |   |   |   +---ScorchTool.cpp
|   |   |   |   |   +---ScriptActionsFalse.cpp
|   |   |   |   |   +---ScriptActionsTrue.cpp
|   |   |   |   |   +---ScriptConditions.cpp
|   |   |   |   |   +---ScriptDialog.cpp
|   |   |   |   |   +---ScriptProperties.cpp
|   |   |   |   |   +---SelectMacrotexture.cpp
|   |   |   |   |   +---ShadowOptions.cpp
|   |   |   |   |   +---SplashScreen.cpp
|   |   |   |   |   +---StdAfx.cpp
|   |   |   |   |   +---TeamBehavior.cpp
|   |   |   |   |   +---TeamGeneric.cpp
|   |   |   |   |   +---TeamIdentity.cpp
|   |   |   |   |   +---TeamReinforcement.cpp
|   |   |   |   |   +---teamsdialog.cpp
|   |   |   |   |   +---TerrainMaterial.cpp
|   |   |   |   |   +---TerrainModal.cpp
|   |   |   |   |   +---TerrainSwatches.cpp
|   |   |   |   |   +---TileTool.cpp
|   |   |   |   |   +---Tool.cpp
|   |   |   |   |   +---WaterOptions.cpp
|   |   |   |   |   +---WaterTool.cpp
|   |   |   |   |   +---WaypointOptions.cpp
|   |   |   |   |   +---WaypointTool.cpp
|   |   |   |   |   +---WBFrameWnd.cpp
|   |   |   |   |   +---WBHeightMap.cpp
|   |   |   |   |   +---WBPopupSlider.cpp
|   |   |   |   |   +---wbview.cpp
|   |   |   |   |   +---wbview3d.cpp
|   |   |   |   |   +---WHeightMapEdit.cpp
|   |   |   |   |   +---WorldBuilder.cpp
|   |   |   |   |   +---WorldBuilderDoc.cpp
|   |   |   |   |   `---WorldBuilderView.cpp
|   |   |   |   `---WorldBuilder.dsp
|   |   |   `---WW3D
|   |   |       +---max2w3d
|   |   |       |   +---Res
|   |   |       |   |   +---DISK12.ICO
|   |   |       |   |   +---one.bmp
|   |   |       |   |   +---orig.ico
|   |   |       |   |   +---orig1.ico
|   |   |       |   |   +---two.bmp
|   |   |       |   |   `---ww3d.bmp
|   |   |       |   +---aabtreebuilder.cpp
|   |   |       |   +---aabtreebuilder.h
|   |   |       |   +---AlphaModifier.cpp
|   |   |       |   +---AlphaModifier.h
|   |   |       |   +---animationcompressionsettings.cpp
|   |   |       |   +---animationcompressionsettings.h
|   |   |       |   +---AppData.cpp
|   |   |       |   +---bchannel.cpp
|   |   |       |   +---bchannel.h
|   |   |       |   +---boneicon.cpp
|   |   |       |   +---boneicon.h
|   |   |       |   +---bpick.cpp
|   |   |       |   +---bpick.h
|   |   |       |   +---changes.txt
|   |   |       |   +---colboxsave.cpp
|   |   |       |   +---colboxsave.h
|   |   |       |   +---dazzlesave.cpp
|   |   |       |   +---dazzlesave.h
|   |   |       |   +---dllmain.cpp
|   |   |       |   +---dllmain.h
|   |   |       |   +---ExportAll.cpp
|   |   |       |   +---ExportAllDlg.cpp
|   |   |       |   +---ExportAllDlg.h
|   |   |       |   +---exportlog.cpp
|   |   |       |   +---exportlog.h
|   |   |       |   +---floaterdialog.cpp
|   |   |       |   +---floaterdialog.h
|   |   |       |   +---FormClass.cpp
|   |   |       |   +---FormClass.h
|   |   |       |   +---gamemaps.cpp
|   |   |       |   +---gamemaps.h
|   |   |       |   +---GameMtl.cpp
|   |   |       |   +---gamemtl.h
|   |   |       |   +---GameMtlDlg.cpp
|   |   |       |   +---GameMtlDlg.h
|   |   |       |   +---GameMtlForm.cpp
|   |   |       |   +---GameMtlForm.h
|   |   |       |   +---GameMtlPassDlg.cpp
|   |   |       |   +---GameMtlPassDlg.h
|   |   |       |   +---GameMtlShaderDlg.cpp
|   |   |       |   +---GameMtlShaderDlg.h
|   |   |       |   +---GameMtlTextureDlg.cpp
|   |   |       |   +---GameMtlTextureDlg.h
|   |   |       |   +---GameMtlVertexMaterialDlg.cpp
|   |   |       |   +---GameMtlVertexMaterialDlg.h
|   |   |       |   +---genlodextensiondialog.cpp
|   |   |       |   +---genlodextensiondialog.h
|   |   |       |   +---genmtlnamesdialog.cpp
|   |   |       |   +---genmtlnamesdialog.h
|   |   |       |   +---gennamesdialog.cpp
|   |   |       |   +---gennamesdialog.h
|   |   |       |   +---geometryexportcontext.h
|   |   |       |   +---geometryexporttask.cpp
|   |   |       |   +---geometryexporttask.h
|   |   |       |   +---gmtldlg.cpp
|   |   |       |   +---gridsnapmodifier.cpp
|   |   |       |   +---gridsnapmodifier.h
|   |   |       |   +---hiersave.cpp
|   |   |       |   +---hiersave.h
|   |   |       |   +---hlodsave.cpp
|   |   |       |   +---hlodsave.h
|   |   |       |   +---InputDlg.cpp
|   |   |       |   +---InputDlg.h
|   |   |       |   +---LightGlareSave.cpp
|   |   |       |   +---LightGlareSave.h
|   |   |       |   +---logdlg.cpp
|   |   |       |   +---logdlg.h
|   |   |       |   +---max2w3d.def
|   |   |       |   +---max2w3d.dsp
|   |   |       |   +---max2w3d.dsw
|   |   |       |   +---max2w3d.rc
|   |   |       |   +---maxworldinfo.cpp
|   |   |       |   +---maxworldinfo.h
|   |   |       |   +---meshbuild.cpp
|   |   |       |   +---meshbuild.h
|   |   |       |   +---meshcon.cpp
|   |   |       |   +---meshcon.h
|   |   |       |   +---MeshDeform.cpp
|   |   |       |   +---MeshDeform.h
|   |   |       |   +---MeshDeformData.cpp
|   |   |       |   +---MeshDeformData.h
|   |   |       |   +---MeshDeformDefs.h
|   |   |       |   +---MeshDeformPanel.cpp
|   |   |       |   +---MeshDeformPanel.h
|   |   |       |   +---MeshDeformSave.cpp
|   |   |       |   +---MeshDeformSave.h
|   |   |       |   +---MeshDeformSaveDefs.h
|   |   |       |   +---MeshDeformSaveSet.cpp
|   |   |       |   +---MeshDeformSaveSet.h
|   |   |       |   +---MeshDeformSet.cpp
|   |   |       |   +---MeshDeformSet.h
|   |   |       |   +---MeshDeformUndo.cpp
|   |   |       |   +---MeshDeformUndo.h
|   |   |       |   +---meshsave.cpp
|   |   |       |   +---meshsave.h
|   |   |       |   +---motion.cpp
|   |   |       |   +---motion.h
|   |   |       |   +---namedsel.cpp
|   |   |       |   +---namedsel.h
|   |   |       |   +---nullsave.cpp
|   |   |       |   +---nullsave.h
|   |   |       |   +---PCToPS2Material.cpp
|   |   |       |   +---presetexportoptionsdialog.cpp
|   |   |       |   +---presetexportoptionsdialog.h
|   |   |       |   +---PS2GameMtl.cpp
|   |   |       |   +---PS2GameMtlShaderDlg.cpp
|   |   |       |   +---PS2GameMtlShaderDlg.h
|   |   |       |   +---rcmenu.cpp
|   |   |       |   +---rcmenu.h
|   |   |       |   +---resource.h
|   |   |       |   +---SceneSetup.cpp
|   |   |       |   +---SceneSetupDlg.cpp
|   |   |       |   +---SceneSetupDlg.h
|   |   |       |   +---simpdib.cpp
|   |   |       |   +---simpdib.h
|   |   |       |   +---skin.cpp
|   |   |       |   +---skin.h
|   |   |       |   +---SkinCopy.cpp
|   |   |       |   +---skindata.cpp
|   |   |       |   +---skindata.h
|   |   |       |   +---SnapPoints.cpp
|   |   |       |   +---SnapPoints.h
|   |   |       |   +---TARGA.CPP
|   |   |       |   +---TARGA.H
|   |   |       |   +---util.cpp
|   |   |       |   +---util.h
|   |   |       |   +---Utility.cpp
|   |   |       |   +---vchannel.cpp
|   |   |       |   +---vchannel.h
|   |   |       |   +---vxl.cpp
|   |   |       |   +---vxl.h
|   |   |       |   +---vxldbg.cpp
|   |   |       |   +---vxldbg.h
|   |   |       |   +---vxllayer.cpp
|   |   |       |   +---vxllayer.h
|   |   |       |   +---w3d_file.h
|   |   |       |   +---w3d_obsolete.h
|   |   |       |   +---w3dappdata.cpp
|   |   |       |   +---w3dappdata.h
|   |   |       |   +---w3ddesc.cpp
|   |   |       |   +---w3ddesc.h
|   |   |       |   +---w3ddlg.cpp
|   |   |       |   +---w3ddlg.h
|   |   |       |   +---w3dexp.cpp
|   |   |       |   +---w3dexp.h
|   |   |       |   +---w3dmtl.cpp
|   |   |       |   +---w3dmtl.h
|   |   |       |   +---w3dutil.cpp
|   |   |       |   `---w3dutil.h
|   |   |       `---pluglib
|   |   |           +---aaplane.h
|   |   |           +---always.h
|   |   |           +---BITTYPE.H
|   |   |           +---bool.h
|   |   |           +---borlandc.h
|   |   |           +---chunkio.cpp
|   |   |           +---chunkio.h
|   |   |           +---errclass.h
|   |   |           +---EULER.CPP
|   |   |           +---EULER.H
|   |   |           +---hashcalc.h
|   |   |           +---hsv.cpp
|   |   |           +---hsv.h
|   |   |           +---iostruct.h
|   |   |           +---jshell.cpp
|   |   |           +---matrix3d.cpp
|   |   |           +---matrix3d.h
|   |   |           +---matrix4.cpp
|   |   |           +---matrix4.h
|   |   |           +---nodefilt.cpp
|   |   |           +---nodefilt.h
|   |   |           +---nodelist.cpp
|   |   |           +---nodelist.h
|   |   |           +---noinit.h
|   |   |           +---palette.cpp
|   |   |           +---palette.h
|   |   |           +---plane.h
|   |   |           +---pluglib.dsp
|   |   |           +---PROGRESS.H
|   |   |           +---rawfile.cpp
|   |   |           +---rawfile.h
|   |   |           +---realcrc.cpp
|   |   |           +---realcrc.h
|   |   |           +---rgb.cpp
|   |   |           +---rgb.h
|   |   |           +---uarray.h
|   |   |           +---Vector.CPP
|   |   |           +---Vector.H
|   |   |           +---vector2.h
|   |   |           +---vector3.h
|   |   |           +---vector3i.h
|   |   |           +---vector4.h
|   |   |           +---visualc.h
|   |   |           +---w3d_file.h
|   |   |           +---w3dquat.cpp
|   |   |           +---w3dquat.h
|   |   |           +---watcom.h
|   |   |           +---win.h
|   |   |           +---wwfile.h
|   |   |           +---wwmath.cpp
|   |   |           +---wwmath.h
|   |   |           +---WWmatrix3.cpp
|   |   |           `---WWmatrix3.h
|   |   +---RTS.dsp
|   |   `---RTS.dsw
|   +---Run
|   |   +---BrowserEngine.dll
|   |   `---place_steam_build_here.txt
|   `---.gitignore
+---GeneralsMD
|   +---Code
|   |   +---GameEngine
|   |   |   +---Include
|   |   |   |   +---AI
|   |   |   |   |   `---FlowField.h
|   |   |   |   +---Common
|   |   |   |   |   +---SafeDisc
|   |   |   |   |   |   `---.gitignore
|   |   |   |   |   +---AcademyStats.h
|   |   |   |   |   +---ActionManager.h
|   |   |   |   |   +---ArchiveFile.h
|   |   |   |   |   +---ArchiveFileSystem.h
|   |   |   |   |   +---AsciiString.h
|   |   |   |   |   +---AudioAffect.h
|   |   |   |   |   +---AudioEventInfo.h
|   |   |   |   |   +---AudioEventRTS.h
|   |   |   |   |   +---AudioHandleSpecialValues.h
|   |   |   |   |   +---AudioRandomValue.h
|   |   |   |   |   +---AudioRequest.h
|   |   |   |   |   +---AudioSettings.h
|   |   |   |   |   +---BattleHonors.h
|   |   |   |   |   +---BezFwdIterator.h
|   |   |   |   |   +---BezierSegment.h
|   |   |   |   |   +---BitFlags.h
|   |   |   |   |   +---BitFlagsIO.h
|   |   |   |   |   +---BorderColors.h
|   |   |   |   |   +---BuildAssistant.h
|   |   |   |   |   +---CDManager.h
|   |   |   |   |   +---ClientUpdateModule.h
|   |   |   |   |   +---CommandLine.h
|   |   |   |   |   +---CopyProtection.h
|   |   |   |   |   +---crc.h
|   |   |   |   |   +---CRCDebug.h
|   |   |   |   |   +---CriticalSection.h
|   |   |   |   |   +---CustomMatchPreferences.h
|   |   |   |   |   +---DamageFX.h
|   |   |   |   |   +---DataChunk.h
|   |   |   |   |   +---Debug.h
|   |   |   |   |   +---Dict.h
|   |   |   |   |   +---Directory.h
|   |   |   |   |   +---DisabledTypes.h
|   |   |   |   |   +---DiscreteCircle.h
|   |   |   |   |   +---DrawModule.h
|   |   |   |   |   +---DynamicAudioEventInfo.h
|   |   |   |   |   +---encrypt.h
|   |   |   |   |   +---Energy.h
|   |   |   |   |   +---Errors.h
|   |   |   |   |   +---file.h
|   |   |   |   |   +---FileSystem.h
|   |   |   |   |   +---FunctionLexicon.h
|   |   |   |   |   +---GameAudio.h
|   |   |   |   |   +---GameCommon.h
|   |   |   |   |   +---GameEngine.h
|   |   |   |   |   +---GameLOD.h
|   |   |   |   |   +---GameMemory.h
|   |   |   |   |   +---GameMusic.h
|   |   |   |   |   +---GameSounds.h
|   |   |   |   |   +---GameSpeech.h
|   |   |   |   |   +---GameSpyMiscPreferences.h
|   |   |   |   |   +---GameState.h
|   |   |   |   |   +---GameStateMap.h
|   |   |   |   |   +---GameType.h
|   |   |   |   |   +---Geometry.h
|   |   |   |   |   +---GlobalData.h
|   |   |   |   |   +---Handicap.h
|   |   |   |   |   +---IgnorePreferences.h
|   |   |   |   |   +---INI.h
|   |   |   |   |   +---INIException.h
|   |   |   |   |   +---KindOf.h
|   |   |   |   |   +---LadderPreferences.h
|   |   |   |   |   +---Language.h
|   |   |   |   |   +---LatchRestore.h
|   |   |   |   |   +---List.h
|   |   |   |   |   +---LocalFile.h
|   |   |   |   |   +---LocalFileSystem.h
|   |   |   |   |   +---MapObject.h
|   |   |   |   |   +---MapReaderWriterInfo.h
|   |   |   |   |   +---MessageStream.h
|   |   |   |   |   +---MiniLog.h
|   |   |   |   |   +---MiscAudio.h
|   |   |   |   |   +---MissionStats.h
|   |   |   |   |   +---ModelState.h
|   |   |   |   |   +---Module.h
|   |   |   |   |   +---ModuleFactory.h
|   |   |   |   |   +---Money.h
|   |   |   |   |   +---MultiplayerSettings.h
|   |   |   |   |   +---NameKeyGenerator.h
|   |   |   |   |   +---ObjectStatusTypes.h
|   |   |   |   |   +---OSDisplay.h
|   |   |   |   |   +---Overridable.h
|   |   |   |   |   +---Override.h
|   |   |   |   |   +---PartitionSolver.h
|   |   |   |   |   +---PerfMetrics.h
|   |   |   |   |   +---PerfTimer.h
|   |   |   |   |   +---PlatformAssert.h
|   |   |   |   |   +---Player.h
|   |   |   |   |   +---PlayerList.h
|   |   |   |   |   +---PlayerTemplate.h
|   |   |   |   |   +---ProductionPrerequisite.h
|   |   |   |   |   +---QuickmatchPreferences.h
|   |   |   |   |   +---QuickTrig.h
|   |   |   |   |   +---QuotedPrintable.h
|   |   |   |   |   +---Radar.h
|   |   |   |   |   +---RAMFile.h
|   |   |   |   |   +---RandomValue.h
|   |   |   |   |   +---Recorder.h
|   |   |   |   |   +---Registry.h
|   |   |   |   |   +---ResourceGatheringManager.h
|   |   |   |   |   +---Science.h
|   |   |   |   |   +---ScopedMutex.h
|   |   |   |   |   +---ScoreKeeper.h
|   |   |   |   |   +---simpleplayer.h
|   |   |   |   |   +---SkirmishBattleHonors.h
|   |   |   |   |   +---SkirmishPreferences.h
|   |   |   |   |   +---Snapshot.h
|   |   |   |   |   +---SparseMatchFinder.h
|   |   |   |   |   +---SpecialPower.h
|   |   |   |   |   +---SpecialPowerMaskType.h
|   |   |   |   |   +---SpecialPowerType.h
|   |   |   |   |   +---StackDump.h
|   |   |   |   |   +---StateMachine.h
|   |   |   |   |   +---StatsCollector.h
|   |   |   |   |   +---STLTypedefs.h
|   |   |   |   |   +---StreamingArchiveFile.h
|   |   |   |   |   +---string.h
|   |   |   |   |   +---SubsystemInterface.h
|   |   |   |   |   +---SystemInfo.h
|   |   |   |   |   +---Team.h
|   |   |   |   |   +---Terrain.h
|   |   |   |   |   +---TerrainTypes.h
|   |   |   |   |   +---Thing.h
|   |   |   |   |   +---ThingFactory.h
|   |   |   |   |   +---ThingSort.h
|   |   |   |   |   +---ThingTemplate.h
|   |   |   |   |   +---TunnelTracker.h
|   |   |   |   |   +---UnicodeString.h
|   |   |   |   |   +---UnitTimings.h
|   |   |   |   |   +---Upgrade.h
|   |   |   |   |   +---urllaunch.h
|   |   |   |   |   +---UserPreferences.h
|   |   |   |   |   +---version.h
|   |   |   |   |   +---WellKnownKeys.h
|   |   |   |   |   +---Xfer.h
|   |   |   |   |   +---XferCRC.h
|   |   |   |   |   +---XferDeepCRC.h
|   |   |   |   |   +---XferLoad.h
|   |   |   |   |   `---XferSave.h
|   |   |   |   +---GameClient
|   |   |   |   |   +---Module
|   |   |   |   |   |   +---AnimatedParticleSysBoneClientUpdate.h
|   |   |   |   |   |   +---BeaconClientUpdate.h
|   |   |   |   |   |   `---SwayClientUpdate.h
|   |   |   |   |   +---Anim2D.h
|   |   |   |   |   +---AnimateWindowManager.h
|   |   |   |   |   +---CampaignManager.h
|   |   |   |   |   +---CDCheck.h
|   |   |   |   |   +---ChallengeGenerals.h
|   |   |   |   |   +---ClientRandomValue.h
|   |   |   |   |   +---Color.h
|   |   |   |   |   +---CommandXlat.h
|   |   |   |   |   +---ControlBar.h
|   |   |   |   |   +---ControlBarResizer.h
|   |   |   |   |   +---ControlBarScheme.h
|   |   |   |   |   +---Credits.h
|   |   |   |   |   +---DebugDisplay.h
|   |   |   |   |   +---Diplomacy.h
|   |   |   |   |   +---DisconnectMenu.h
|   |   |   |   |   +---Display.h
|   |   |   |   |   +---DisplayString.h
|   |   |   |   |   +---DisplayStringManager.h
|   |   |   |   |   +---Drawable.h
|   |   |   |   |   +---DrawableInfo.h
|   |   |   |   |   +---DrawableManager.h
|   |   |   |   |   +---DrawGroupInfo.h
|   |   |   |   |   +---EstablishConnectionsMenu.h
|   |   |   |   |   +---Eva.h
|   |   |   |   |   +---ExtendedMessageBox.h
|   |   |   |   |   +---FontDesc.h
|   |   |   |   |   +---FXList.h
|   |   |   |   |   +---Gadget.h
|   |   |   |   |   +---GadgetCheckBox.h
|   |   |   |   |   +---GadgetComboBox.h
|   |   |   |   |   +---GadgetListBox.h
|   |   |   |   |   +---GadgetProgressBar.h
|   |   |   |   |   +---GadgetPushButton.h
|   |   |   |   |   +---GadgetRadioButton.h
|   |   |   |   |   +---GadgetSlider.h
|   |   |   |   |   +---GadgetStaticText.h
|   |   |   |   |   +---GadgetTabControl.h
|   |   |   |   |   +---GadgetTextEntry.h
|   |   |   |   |   +---GameClient.h
|   |   |   |   |   +---GameFont.h
|   |   |   |   |   +---GameInfoWindow.h
|   |   |   |   |   +---GameText.h
|   |   |   |   |   +---GameWindow.h
|   |   |   |   |   +---GameWindowGlobal.h
|   |   |   |   |   +---GameWindowID.h
|   |   |   |   |   +---GameWindowManager.h
|   |   |   |   |   +---GameWindowTransitions.h
|   |   |   |   |   +---GlobalLanguage.h
|   |   |   |   |   +---GraphDraw.h
|   |   |   |   |   +---GUICallbacks.h
|   |   |   |   |   +---GUICommandTranslator.h
|   |   |   |   |   +---HeaderTemplate.h
|   |   |   |   |   +---HintSpy.h
|   |   |   |   |   +---HotKey.h
|   |   |   |   |   +---Image.h
|   |   |   |   |   +---IMEManager.h
|   |   |   |   |   +---InGameUI.h
|   |   |   |   |   +---Keyboard.h
|   |   |   |   |   +---KeyDefs.h
|   |   |   |   |   +---LanguageFilter.h
|   |   |   |   |   +---Line2D.h
|   |   |   |   |   +---LoadScreen.h
|   |   |   |   |   +---LookAtXlat.h
|   |   |   |   |   +---MapUtil.h
|   |   |   |   |   +---MessageBox.h
|   |   |   |   |   +---MetaEvent.h
|   |   |   |   |   +---Mouse.h
|   |   |   |   |   +---ParabolicEase.h
|   |   |   |   |   +---ParticleSys.h
|   |   |   |   |   +---PlaceEventTranslator.h
|   |   |   |   |   +---ProcessAnimateWindow.h
|   |   |   |   |   +---RadiusDecal.h
|   |   |   |   |   +---RayEffect.h
|   |   |   |   |   +---SelectionInfo.h
|   |   |   |   |   +---SelectionXlat.h
|   |   |   |   |   +---Shadow.h
|   |   |   |   |   +---Shell.h
|   |   |   |   |   +---ShellHooks.h
|   |   |   |   |   +---ShellMenuScheme.h
|   |   |   |   |   +---Smudge.h
|   |   |   |   |   +---Snow.h
|   |   |   |   |   +---Statistics.h
|   |   |   |   |   +---TerrainRoads.h
|   |   |   |   |   +---TerrainVisual.h
|   |   |   |   |   +---VideoPlayer.h
|   |   |   |   |   +---View.h
|   |   |   |   |   +---Water.h
|   |   |   |   |   +---WindowLayout.h
|   |   |   |   |   +---WindowVideoManager.h
|   |   |   |   |   +---WindowXlat.h
|   |   |   |   |   `---WinInstanceData.h
|   |   |   |   +---GameLogic
|   |   |   |   |   +---Module
|   |   |   |   |   |   +---ActiveBody.h
|   |   |   |   |   |   +---ActiveShroudUpgrade.h
|   |   |   |   |   |   +---AIUpdate.h
|   |   |   |   |   |   +---AnimationSteeringUpdate.h
|   |   |   |   |   |   +---ArmorUpgrade.h
|   |   |   |   |   |   +---AssaultTransportAIUpdate.h
|   |   |   |   |   |   +---AssistedTargetingUpdate.h
|   |   |   |   |   |   +---AutoDepositUpdate.h
|   |   |   |   |   |   +---AutoFindHealingUpdate.h
|   |   |   |   |   |   +---AutoHealBehavior.h
|   |   |   |   |   |   +---BaikonurLaunchPower.h
|   |   |   |   |   |   +---BaseRegenerateUpdate.h
|   |   |   |   |   |   +---BattleBusSlowDeathBehavior.h
|   |   |   |   |   |   +---BattlePlanUpdate.h
|   |   |   |   |   |   +---BehaviorModule.h
|   |   |   |   |   |   +---BodyModule.h
|   |   |   |   |   |   +---BoneFXDamage.h
|   |   |   |   |   |   +---BoneFXUpdate.h
|   |   |   |   |   |   +---BridgeBehavior.h
|   |   |   |   |   |   +---BridgeScaffoldBehavior.h
|   |   |   |   |   |   +---BridgeTowerBehavior.h
|   |   |   |   |   |   +---BunkerBusterBehavior.h
|   |   |   |   |   |   +---CashBountyPower.h
|   |   |   |   |   |   +---CashHackSpecialPower.h
|   |   |   |   |   |   +---CaveContain.h
|   |   |   |   |   |   +---CheckpointUpdate.h
|   |   |   |   |   |   +---ChinookAIUpdate.h
|   |   |   |   |   |   +---CleanupAreaPower.h
|   |   |   |   |   |   +---CleanupHazardUpdate.h
|   |   |   |   |   |   +---CollideModule.h
|   |   |   |   |   |   +---CommandButtonHuntUpdate.h
|   |   |   |   |   |   +---CommandSetUpgrade.h
|   |   |   |   |   |   +---ContainModule.h
|   |   |   |   |   |   +---ConvertToCarBombCrateCollide.h
|   |   |   |   |   |   +---ConvertToHijackedVehicleCrateCollide.h
|   |   |   |   |   |   +---CostModifierUpgrade.h
|   |   |   |   |   |   +---CountermeasuresBehavior.h
|   |   |   |   |   |   +---CrateCollide.h
|   |   |   |   |   |   +---CreateCrateDie.h
|   |   |   |   |   |   +---CreateModule.h
|   |   |   |   |   |   +---CreateObjectDie.h
|   |   |   |   |   |   +---CrushDie.h
|   |   |   |   |   |   +---DamageModule.h
|   |   |   |   |   |   +---DamDie.h
|   |   |   |   |   |   +---DefaultProductionExitUpdate.h
|   |   |   |   |   |   +---DefectorSpecialPower.h
|   |   |   |   |   |   +---DeletionUpdate.h
|   |   |   |   |   |   +---DeliverPayloadAIUpdate.h
|   |   |   |   |   |   +---DemoralizeSpecialPower.h
|   |   |   |   |   |   +---DemoTrapUpdate.h
|   |   |   |   |   |   +---DeployStyleAIUpdate.h
|   |   |   |   |   |   +---DestroyDie.h
|   |   |   |   |   |   +---DestroyModule.h
|   |   |   |   |   |   +---DieModule.h
|   |   |   |   |   |   +---DockUpdate.h
|   |   |   |   |   |   +---DozerAIUpdate.h
|   |   |   |   |   |   +---DumbProjectileBehavior.h
|   |   |   |   |   |   +---DynamicGeometryInfoUpdate.h
|   |   |   |   |   |   +---DynamicShroudClearingRangeUpdate.h
|   |   |   |   |   |   +---EjectPilotDie.h
|   |   |   |   |   |   +---EMPUpdate.h
|   |   |   |   |   |   +---EnemyNearUpdate.h
|   |   |   |   |   |   +---ExperienceScalarUpgrade.h
|   |   |   |   |   |   +---FireOCLAfterWeaponCooldownUpdate.h
|   |   |   |   |   |   +---FireSpreadUpdate.h
|   |   |   |   |   |   +---FirestormDynamicGeometryInfoUpdate.h
|   |   |   |   |   |   +---FireWeaponCollide.h
|   |   |   |   |   |   +---FireWeaponPower.h
|   |   |   |   |   |   +---FireWeaponUpdate.h
|   |   |   |   |   |   +---FireWeaponWhenDamagedBehavior.h
|   |   |   |   |   |   +---FireWeaponWhenDeadBehavior.h
|   |   |   |   |   |   +---FlammableUpdate.h
|   |   |   |   |   |   +---FlightDeckBehavior.h
|   |   |   |   |   |   +---FloatUpdate.h
|   |   |   |   |   |   +---FXListDie.h
|   |   |   |   |   |   +---GarrisonContain.h
|   |   |   |   |   |   +---GenerateMinefieldBehavior.h
|   |   |   |   |   |   +---GrantScienceUpgrade.h
|   |   |   |   |   |   +---GrantStealthBehavior.h
|   |   |   |   |   |   +---GrantUpgradeCreate.h
|   |   |   |   |   |   +---HackInternetAIUpdate.h
|   |   |   |   |   |   +---HealContain.h
|   |   |   |   |   |   +---HealCrateCollide.h
|   |   |   |   |   |   +---HeightDieUpdate.h
|   |   |   |   |   |   +---HelicopterSlowDeathUpdate.h
|   |   |   |   |   |   +---HelixContain.h
|   |   |   |   |   |   +---HighlanderBody.h
|   |   |   |   |   |   +---HijackerUpdate.h
|   |   |   |   |   |   +---HiveStructureBody.h
|   |   |   |   |   |   +---HordeUpdate.h
|   |   |   |   |   |   +---ImmortalBody.h
|   |   |   |   |   |   +---InactiveBody.h
|   |   |   |   |   |   +---InstantDeathBehavior.h
|   |   |   |   |   |   +---InternetHackContain.h
|   |   |   |   |   |   +---JetAIUpdate.h
|   |   |   |   |   |   +---JetSlowDeathBehavior.h
|   |   |   |   |   |   +---KeepObjectDie.h
|   |   |   |   |   |   +---LaserUpdate.h
|   |   |   |   |   |   +---LifetimeUpdate.h
|   |   |   |   |   |   +---LockWeaponCreate.h
|   |   |   |   |   |   +---LocomotorSetUpgrade.h
|   |   |   |   |   |   +---MaxHealthUpgrade.h
|   |   |   |   |   |   +---MinefieldBehavior.h
|   |   |   |   |   |   +---MissileAIUpdate.h
|   |   |   |   |   |   +---MissileLauncherBuildingUpdate.h
|   |   |   |   |   |   +---MobMemberSlavedUpdate.h
|   |   |   |   |   |   +---MobNexusContain.h
|   |   |   |   |   |   +---ModelConditionUpgrade.h
|   |   |   |   |   |   +---MoneyCrateCollide.h
|   |   |   |   |   |   +---NeutronBlastBehavior.h
|   |   |   |   |   |   +---NeutronMissileSlowDeathUpdate.h
|   |   |   |   |   |   +---NeutronMissileUpdate.h
|   |   |   |   |   |   +---ObjectCreationUpgrade.h
|   |   |   |   |   |   +---ObjectDefectionHelper.h
|   |   |   |   |   |   +---ObjectHelper.h
|   |   |   |   |   |   +---ObjectRepulsorHelper.h
|   |   |   |   |   |   +---ObjectSMCHelper.h
|   |   |   |   |   |   +---ObjectWeaponStatusHelper.h
|   |   |   |   |   |   +---OCLSpecialPower.h
|   |   |   |   |   |   +---OCLUpdate.h
|   |   |   |   |   |   +---OpenContain.h
|   |   |   |   |   |   +---OverchargeBehavior.h
|   |   |   |   |   |   +---OverlordContain.h
|   |   |   |   |   |   +---ParachuteContain.h
|   |   |   |   |   |   +---ParkingPlaceBehavior.h
|   |   |   |   |   |   +---ParticleUplinkCannonUpdate.h
|   |   |   |   |   |   +---PassengersFireUpgrade.h
|   |   |   |   |   |   +---PhysicsUpdate.h
|   |   |   |   |   |   +---PilotFindVehicleUpdate.h
|   |   |   |   |   |   +---PointDefenseLaserUpdate.h
|   |   |   |   |   |   +---PoisonedBehavior.h
|   |   |   |   |   |   +---PowerPlantUpdate.h
|   |   |   |   |   |   +---PowerPlantUpgrade.h
|   |   |   |   |   |   +---POWTruckAIUpdate.h
|   |   |   |   |   |   +---POWTruckBehavior.h
|   |   |   |   |   |   +---PreorderCreate.h
|   |   |   |   |   |   +---PrisonBehavior.h
|   |   |   |   |   |   +---PrisonDockUpdate.h
|   |   |   |   |   |   +---ProductionUpdate.h
|   |   |   |   |   |   +---ProjectileStreamUpdate.h
|   |   |   |   |   |   +---ProneUpdate.h
|   |   |   |   |   |   +---PropagandaCenterBehavior.h
|   |   |   |   |   |   +---PropagandaTowerBehavior.h
|   |   |   |   |   |   +---QueueProductionExitUpdate.h
|   |   |   |   |   |   +---RadarUpdate.h
|   |   |   |   |   |   +---RadarUpgrade.h
|   |   |   |   |   |   +---RadiusDecalUpdate.h
|   |   |   |   |   |   +---RailedTransportAIUpdate.h
|   |   |   |   |   |   +---RailedTransportContain.h
|   |   |   |   |   |   +---RailedTransportDockUpdate.h
|   |   |   |   |   |   +---RailroadGuideAIUpdate.h
|   |   |   |   |   |   +---RebuildHoleBehavior.h
|   |   |   |   |   |   +---RebuildHoleExposeDie.h
|   |   |   |   |   |   +---RepairDockUpdate.h
|   |   |   |   |   |   +---ReplaceObjectUpgrade.h
|   |   |   |   |   |   +---RiderChangeContain.h
|   |   |   |   |   |   +---SabotageCommandCenterCrateCollide.h
|   |   |   |   |   |   +---SabotageFakeBuildingCrateCollide.h
|   |   |   |   |   |   +---SabotageInternetCenterCrateCollide.h
|   |   |   |   |   |   +---SabotageMilitaryFactoryCrateCollide.h
|   |   |   |   |   |   +---SabotagePowerPlantCrateCollide.h
|   |   |   |   |   |   +---SabotageSuperweaponCrateCollide.h
|   |   |   |   |   |   +---SabotageSupplyCenterCrateCollide.h
|   |   |   |   |   |   +---SabotageSupplyDropzoneCrateCollide.h
|   |   |   |   |   |   +---SalvageCrateCollide.h
|   |   |   |   |   |   +---ShroudCrateCollide.h
|   |   |   |   |   |   +---SlavedUpdate.h
|   |   |   |   |   |   +---SlowDeathBehavior.h
|   |   |   |   |   |   +---SmartBombTargetHomingUpdate.h
|   |   |   |   |   |   +---SpawnBehavior.h
|   |   |   |   |   |   +---SpawnPointProductionExitUpdate.h
|   |   |   |   |   |   +---SpecialAbility.h
|   |   |   |   |   |   +---SpecialAbilityUpdate.h
|   |   |   |   |   |   +---SpecialPowerCompletionDie.h
|   |   |   |   |   |   +---SpecialPowerCreate.h
|   |   |   |   |   |   +---SpecialPowerModule.h
|   |   |   |   |   |   +---SpecialPowerUpdateModule.h
|   |   |   |   |   |   +---SpectreGunshipDeploymentUpdate.h
|   |   |   |   |   |   +---SpectreGunshipUpdate.h
|   |   |   |   |   |   +---SpyVisionSpecialPower.h
|   |   |   |   |   |   +---SpyVisionUpdate.h
|   |   |   |   |   |   +---SquishCollide.h
|   |   |   |   |   |   +---StatusBitsUpgrade.h
|   |   |   |   |   |   +---StatusDamageHelper.h
|   |   |   |   |   |   +---StealthDetectorUpdate.h
|   |   |   |   |   |   +---StealthUpdate.h
|   |   |   |   |   |   +---StealthUpgrade.h
|   |   |   |   |   |   +---StickyBombUpdate.h
|   |   |   |   |   |   +---StructureBody.h
|   |   |   |   |   |   +---StructureCollapseUpdate.h
|   |   |   |   |   |   +---StructureToppleUpdate.h
|   |   |   |   |   |   +---SubdualDamageHelper.h
|   |   |   |   |   |   +---SubObjectsUpgrade.h
|   |   |   |   |   |   +---SupplyCenterCreate.h
|   |   |   |   |   |   +---SupplyCenterDockUpdate.h
|   |   |   |   |   |   +---SupplyCenterProductionExitUpdate.h
|   |   |   |   |   |   +---SupplyTruckAIUpdate.h
|   |   |   |   |   |   +---SupplyWarehouseCreate.h
|   |   |   |   |   |   +---SupplyWarehouseCripplingBehavior.h
|   |   |   |   |   |   +---SupplyWarehouseDockUpdate.h
|   |   |   |   |   |   +---TechBuildingBehavior.h
|   |   |   |   |   |   +---TempWeaponBonusHelper.h
|   |   |   |   |   |   +---TensileFormationUpdate.h
|   |   |   |   |   |   +---ToppleUpdate.h
|   |   |   |   |   |   +---TransitionDamageFX.h
|   |   |   |   |   |   +---TransportAIUpdate.h
|   |   |   |   |   |   +---TransportContain.h
|   |   |   |   |   |   +---TunnelContain.h
|   |   |   |   |   |   +---UndeadBody.h
|   |   |   |   |   |   +---UnitCrateCollide.h
|   |   |   |   |   |   +---UnpauseSpecialPowerUpgrade.h
|   |   |   |   |   |   +---UpdateModule.h
|   |   |   |   |   |   +---UpgradeDie.h
|   |   |   |   |   |   +---UpgradeModule.h
|   |   |   |   |   |   +---VeterancyCrateCollide.h
|   |   |   |   |   |   +---VeterancyGainCreate.h
|   |   |   |   |   |   +---WanderAIUpdate.h
|   |   |   |   |   |   +---WaveGuideUpdate.h
|   |   |   |   |   |   +---WeaponBonusUpdate.h
|   |   |   |   |   |   +---WeaponBonusUpgrade.h
|   |   |   |   |   |   +---WeaponSetUpgrade.h
|   |   |   |   |   |   `---WorkerAIUpdate.h
|   |   |   |   |   +---AI.h
|   |   |   |   |   +---AIDock.h
|   |   |   |   |   +---AIGuard.h
|   |   |   |   |   +---AIGuardRetaliate.h
|   |   |   |   |   +---AIPathfind.h
|   |   |   |   |   +---AIPlayer.h
|   |   |   |   |   +---AISkirmishPlayer.h
|   |   |   |   |   +---AIStateMachine.h
|   |   |   |   |   +---AITNGuard.h
|   |   |   |   |   +---Armor.h
|   |   |   |   |   +---ArmorSet.h
|   |   |   |   |   +---CaveSystem.h
|   |   |   |   |   +---CrateSystem.h
|   |   |   |   |   +---Damage.h
|   |   |   |   |   +---ExperienceTracker.h
|   |   |   |   |   +---FiringTracker.h
|   |   |   |   |   +---FPUControl.h
|   |   |   |   |   +---GameLogic.h
|   |   |   |   |   +---GhostObject.h
|   |   |   |   |   +---Locomotor.h
|   |   |   |   |   +---LocomotorSet.h
|   |   |   |   |   +---LogicRandomValue.h
|   |   |   |   |   +---Object.h
|   |   |   |   |   +---ObjectCreationList.h
|   |   |   |   |   +---ObjectIter.h
|   |   |   |   |   +---ObjectScriptStatusBits.h
|   |   |   |   |   +---ObjectTypes.h
|   |   |   |   |   +---PartitionManager.h
|   |   |   |   |   +---PolygonTrigger.h
|   |   |   |   |   +---Powers.h
|   |   |   |   |   +---RankInfo.h
|   |   |   |   |   +---ScriptActions.h
|   |   |   |   |   +---ScriptConditions.h
|   |   |   |   |   +---ScriptEngine.h
|   |   |   |   |   +---Scripts.h
|   |   |   |   |   +---SidesList.h
|   |   |   |   |   +---Squad.h
|   |   |   |   |   +---TerrainLogic.h
|   |   |   |   |   +---TurretAI.h
|   |   |   |   |   +---VictoryConditions.h
|   |   |   |   |   +---Weapon.h
|   |   |   |   |   +---WeaponBonusConditionFlags.h
|   |   |   |   |   +---WeaponSet.h
|   |   |   |   |   +---WeaponSetFlags.h
|   |   |   |   |   +---WeaponSetType.h
|   |   |   |   |   `---WeaponStatus.h
|   |   |   |   +---GameNetwork
|   |   |   |   |   +---GameSpy
|   |   |   |   |   |   +---BuddyDefs.h
|   |   |   |   |   |   +---BuddyThread.h
|   |   |   |   |   |   +---GameResultsThread.h
|   |   |   |   |   |   +---GSConfig.h
|   |   |   |   |   |   +---LadderDefs.h
|   |   |   |   |   |   +---LobbyUtils.h
|   |   |   |   |   |   +---MainMenuUtils.h
|   |   |   |   |   |   +---PeerDefs.h
|   |   |   |   |   |   +---PeerDefsImplementation.h
|   |   |   |   |   |   +---PeerThread.h
|   |   |   |   |   |   +---PersistentStorageDefs.h
|   |   |   |   |   |   +---PersistentStorageThread.h
|   |   |   |   |   |   +---PingThread.h
|   |   |   |   |   |   +---StagingRoomGameInfo.h
|   |   |   |   |   |   `---ThreadUtils.h
|   |   |   |   |   +---WOLBrowser
|   |   |   |   |   |   +---FEBDispatch.h
|   |   |   |   |   |   `---WebBrowser.h
|   |   |   |   |   +---Connection.h
|   |   |   |   |   +---ConnectionManager.h
|   |   |   |   |   +---DisconnectManager.h
|   |   |   |   |   +---DownloadManager.h
|   |   |   |   |   +---FileTransfer.h
|   |   |   |   |   +---FirewallHelper.h
|   |   |   |   |   +---FrameData.h
|   |   |   |   |   +---FrameDataManager.h
|   |   |   |   |   +---FrameMetrics.h
|   |   |   |   |   +---GameInfo.h
|   |   |   |   |   +---GameMessageParser.h
|   |   |   |   |   +---GameSpy.h
|   |   |   |   |   +---GameSpyChat.h
|   |   |   |   |   +---GameSpyGameInfo.h
|   |   |   |   |   +---GameSpyGP.h
|   |   |   |   |   +---GameSpyOverlay.h
|   |   |   |   |   +---GameSpyThread.h
|   |   |   |   |   +---GUIUtil.h
|   |   |   |   |   +---IPEnumeration.h
|   |   |   |   |   +---LANAPI.h
|   |   |   |   |   +---LANAPICallbacks.h
|   |   |   |   |   +---LANGameInfo.h
|   |   |   |   |   +---LANPlayer.h
|   |   |   |   |   +---NAT.h
|   |   |   |   |   +---NetCommandList.h
|   |   |   |   |   +---NetCommandMsg.h
|   |   |   |   |   +---NetCommandRef.h
|   |   |   |   |   +---NetCommandWrapperList.h
|   |   |   |   |   +---NetPacket.h
|   |   |   |   |   +---NetworkDefs.h
|   |   |   |   |   +---NetworkInterface.h
|   |   |   |   |   +---networkutil.h
|   |   |   |   |   +---RankPointValue.h
|   |   |   |   |   +---Transport.h
|   |   |   |   |   +---udp.h
|   |   |   |   |   `---User.h
|   |   |   |   +---Memory
|   |   |   |   |   `---PoolAllocator.h
|   |   |   |   +---Precompiled
|   |   |   |   |   `---PreRTS.h
|   |   |   |   `---System
|   |   |   |       `---JobSystem.h
|   |   |   +---Source
|   |   |   |   +---AI
|   |   |   |   |   `---FlowField.cpp
|   |   |   |   +---Common
|   |   |   |   |   +---Audio
|   |   |   |   |   |   +---AudioEventRTS.cpp
|   |   |   |   |   |   +---AudioRequest.cpp
|   |   |   |   |   |   +---DynamicAudioEventInfo.cpp
|   |   |   |   |   |   +---GameAudio.cpp
|   |   |   |   |   |   +---GameMusic.cpp
|   |   |   |   |   |   +---GameSounds.cpp
|   |   |   |   |   |   +---GameSpeech.cpp
|   |   |   |   |   |   +---simpleplayer.cpp
|   |   |   |   |   |   `---urllaunch.cpp
|   |   |   |   |   +---Bezier
|   |   |   |   |   |   +---BezFwdIterator.cpp
|   |   |   |   |   |   `---BezierSegment.cpp
|   |   |   |   |   +---INI
|   |   |   |   |   |   +---INI.cpp
|   |   |   |   |   |   +---INIAiData.cpp
|   |   |   |   |   |   +---INIAnimation.cpp
|   |   |   |   |   |   +---INIAudioEventInfo.cpp
|   |   |   |   |   |   +---INICommandButton.cpp
|   |   |   |   |   |   +---INICommandSet.cpp
|   |   |   |   |   |   +---INIControlBarScheme.cpp
|   |   |   |   |   |   +---INICrate.cpp
|   |   |   |   |   |   +---INIDamageFX.cpp
|   |   |   |   |   |   +---INIDrawGroupInfo.cpp
|   |   |   |   |   |   +---INIGameData.cpp
|   |   |   |   |   |   +---INIMapCache.cpp
|   |   |   |   |   |   +---INIMapData.cpp
|   |   |   |   |   |   +---INIMappedImage.cpp
|   |   |   |   |   |   +---INIMiscAudio.cpp
|   |   |   |   |   |   +---INIModel.cpp
|   |   |   |   |   |   +---INIMultiplayer.cpp
|   |   |   |   |   |   +---INIObject.cpp
|   |   |   |   |   |   +---INIParticleSys.cpp
|   |   |   |   |   |   +---INISpecialPower.cpp
|   |   |   |   |   |   +---INITerrain.cpp
|   |   |   |   |   |   +---INITerrainBridge.cpp
|   |   |   |   |   |   +---INITerrainRoad.cpp
|   |   |   |   |   |   +---INIUpgrade.cpp
|   |   |   |   |   |   +---INIVideo.cpp
|   |   |   |   |   |   +---INIWater.cpp
|   |   |   |   |   |   +---INIWeapon.cpp
|   |   |   |   |   |   `---INIWebpageURL.cpp
|   |   |   |   |   +---RTS
|   |   |   |   |   |   +---AcademyStats.cpp
|   |   |   |   |   |   +---ActionManager.cpp
|   |   |   |   |   |   +---Energy.cpp
|   |   |   |   |   |   +---Handicap.cpp
|   |   |   |   |   |   +---MissionStats.cpp
|   |   |   |   |   |   +---Money.cpp
|   |   |   |   |   |   +---Player.cpp
|   |   |   |   |   |   +---PlayerList.cpp
|   |   |   |   |   |   +---PlayerTemplate.cpp
|   |   |   |   |   |   +---ProductionPrerequisite.cpp
|   |   |   |   |   |   +---ResourceGatheringManager.cpp
|   |   |   |   |   |   +---Science.cpp
|   |   |   |   |   |   +---ScoreKeeper.cpp
|   |   |   |   |   |   +---SpecialPower.cpp
|   |   |   |   |   |   +---Team.cpp
|   |   |   |   |   |   `---TunnelTracker.cpp
|   |   |   |   |   +---System
|   |   |   |   |   |   +---SaveGame
|   |   |   |   |   |   |   +---GameState.cpp
|   |   |   |   |   |   |   `---GameStateMap.cpp
|   |   |   |   |   |   +---ArchiveFile.cpp
|   |   |   |   |   |   +---ArchiveFileSystem.cpp
|   |   |   |   |   |   +---AsciiString.cpp
|   |   |   |   |   |   +---BuildAssistant.cpp
|   |   |   |   |   |   +---CDManager.cpp
|   |   |   |   |   |   +---Compression.cpp
|   |   |   |   |   |   +---CopyProtection.cpp
|   |   |   |   |   |   +---CriticalSection.cpp
|   |   |   |   |   |   +---DataChunk.cpp
|   |   |   |   |   |   +---Debug.cpp
|   |   |   |   |   |   +---Directory.cpp
|   |   |   |   |   |   +---DisabledTypes.cpp
|   |   |   |   |   |   +---encrypt.cpp
|   |   |   |   |   |   +---File.cpp
|   |   |   |   |   |   +---FileSystem.cpp
|   |   |   |   |   |   +---FunctionLexicon.cpp
|   |   |   |   |   |   +---GameCommon.cpp
|   |   |   |   |   |   +---GameMemory.cpp
|   |   |   |   |   |   +---GameType.cpp
|   |   |   |   |   |   +---Geometry.cpp
|   |   |   |   |   |   +---KindOf.cpp
|   |   |   |   |   |   +---List.cpp
|   |   |   |   |   |   +---LocalFile.cpp
|   |   |   |   |   |   +---LocalFileSystem.cpp
|   |   |   |   |   |   +---MemoryInit.cpp
|   |   |   |   |   |   +---ObjectStatusTypes.cpp
|   |   |   |   |   |   +---QuickTrig.cpp
|   |   |   |   |   |   +---QuotedPrintable.cpp
|   |   |   |   |   |   +---Radar.cpp
|   |   |   |   |   |   +---RAMFile.cpp
|   |   |   |   |   |   +---registry.cpp
|   |   |   |   |   |   +---Snapshot.cpp
|   |   |   |   |   |   +---StackDump.cpp
|   |   |   |   |   |   +---StreamingArchiveFile.cpp
|   |   |   |   |   |   +---String.cpp
|   |   |   |   |   |   +---SubsystemInterface.cpp
|   |   |   |   |   |   +---Trig.cpp
|   |   |   |   |   |   +---UnicodeString.cpp
|   |   |   |   |   |   +---Upgrade.cpp
|   |   |   |   |   |   +---Xfer.cpp
|   |   |   |   |   |   +---XferCRC.cpp
|   |   |   |   |   |   +---XferLoad.cpp
|   |   |   |   |   |   `---XferSave.cpp
|   |   |   |   |   +---Thing
|   |   |   |   |   |   +---DrawModule.cpp
|   |   |   |   |   |   +---Module.cpp
|   |   |   |   |   |   +---ModuleFactory.cpp
|   |   |   |   |   |   +---Thing.cpp
|   |   |   |   |   |   +---ThingFactory.cpp
|   |   |   |   |   |   `---ThingTemplate.cpp
|   |   |   |   |   +---BitFlags.cpp
|   |   |   |   |   +---CommandLine.cpp
|   |   |   |   |   +---crc.cpp
|   |   |   |   |   +---CRCDebug.cpp
|   |   |   |   |   +---DamageFX.cpp
|   |   |   |   |   +---Dict.cpp
|   |   |   |   |   +---DiscreteCircle.cpp
|   |   |   |   |   +---GameEngine.cpp
|   |   |   |   |   +---GameLOD.cpp
|   |   |   |   |   +---GameMain.cpp
|   |   |   |   |   +---GlobalData.cpp
|   |   |   |   |   +---Language.cpp
|   |   |   |   |   +---MessageStream.cpp
|   |   |   |   |   +---MiniLog.cpp
|   |   |   |   |   +---MultiplayerSettings.cpp
|   |   |   |   |   +---NameKeyGenerator.cpp
|   |   |   |   |   +---PartitionSolver.cpp
|   |   |   |   |   +---PerfTimer.cpp
|   |   |   |   |   +---RandomValue.cpp
|   |   |   |   |   +---Recorder.cpp
|   |   |   |   |   +---SkirmishBattleHonors.cpp
|   |   |   |   |   +---StateMachine.cpp
|   |   |   |   |   +---StatsCollector.cpp
|   |   |   |   |   +---TerrainTypes.cpp
|   |   |   |   |   +---UserPreferences.cpp
|   |   |   |   |   `---version.cpp
|   |   |   |   +---GameClient
|   |   |   |   |   +---Drawable
|   |   |   |   |   |   +---Update
|   |   |   |   |   |   |   +---AnimatedParticleSysBoneClientUpdate.cpp
|   |   |   |   |   |   |   +---BeaconClientUpdate.cpp
|   |   |   |   |   |   |   `---SwayClientUpdate.cpp
|   |   |   |   |   |   `---DrawableManager.cpp
|   |   |   |   |   +---GUI
|   |   |   |   |   |   +---ControlBar
|   |   |   |   |   |   |   +---ControlBar.cpp
|   |   |   |   |   |   |   +---ControlBarBeacon.cpp
|   |   |   |   |   |   |   +---ControlBarCommand.cpp
|   |   |   |   |   |   |   +---ControlBarCommandProcessing.cpp
|   |   |   |   |   |   |   +---ControlBarMultiSelect.cpp
|   |   |   |   |   |   |   +---ControlBarObserver.cpp
|   |   |   |   |   |   |   +---ControlBarOCLTimer.cpp
|   |   |   |   |   |   |   +---ControlBarPrintPositions.cpp
|   |   |   |   |   |   |   +---ControlBarResizer.cpp
|   |   |   |   |   |   |   +---ControlBarScheme.cpp
|   |   |   |   |   |   |   +---ControlBarStructureInventory.cpp
|   |   |   |   |   |   |   `---ControlBarUnderConstruction.cpp
|   |   |   |   |   |   +---DisconnectMenu
|   |   |   |   |   |   |   `---DisconnectMenu.cpp
|   |   |   |   |   |   +---EstablishConnectionsMenu
|   |   |   |   |   |   |   `---EstablishConnectionsMenu.cpp
|   |   |   |   |   |   +---Gadget
|   |   |   |   |   |   |   +---GadgetCheckBox.cpp
|   |   |   |   |   |   |   +---GadgetComboBox.cpp
|   |   |   |   |   |   |   +---GadgetHorizontalSlider.cpp
|   |   |   |   |   |   |   +---GadgetListBox.cpp
|   |   |   |   |   |   |   +---GadgetProgressBar.cpp
|   |   |   |   |   |   |   +---GadgetPushButton.cpp
|   |   |   |   |   |   |   +---GadgetRadioButton.cpp
|   |   |   |   |   |   |   +---GadgetStaticText.cpp
|   |   |   |   |   |   |   +---GadgetTabControl.cpp
|   |   |   |   |   |   |   +---GadgetTextEntry.cpp
|   |   |   |   |   |   |   `---GadgetVerticalSlider.cpp
|   |   |   |   |   |   +---GUICallbacks
|   |   |   |   |   |   |   +---Menus
|   |   |   |   |   |   |   |   +---ChallengeMenu.cpp
|   |   |   |   |   |   |   |   +---CreditsMenu.cpp
|   |   |   |   |   |   |   |   +---DifficultySelect.cpp
|   |   |   |   |   |   |   |   +---DisconnectWindow.cpp
|   |   |   |   |   |   |   |   +---DownloadMenu.cpp
|   |   |   |   |   |   |   |   +---EstablishConnectionsWindow.cpp
|   |   |   |   |   |   |   |   +---GameInfoWindow.cpp
|   |   |   |   |   |   |   |   +---KeyboardOptionsMenu.cpp
|   |   |   |   |   |   |   |   +---LanGameOptionsMenu.cpp
|   |   |   |   |   |   |   |   +---LanLobbyMenu.cpp
|   |   |   |   |   |   |   |   +---LanMapSelectMenu.cpp
|   |   |   |   |   |   |   |   +---MainMenu.cpp
|   |   |   |   |   |   |   |   +---MapSelectMenu.cpp
|   |   |   |   |   |   |   |   +---NetworkDirectConnect.cpp
|   |   |   |   |   |   |   |   +---OptionsMenu.cpp
|   |   |   |   |   |   |   |   +---PopupCommunicator.cpp
|   |   |   |   |   |   |   |   +---PopupHostGame.cpp
|   |   |   |   |   |   |   |   +---PopupJoinGame.cpp
|   |   |   |   |   |   |   |   +---PopupLadderSelect.cpp
|   |   |   |   |   |   |   |   +---PopupPlayerInfo.cpp
|   |   |   |   |   |   |   |   +---PopupReplay.cpp
|   |   |   |   |   |   |   |   +---PopupSaveLoad.cpp
|   |   |   |   |   |   |   |   +---QuitMenu.cpp
|   |   |   |   |   |   |   |   +---ReplayMenu.cpp
|   |   |   |   |   |   |   |   +---ScoreScreen.cpp
|   |   |   |   |   |   |   |   +---SinglePlayerMenu.cpp
|   |   |   |   |   |   |   |   +---SkirmishGameOptionsMenu.cpp
|   |   |   |   |   |   |   |   +---SkirmishMapSelectMenu.cpp
|   |   |   |   |   |   |   |   +---WOLBuddyOverlay.cpp
|   |   |   |   |   |   |   |   +---WOLCustomScoreScreen.cpp
|   |   |   |   |   |   |   |   +---WOLGameSetupMenu.cpp
|   |   |   |   |   |   |   |   +---WOLLadderScreen.cpp
|   |   |   |   |   |   |   |   +---WOLLobbyMenu.cpp
|   |   |   |   |   |   |   |   +---WOLLocaleSelectPopup.cpp
|   |   |   |   |   |   |   |   +---WOLLoginMenu.cpp
|   |   |   |   |   |   |   |   +---WOLMapSelectMenu.cpp
|   |   |   |   |   |   |   |   +---WOLMessageWindow.cpp
|   |   |   |   |   |   |   |   +---WOLQMScoreScreen.cpp
|   |   |   |   |   |   |   |   +---WOLQuickMatchMenu.cpp
|   |   |   |   |   |   |   |   +---WOLStatusMenu.cpp
|   |   |   |   |   |   |   |   `---WOLWelcomeMenu.cpp
|   |   |   |   |   |   |   +---ControlBarCallback.cpp
|   |   |   |   |   |   |   +---ControlBarPopupDescription.cpp
|   |   |   |   |   |   |   +---Diplomacy.cpp
|   |   |   |   |   |   |   +---ExtendedMessageBox.cpp
|   |   |   |   |   |   |   +---GeneralsExpPoints.cpp
|   |   |   |   |   |   |   +---IMECandidate.cpp
|   |   |   |   |   |   |   +---InGameChat.cpp
|   |   |   |   |   |   |   +---InGamePopupMessage.cpp
|   |   |   |   |   |   |   +---MessageBox.cpp
|   |   |   |   |   |   |   `---ReplayControls.cpp
|   |   |   |   |   |   +---Shell
|   |   |   |   |   |   |   +---Shell.cpp
|   |   |   |   |   |   |   `---ShellMenuScheme.cpp
|   |   |   |   |   |   +---AnimateWindowManager.cpp
|   |   |   |   |   |   +---ChallengeGenerals.cpp
|   |   |   |   |   |   +---GameFont.cpp
|   |   |   |   |   |   +---GameWindow.cpp
|   |   |   |   |   |   +---GameWindowGlobal.cpp
|   |   |   |   |   |   +---GameWindowManager.cpp
|   |   |   |   |   |   +---GameWindowManagerScript.cpp
|   |   |   |   |   |   +---GameWindowTransitions.cpp
|   |   |   |   |   |   +---GameWindowTransitionsStyles.cpp
|   |   |   |   |   |   +---HeaderTemplate.cpp
|   |   |   |   |   |   +---IMEManager.cpp
|   |   |   |   |   |   +---LoadScreen.cpp
|   |   |   |   |   |   +---ProcessAnimateWindow.cpp
|   |   |   |   |   |   +---WindowLayout.cpp
|   |   |   |   |   |   +---WindowVideoManager.cpp
|   |   |   |   |   |   `---WinInstanceData.cpp
|   |   |   |   |   +---Input
|   |   |   |   |   |   +---Keyboard.cpp
|   |   |   |   |   |   `---Mouse.cpp
|   |   |   |   |   +---MessageStream
|   |   |   |   |   |   +---CommandXlat.cpp
|   |   |   |   |   |   +---GUICommandTranslator.cpp
|   |   |   |   |   |   +---HintSpy.cpp
|   |   |   |   |   |   +---HotKey.cpp
|   |   |   |   |   |   +---LookAtXlat.cpp
|   |   |   |   |   |   +---MetaEvent.cpp
|   |   |   |   |   |   +---PlaceEventTranslator.cpp
|   |   |   |   |   |   +---SelectionXlat.cpp
|   |   |   |   |   |   `---WindowXlat.cpp
|   |   |   |   |   +---System
|   |   |   |   |   |   +---Debug Displayers
|   |   |   |   |   |   |   `---AudioDebugDisplay.cpp
|   |   |   |   |   |   +---Anim2D.cpp
|   |   |   |   |   |   +---CampaignManager.cpp
|   |   |   |   |   |   +---DebugDisplay.cpp
|   |   |   |   |   |   +---Image.cpp
|   |   |   |   |   |   +---ParticleSys.cpp
|   |   |   |   |   |   +---RayEffect.cpp
|   |   |   |   |   |   `---Smudge.cpp
|   |   |   |   |   +---Terrain
|   |   |   |   |   |   +---TerrainRoads.cpp
|   |   |   |   |   |   `---TerrainVisual.cpp
|   |   |   |   |   +---Color.cpp
|   |   |   |   |   +---Credits.cpp
|   |   |   |   |   +---Display.cpp
|   |   |   |   |   +---DisplayString.cpp
|   |   |   |   |   +---DisplayStringManager.cpp
|   |   |   |   |   +---Drawable.cpp
|   |   |   |   |   +---DrawableManager.cpp
|   |   |   |   |   +---DrawGroupInfo.cpp
|   |   |   |   |   +---Eva.cpp
|   |   |   |   |   +---FXList.cpp
|   |   |   |   |   +---GameClient.cpp
|   |   |   |   |   +---GameClientDispatch.cpp
|   |   |   |   |   +---GameText.cpp
|   |   |   |   |   +---GlobalLanguage.cpp
|   |   |   |   |   +---GraphDraw.cpp
|   |   |   |   |   +---InGameUI.cpp
|   |   |   |   |   +---LanguageFilter.cpp
|   |   |   |   |   +---Line2D.cpp
|   |   |   |   |   +---MapUtil.cpp
|   |   |   |   |   +---ParabolicEase.cpp
|   |   |   |   |   +---RadiusDecal.cpp
|   |   |   |   |   +---SelectionInfo.cpp
|   |   |   |   |   +---Snow.cpp
|   |   |   |   |   +---Statistics.cpp
|   |   |   |   |   +---VideoPlayer.cpp
|   |   |   |   |   +---VideoStream.cpp
|   |   |   |   |   +---View.cpp
|   |   |   |   |   `---Water.cpp
|   |   |   |   +---GameLogic
|   |   |   |   |   +---AI
|   |   |   |   |   |   +---AI.cpp
|   |   |   |   |   |   +---AIDock.cpp
|   |   |   |   |   |   +---AIGroup.cpp
|   |   |   |   |   |   +---AIGuard.cpp
|   |   |   |   |   |   +---AIGuardRetaliate.cpp
|   |   |   |   |   |   +---AIPathfind.cpp
|   |   |   |   |   |   +---AIPlayer.cpp
|   |   |   |   |   |   +---AISkirmishPlayer.cpp
|   |   |   |   |   |   +---AIStates.cpp
|   |   |   |   |   |   +---AITNGuard.cpp
|   |   |   |   |   |   +---Squad.cpp
|   |   |   |   |   |   `---TurretAI.cpp
|   |   |   |   |   +---Map
|   |   |   |   |   |   +---PolygonTrigger.cpp
|   |   |   |   |   |   +---SidesList.cpp
|   |   |   |   |   |   `---TerrainLogic.cpp
|   |   |   |   |   +---Object
|   |   |   |   |   |   +---Behavior
|   |   |   |   |   |   |   +---AutoHealBehavior.cpp
|   |   |   |   |   |   |   +---BattleBusSlowDeathBehavior.cpp
|   |   |   |   |   |   |   +---BehaviorModule.cpp
|   |   |   |   |   |   |   +---BridgeBehavior.cpp
|   |   |   |   |   |   |   +---BridgeScaffoldBehavior.cpp
|   |   |   |   |   |   |   +---BridgeTowerBehavior.cpp
|   |   |   |   |   |   |   +---BunkerBusterBehavior.cpp
|   |   |   |   |   |   |   +---CountermeasuresBehavior.cpp
|   |   |   |   |   |   |   +---DumbProjectileBehavior.cpp
|   |   |   |   |   |   |   +---FireWeaponWhenDamagedBehavior.cpp
|   |   |   |   |   |   |   +---FireWeaponWhenDeadBehavior.cpp
|   |   |   |   |   |   |   +---FlightDeckBehavior.cpp
|   |   |   |   |   |   |   +---GenerateMinefieldBehavior.cpp
|   |   |   |   |   |   |   +---GrantStealthBehavior.cpp
|   |   |   |   |   |   |   +---InstantDeathBehavior.cpp
|   |   |   |   |   |   |   +---JetSlowDeathBehavior.cpp
|   |   |   |   |   |   |   +---MinefieldBehavior.cpp
|   |   |   |   |   |   |   +---NeutonBlastBehavior.cpp
|   |   |   |   |   |   |   +---OverchargeBehavior.cpp
|   |   |   |   |   |   |   +---ParkingPlaceBehavior.cpp
|   |   |   |   |   |   |   +---PoisonedBehavior.cpp
|   |   |   |   |   |   |   +---POWTruckBehavior.cpp
|   |   |   |   |   |   |   +---PrisonBehavior.cpp
|   |   |   |   |   |   |   +---PropagandaCenterBehavior.cpp
|   |   |   |   |   |   |   +---PropagandaTowerBehavior.cpp
|   |   |   |   |   |   |   +---RebuildHoleBehavior.cpp
|   |   |   |   |   |   |   +---SlowDeathBehavior.cpp
|   |   |   |   |   |   |   +---SpawnBehavior.cpp
|   |   |   |   |   |   |   +---SupplyWarehouseCripplingBehavior.cpp
|   |   |   |   |   |   |   `---TechBuildingBehavior.cpp
|   |   |   |   |   |   +---Body
|   |   |   |   |   |   |   +---ActiveBody.cpp
|   |   |   |   |   |   |   +---BodyModule.cpp
|   |   |   |   |   |   |   +---HighlanderBody.cpp
|   |   |   |   |   |   |   +---HiveStructureBody.cpp
|   |   |   |   |   |   |   +---ImmortalBody.cpp
|   |   |   |   |   |   |   +---InactiveBody.cpp
|   |   |   |   |   |   |   +---StructureBody.cpp
|   |   |   |   |   |   |   `---UndeadBody.cpp
|   |   |   |   |   |   +---Collide
|   |   |   |   |   |   |   +---CrateCollide
|   |   |   |   |   |   |   |   +---ConvertToCarBombCrateCollide.cpp
|   |   |   |   |   |   |   |   +---ConvertToHijackedVehicleCrateCollide.cpp
|   |   |   |   |   |   |   |   +---CrateCollide.cpp
|   |   |   |   |   |   |   |   +---HealCrateCollide.cpp
|   |   |   |   |   |   |   |   +---MoneyCrateCollide.cpp
|   |   |   |   |   |   |   |   +---SabotageCommandCenterCrateCollide.cpp
|   |   |   |   |   |   |   |   +---SabotageFakeBuilding.cpp
|   |   |   |   |   |   |   |   +---SabotageInternetCenterCrateCollide.cpp
|   |   |   |   |   |   |   |   +---SabotageMilitaryFactoryCrateCollide.cpp
|   |   |   |   |   |   |   |   +---SabotagePowerPlantCrateCollide.cpp
|   |   |   |   |   |   |   |   +---SabotageSuperweaponCrateCollide.cpp
|   |   |   |   |   |   |   |   +---SabotageSupplyCenterCrateCollide.cpp
|   |   |   |   |   |   |   |   +---SabotageSupplyDropzoneCrateCollide.cpp
|   |   |   |   |   |   |   |   +---SalvageCrateCollide.cpp
|   |   |   |   |   |   |   |   +---ShroudCrateCollide.cpp
|   |   |   |   |   |   |   |   +---UnitCrateCollide.cpp
|   |   |   |   |   |   |   |   `---VeterancyCrateCollide.cpp
|   |   |   |   |   |   |   +---CollideModule.cpp
|   |   |   |   |   |   |   +---FireWeaponCollide.cpp
|   |   |   |   |   |   |   `---SquishCollide.cpp
|   |   |   |   |   |   +---Contain
|   |   |   |   |   |   |   +---CaveContain.cpp
|   |   |   |   |   |   |   +---GarrisonContain.cpp
|   |   |   |   |   |   |   +---HealContain.cpp
|   |   |   |   |   |   |   +---HelixContain.cpp
|   |   |   |   |   |   |   +---InternetHackContain.cpp
|   |   |   |   |   |   |   +---MobNexusContain.cpp
|   |   |   |   |   |   |   +---OpenContain.cpp
|   |   |   |   |   |   |   +---OverlordContain.cpp
|   |   |   |   |   |   |   +---ParachuteContain.cpp
|   |   |   |   |   |   |   +---RailedTransportContain.cpp
|   |   |   |   |   |   |   +---RiderChangeContain.cpp
|   |   |   |   |   |   |   +---TransportContain.cpp
|   |   |   |   |   |   |   `---TunnelContain.cpp
|   |   |   |   |   |   +---Create
|   |   |   |   |   |   |   +---CreateModule.cpp
|   |   |   |   |   |   |   +---GrantUpgradeCreate.cpp
|   |   |   |   |   |   |   +---LockWeaponCreate.cpp
|   |   |   |   |   |   |   +---PreorderCreate.cpp
|   |   |   |   |   |   |   +---SpecialPowerCreate.cpp
|   |   |   |   |   |   |   +---SupplyCenterCreate.cpp
|   |   |   |   |   |   |   +---SupplyWarehouseCreate.cpp
|   |   |   |   |   |   |   `---VeterancyGainCreate.cpp
|   |   |   |   |   |   +---Damage
|   |   |   |   |   |   |   +---BoneFXDamage.cpp
|   |   |   |   |   |   |   +---DamageModule.cpp
|   |   |   |   |   |   |   `---TransitionDamageFX.cpp
|   |   |   |   |   |   +---Destroy
|   |   |   |   |   |   |   `---DestroyModule.cpp
|   |   |   |   |   |   +---Die
|   |   |   |   |   |   |   +---CreateCrateDie.cpp
|   |   |   |   |   |   |   +---CreateObjectDie.cpp
|   |   |   |   |   |   |   +---CrushDie.cpp
|   |   |   |   |   |   |   +---DamDie.cpp
|   |   |   |   |   |   |   +---DestroyDie.cpp
|   |   |   |   |   |   |   +---DieModule.cpp
|   |   |   |   |   |   |   +---EjectPilotDie.cpp
|   |   |   |   |   |   |   +---FXListDie.cpp
|   |   |   |   |   |   |   +---KeepObjectDie.cpp
|   |   |   |   |   |   |   +---RebuildHoleExposeDie.cpp
|   |   |   |   |   |   |   +---SpecialPowerCompletionDie.cpp
|   |   |   |   |   |   |   `---UpgradeDie.cpp
|   |   |   |   |   |   +---Helper
|   |   |   |   |   |   |   +---ObjectDefectionHelper.cpp
|   |   |   |   |   |   |   +---ObjectHelper.cpp
|   |   |   |   |   |   |   +---ObjectRepulsorHelper.cpp
|   |   |   |   |   |   |   +---ObjectSMCHelper.cpp
|   |   |   |   |   |   |   +---ObjectWeaponStatusHelper.cpp
|   |   |   |   |   |   |   +---StatusDamageHelper.cpp
|   |   |   |   |   |   |   +---SubdualDamageHelper.cpp
|   |   |   |   |   |   |   `---TempWeaponBonusHelper.cpp
|   |   |   |   |   |   +---SpecialPower
|   |   |   |   |   |   |   +---BaikonurLaunchPower.cpp
|   |   |   |   |   |   |   +---CashBountyPower.cpp
|   |   |   |   |   |   |   +---CashHackSpecialPower.cpp
|   |   |   |   |   |   |   +---CleanupAreaPower.cpp
|   |   |   |   |   |   |   +---DefectorSpecialPower.cpp
|   |   |   |   |   |   |   +---DemoralizeSpecialPower.cpp
|   |   |   |   |   |   |   +---FireWeaponPower.cpp
|   |   |   |   |   |   |   +---OCLSpecialPower.cpp
|   |   |   |   |   |   |   +---SpecialAbility.cpp
|   |   |   |   |   |   |   +---SpecialPowerModule.cpp
|   |   |   |   |   |   |   `---SpyVisionSpecialPower.cpp
|   |   |   |   |   |   +---Update
|   |   |   |   |   |   |   +---AIUpdate
|   |   |   |   |   |   |   |   +---AssaultTransportAIUpdate.cpp
|   |   |   |   |   |   |   |   +---ChinookAIUpdate.cpp
|   |   |   |   |   |   |   |   +---DeliverPayloadAIUpdate.cpp
|   |   |   |   |   |   |   |   +---DeployStyleAIUpdate.cpp
|   |   |   |   |   |   |   |   +---DozerAIUpdate.cpp
|   |   |   |   |   |   |   |   +---HackInternetAIUpdate.cpp
|   |   |   |   |   |   |   |   +---JetAIUpdate.cpp
|   |   |   |   |   |   |   |   +---MissileAIUpdate.cpp
|   |   |   |   |   |   |   |   +---POWTruckAIUpdate.cpp
|   |   |   |   |   |   |   |   +---RailedTransportAIUpdate.cpp
|   |   |   |   |   |   |   |   +---RailroadGuideAIUpdate.cpp
|   |   |   |   |   |   |   |   +---SupplyTruckAIUpdate.cpp
|   |   |   |   |   |   |   |   +---TransportAIUpdate.cpp
|   |   |   |   |   |   |   |   +---WanderAIUpdate.cpp
|   |   |   |   |   |   |   |   `---WorkerAIUpdate.cpp
|   |   |   |   |   |   |   +---DockUpdate
|   |   |   |   |   |   |   |   +---DockUpdate.cpp
|   |   |   |   |   |   |   |   +---PrisonDockUpdate.cpp
|   |   |   |   |   |   |   |   +---RailedTransportDockUpdate.cpp
|   |   |   |   |   |   |   |   +---RepairDockUpdate.cpp
|   |   |   |   |   |   |   |   +---SupplyCenterDockUpdate.cpp
|   |   |   |   |   |   |   |   `---SupplyWarehouseDockUpdate.cpp
|   |   |   |   |   |   |   +---ProductionExitUpdate
|   |   |   |   |   |   |   |   +---DefaultProductionExitUpdate.cpp
|   |   |   |   |   |   |   |   +---QueueProductionExitUpdate.cpp
|   |   |   |   |   |   |   |   +---SpawnPointProductionExitUpdate.cpp
|   |   |   |   |   |   |   |   `---SupplyCenterProductionExitUpdate.cpp
|   |   |   |   |   |   |   +---AIUpdate.cpp
|   |   |   |   |   |   |   +---AnimationSteeringUpdate.cpp
|   |   |   |   |   |   |   +---AssistedTargetingUpdate.cpp
|   |   |   |   |   |   |   +---AutoDepositUpdate.cpp
|   |   |   |   |   |   |   +---AutoFindHealingUpdate.cpp
|   |   |   |   |   |   |   +---BaseRenerateUpdate.cpp
|   |   |   |   |   |   |   +---BattlePlanUpdate.cpp
|   |   |   |   |   |   |   +---BoneFXUpdate.cpp
|   |   |   |   |   |   |   +---CheckpointUpdate.cpp
|   |   |   |   |   |   |   +---CleanupHazardUpdate.cpp
|   |   |   |   |   |   |   +---CommandButtonHuntUpdate.cpp
|   |   |   |   |   |   |   +---DeletionUpdate.cpp
|   |   |   |   |   |   |   +---DemoTrapUpdate.cpp
|   |   |   |   |   |   |   +---DynamicGeometryInfoUpdate.cpp
|   |   |   |   |   |   |   +---DynamicShroudClearingRangeUpdate.cpp
|   |   |   |   |   |   |   +---EMPUpdate.cpp
|   |   |   |   |   |   |   +---EnemyNearUpdate.cpp
|   |   |   |   |   |   |   +---FireOCLAfterWeaponCooldownUpdate.cpp
|   |   |   |   |   |   |   +---FireSpreadUpdate.cpp
|   |   |   |   |   |   |   +---FirestormDynamicGeometryInfoUpdate.cpp
|   |   |   |   |   |   |   +---FireWeaponUpdate.cpp
|   |   |   |   |   |   |   +---FlammableUpdate.cpp
|   |   |   |   |   |   |   +---FloatUpdate.cpp
|   |   |   |   |   |   |   +---HeightDieUpdate.cpp
|   |   |   |   |   |   |   +---HelicopterSlowDeathUpdate.cpp
|   |   |   |   |   |   |   +---HijackerUpdate.cpp
|   |   |   |   |   |   |   +---HordeUpdate.cpp
|   |   |   |   |   |   |   +---LaserUpdate.cpp
|   |   |   |   |   |   |   +---LifetimeUpdate.cpp
|   |   |   |   |   |   |   +---MissileLauncherBuildingUpdate.cpp
|   |   |   |   |   |   |   +---MobMemberSlavedUpdate.cpp
|   |   |   |   |   |   |   +---NeutronMissileSlowDeathUpdate.cpp
|   |   |   |   |   |   |   +---NeutronMissileUpdate.cpp
|   |   |   |   |   |   |   +---OCLUpdate.cpp
|   |   |   |   |   |   |   +---ParticleUplinkCannonUpdate.cpp
|   |   |   |   |   |   |   +---PhysicsUpdate.cpp
|   |   |   |   |   |   |   +---PilotFindVehicleUpdate.cpp
|   |   |   |   |   |   |   +---PointDefenseLaserUpdate.cpp
|   |   |   |   |   |   |   +---PowerPlantUpdate.cpp
|   |   |   |   |   |   |   +---ProductionUpdate.cpp
|   |   |   |   |   |   |   +---ProjectileStreamUpdate.cpp
|   |   |   |   |   |   |   +---ProneUpdate.cpp
|   |   |   |   |   |   |   +---RadarUpdate.cpp
|   |   |   |   |   |   |   +---RadiusDecalUpdate.cpp
|   |   |   |   |   |   |   +---SlavedUpdate.cpp
|   |   |   |   |   |   |   +---SmartBombTargetHomingUpdate.cpp
|   |   |   |   |   |   |   +---SpecialAbilityUpdate.cpp
|   |   |   |   |   |   |   +---SpecialPowerUpdateModule.cpp
|   |   |   |   |   |   |   +---SpectreGunshipDeploymentUpdate.cpp
|   |   |   |   |   |   |   +---SpectreGunshipUpdate.cpp
|   |   |   |   |   |   |   +---SpyVisionUpdate.cpp
|   |   |   |   |   |   |   +---StealthDetectorUpdate.cpp
|   |   |   |   |   |   |   +---StealthUpdate.cpp
|   |   |   |   |   |   |   +---StickyBombUpdate.cpp
|   |   |   |   |   |   |   +---StructureCollapseUpdate.cpp
|   |   |   |   |   |   |   +---StructureToppleUpdate.cpp
|   |   |   |   |   |   |   +---TensileFormationUpdate.cpp
|   |   |   |   |   |   |   +---ToppleUpdate.cpp
|   |   |   |   |   |   |   +---UpdateModule.cpp
|   |   |   |   |   |   |   +---WaveGuideUpdate.cpp
|   |   |   |   |   |   |   `---WeaponBonusUpdate.cpp
|   |   |   |   |   |   +---Upgrade
|   |   |   |   |   |   |   +---ActiveShroudUpgrade.cpp
|   |   |   |   |   |   |   +---ArmorUpgrade.cpp
|   |   |   |   |   |   |   +---CommandSetUpgrade.cpp
|   |   |   |   |   |   |   +---CostModifierUpgrade.cpp
|   |   |   |   |   |   |   +---ExperienceScalarUpgrade.cpp
|   |   |   |   |   |   |   +---GrantScienceUpgrade.cpp
|   |   |   |   |   |   |   +---LocomotorSetUpgrade.cpp
|   |   |   |   |   |   |   +---MaxHealthUpgrade.cpp
|   |   |   |   |   |   |   +---ModelConditionUpgrade.cpp
|   |   |   |   |   |   |   +---ObjectCreationUpgrade.cpp
|   |   |   |   |   |   |   +---PassengersFireUpgrade.cpp
|   |   |   |   |   |   |   +---PowerPlantUpgrade.cpp
|   |   |   |   |   |   |   +---RadarUpgrade.cpp
|   |   |   |   |   |   |   +---ReplaceObjectUpgrade.cpp
|   |   |   |   |   |   |   +---StatusBitsUpgrade.cpp
|   |   |   |   |   |   |   +---StealthUpgrade.cpp
|   |   |   |   |   |   |   +---SubObjectsUpgrade.cpp
|   |   |   |   |   |   |   +---UnpauseSpecialPowerUpgrade.cpp
|   |   |   |   |   |   |   +---UpgradeModule.cpp
|   |   |   |   |   |   |   +---WeaponBonusUpgrade.cpp
|   |   |   |   |   |   |   `---WeaponSetUpgrade.cpp
|   |   |   |   |   |   +---Armor.cpp
|   |   |   |   |   |   +---ExperienceTracker.cpp
|   |   |   |   |   |   +---FiringTracker.cpp
|   |   |   |   |   |   +---GhostObject.cpp
|   |   |   |   |   |   +---Locomotor.cpp
|   |   |   |   |   |   +---Object.cpp
|   |   |   |   |   |   +---ObjectCreationList.cpp
|   |   |   |   |   |   +---ObjectTypes.cpp
|   |   |   |   |   |   +---PartitionManager.cpp
|   |   |   |   |   |   +---SimpleObjectIterator.cpp
|   |   |   |   |   |   +---Weapon.cpp
|   |   |   |   |   |   `---WeaponSet.cpp
|   |   |   |   |   +---ScriptEngine
|   |   |   |   |   |   +---ScriptActions.cpp
|   |   |   |   |   |   +---ScriptConditions.cpp
|   |   |   |   |   |   +---ScriptEngine.cpp
|   |   |   |   |   |   +---Scripts.cpp
|   |   |   |   |   |   `---VictoryConditions.cpp
|   |   |   |   |   `---System
|   |   |   |   |       +---CaveSystem.cpp
|   |   |   |   |       +---CrateSystem.cpp
|   |   |   |   |       +---Damage.cpp
|   |   |   |   |       +---GameLogic.cpp
|   |   |   |   |       +---GameLogicDispatch.cpp
|   |   |   |   |       `---RankInfo.cpp
|   |   |   |   +---GameNetwork
|   |   |   |   |   +---GameSpy
|   |   |   |   |   |   +---Thread
|   |   |   |   |   |   |   +---BuddyThread.cpp
|   |   |   |   |   |   |   +---GameResultsThread.cpp
|   |   |   |   |   |   |   +---PeerThread.cpp
|   |   |   |   |   |   |   +---PersistentStorageThread.cpp
|   |   |   |   |   |   |   +---PingThread.cpp
|   |   |   |   |   |   |   `---ThreadUtils.cpp
|   |   |   |   |   |   +---Chat.cpp
|   |   |   |   |   |   +---GSConfig.cpp
|   |   |   |   |   |   +---LadderDefs.cpp
|   |   |   |   |   |   +---LobbyUtils.cpp
|   |   |   |   |   |   +---MainMenuUtils.cpp
|   |   |   |   |   |   +---PeerDefs.cpp
|   |   |   |   |   |   `---StagingRoomGameInfo.cpp
|   |   |   |   |   +---WOLBrowser
|   |   |   |   |   |   `---WebBrowser.cpp
|   |   |   |   |   +---Connection.cpp
|   |   |   |   |   +---ConnectionManager.cpp
|   |   |   |   |   +---DisconnectManager.cpp
|   |   |   |   |   +---DownloadManager.cpp
|   |   |   |   |   +---FileTransfer.cpp
|   |   |   |   |   +---FirewallHelper.cpp
|   |   |   |   |   +---FrameData.cpp
|   |   |   |   |   +---FrameDataManager.cpp
|   |   |   |   |   +---FrameMetrics.cpp
|   |   |   |   |   +---GameInfo.cpp
|   |   |   |   |   +---GameMessageParser.cpp
|   |   |   |   |   +---GameSpyChat.cpp
|   |   |   |   |   +---GameSpyGameInfo.cpp
|   |   |   |   |   +---GameSpyGP.cpp
|   |   |   |   |   +---GameSpyOverlay.cpp
|   |   |   |   |   +---GameSpyStub.cpp
|   |   |   |   |   +---GUIUtil.cpp
|   |   |   |   |   +---IPEnumeration.cpp
|   |   |   |   |   +---LANAPI.cpp
|   |   |   |   |   +---LANAPICallbacks.cpp
|   |   |   |   |   +---LANAPIhandlers.cpp
|   |   |   |   |   +---LANGameInfo.cpp
|   |   |   |   |   +---NAT.cpp
|   |   |   |   |   +---NetCommandList.cpp
|   |   |   |   |   +---NetCommandMsg.cpp
|   |   |   |   |   +---NetCommandRef.cpp
|   |   |   |   |   +---NetCommandWrapperList.cpp
|   |   |   |   |   +---NetMessageStream.cpp
|   |   |   |   |   +---NetPacket.cpp
|   |   |   |   |   +---Network.cpp
|   |   |   |   |   +---NetworkUtil.cpp
|   |   |   |   |   +---Transport.cpp
|   |   |   |   |   +---udp.cpp
|   |   |   |   |   `---User.cpp
|   |   |   |   +---Precompiled
|   |   |   |   |   `---PreRTS.cpp
|   |   |   |   `---System
|   |   |   |       `---JobSystem.cpp
|   |   |   +---CMakeLists.txt
|   |   |   `---GameEngine.dsp
|   |   +---GameEngineDevice
|   |   |   +---Include
|   |   |   |   +---Audio
|   |   |   |   |   `---IAudioDevice.h
|   |   |   |   +---Input
|   |   |   |   |   `---IInputDevice.h
|   |   |   |   +---MilesAudioDevice
|   |   |   |   |   `---MilesAudioManager.h
|   |   |   |   +---Render
|   |   |   |   |   `---IRenderDevice.h
|   |   |   |   +---Video
|   |   |   |   |   `---IVideoPlayer.h
|   |   |   |   +---VideoDevice
|   |   |   |   |   `---Bink
|   |   |   |   |       `---BinkVideoPlayer.h
|   |   |   |   +---W3DDevice
|   |   |   |   |   +---Common
|   |   |   |   |   |   +---InstanceData.h
|   |   |   |   |   |   +---IUpscaler.h
|   |   |   |   |   |   +---RenderStateCache.h
|   |   |   |   |   |   +---W3DConvert.h
|   |   |   |   |   |   +---W3DFunctionLexicon.h
|   |   |   |   |   |   +---W3DModuleFactory.h
|   |   |   |   |   |   +---W3DRadar.h
|   |   |   |   |   |   `---W3DThingFactory.h
|   |   |   |   |   +---GameClient
|   |   |   |   |   |   +---Module
|   |   |   |   |   |   |   +---W3DDebrisDraw.h
|   |   |   |   |   |   |   +---W3DDefaultDraw.h
|   |   |   |   |   |   |   +---W3DDependencyModelDraw.h
|   |   |   |   |   |   |   +---W3DLaserDraw.h
|   |   |   |   |   |   |   +---W3DModelDraw.h
|   |   |   |   |   |   |   +---W3DOverlordAircraftDraw.h
|   |   |   |   |   |   |   +---W3DOverlordTankDraw.h
|   |   |   |   |   |   |   +---W3DOverlordTruckDraw.h
|   |   |   |   |   |   |   +---W3DPoliceCarDraw.h
|   |   |   |   |   |   |   +---W3DProjectileStreamDraw.h
|   |   |   |   |   |   |   +---W3DPropDraw.h
|   |   |   |   |   |   |   +---W3DRopeDraw.h
|   |   |   |   |   |   |   +---W3DScienceModelDraw.h
|   |   |   |   |   |   |   +---W3DSupplyDraw.h
|   |   |   |   |   |   |   +---W3DTankDraw.h
|   |   |   |   |   |   |   +---W3DTankTruckDraw.h
|   |   |   |   |   |   |   +---W3DTracerDraw.h
|   |   |   |   |   |   |   +---W3DTreeDraw.h
|   |   |   |   |   |   |   `---W3DTruckDraw.h
|   |   |   |   |   |   +---BaseHeightMap.h
|   |   |   |   |   |   +---camerashakesystem.h
|   |   |   |   |   |   +---FlatHeightMap.h
|   |   |   |   |   |   +---HeightMap.h
|   |   |   |   |   |   +---TerrainTex.h
|   |   |   |   |   |   +---TileData.h
|   |   |   |   |   |   +---W3DAssetManager.h
|   |   |   |   |   |   +---W3DAssetManagerExposed.h
|   |   |   |   |   |   +---W3DBibBuffer.h
|   |   |   |   |   |   +---W3DBridgeBuffer.h
|   |   |   |   |   |   +---W3DBufferManager.h
|   |   |   |   |   |   +---W3DCustomEdging.h
|   |   |   |   |   |   +---W3DCustomScene.h
|   |   |   |   |   |   +---W3DDebugDisplay.h
|   |   |   |   |   |   +---W3DDebugIcons.h
|   |   |   |   |   |   +---W3DDisplay.h
|   |   |   |   |   |   +---W3DDisplayString.h
|   |   |   |   |   |   +---W3DDisplayStringManager.h
|   |   |   |   |   |   +---W3DDynamicLight.h
|   |   |   |   |   |   +---W3DFileSystem.h
|   |   |   |   |   |   +---W3DGadget.h
|   |   |   |   |   |   +---W3DGameClient.h
|   |   |   |   |   |   +---W3DGameFont.h
|   |   |   |   |   |   +---W3DGameWindow.h
|   |   |   |   |   |   +---W3DGameWindowManager.h
|   |   |   |   |   |   +---W3DGranny.h
|   |   |   |   |   |   +---W3DGUICallbacks.h
|   |   |   |   |   |   +---W3DInGameUI.h
|   |   |   |   |   |   +---W3DMirror.h
|   |   |   |   |   |   +---W3DMouse.h
|   |   |   |   |   |   +---W3DParticleSys.h
|   |   |   |   |   |   +---W3DPoly.h
|   |   |   |   |   |   +---W3DProjectedShadow.h
|   |   |   |   |   |   +---W3DPropBuffer.h
|   |   |   |   |   |   +---W3DRoadBuffer.h
|   |   |   |   |   |   +---W3DScene.h
|   |   |   |   |   |   +---W3DShaderManager.h
|   |   |   |   |   |   +---W3DShadow.h
|   |   |   |   |   |   +---W3DShroud.h
|   |   |   |   |   |   +---W3DSmudge.h
|   |   |   |   |   |   +---W3DSnow.h
|   |   |   |   |   |   +---W3DStatusCircle.h
|   |   |   |   |   |   +---W3DTerrainBackground.h
|   |   |   |   |   |   +---W3DTerrainTracks.h
|   |   |   |   |   |   +---W3DTerrainVisual.h
|   |   |   |   |   |   +---W3DTreeBuffer.h
|   |   |   |   |   |   +---W3DVideobuffer.h
|   |   |   |   |   |   +---W3DView.h
|   |   |   |   |   |   +---W3DVolumetricShadow.h
|   |   |   |   |   |   +---W3DWater.h
|   |   |   |   |   |   +---W3DWaterTracks.h
|   |   |   |   |   |   +---W3DWaypointBuffer.h
|   |   |   |   |   |   +---W3DWebBrowser.h
|   |   |   |   |   |   `---WorldHeightMap.h
|   |   |   |   |   `---GameLogic
|   |   |   |   |       +---W3DGameLogic.h
|   |   |   |   |       +---W3DGhostObject.h
|   |   |   |   |       `---W3DTerrainLogic.h
|   |   |   |   `---Win32Device
|   |   |   |       +---Common
|   |   |   |       |   +---Win32BIGFile.h
|   |   |   |       |   +---Win32BIGFileSystem.h
|   |   |   |       |   +---Win32CDManager.h
|   |   |   |       |   +---Win32GameEngine.h
|   |   |   |       |   +---Win32LocalFile.h
|   |   |   |       |   `---Win32LocalFileSystem.h
|   |   |   |       `---GameClient
|   |   |   |           +---Win32DIKeyboard.h
|   |   |   |           +---Win32DIMouse.h
|   |   |   |           `---Win32Mouse.h
|   |   |   +---Source
|   |   |   |   +---Audio
|   |   |   |   |   `---XAudio2Device.cpp
|   |   |   |   +---MilesAudioDevice
|   |   |   |   |   `---MilesAudioManager.cpp
|   |   |   |   +---SDL2Device
|   |   |   |   |   +---SDL2InputDevice.cpp
|   |   |   |   |   `---SDL2InputDevice.h
|   |   |   |   +---Video
|   |   |   |   |   `---FFmpegVideoPlayer.cpp
|   |   |   |   +---VideoDevice
|   |   |   |   |   `---Bink
|   |   |   |   |       `---BinkVideoPlayer.cpp
|   |   |   |   +---W3D
|   |   |   |   |   `---DX11W3DDevice.cpp
|   |   |   |   +---W3DDevice
|   |   |   |   |   +---Common
|   |   |   |   |   |   +---System
|   |   |   |   |   |   |   +---W3DFunctionLexicon.cpp
|   |   |   |   |   |   |   `---W3DRadar.cpp
|   |   |   |   |   |   +---Thing
|   |   |   |   |   |   |   +---W3DModuleFactory.cpp
|   |   |   |   |   |   |   `---W3DThingFactory.cpp
|   |   |   |   |   |   +---RenderStateCache.cpp
|   |   |   |   |   |   `---W3DConvert.cpp
|   |   |   |   |   +---GameClient
|   |   |   |   |   |   +---Drawable
|   |   |   |   |   |   |   `---Draw
|   |   |   |   |   |   |       +---W3DDebrisDraw.cpp
|   |   |   |   |   |   |       +---W3DDefaultDraw.cpp
|   |   |   |   |   |   |       +---W3DDependencyModelDraw.cpp
|   |   |   |   |   |   |       +---W3DLaserDraw.cpp
|   |   |   |   |   |   |       +---W3DModelDraw.cpp
|   |   |   |   |   |   |       +---W3DOverlordAircraftDraw.cpp
|   |   |   |   |   |   |       +---W3DOverlordTankDraw.cpp
|   |   |   |   |   |   |       +---W3DOverlordTruckDraw.cpp
|   |   |   |   |   |   |       +---W3DPoliceCarDraw.cpp
|   |   |   |   |   |   |       +---W3DProjectileStreamDraw.cpp
|   |   |   |   |   |   |       +---W3DPropDraw.cpp
|   |   |   |   |   |   |       +---W3DRopeDraw.cpp
|   |   |   |   |   |   |       +---W3DScienceModelDraw.cpp
|   |   |   |   |   |   |       +---W3DSupplyDraw.cpp
|   |   |   |   |   |   |       +---W3DTankDraw.cpp
|   |   |   |   |   |   |       +---W3DTankTruckDraw.cpp
|   |   |   |   |   |   |       +---W3DTracerDraw.cpp
|   |   |   |   |   |   |       +---W3DTreeDraw.cpp
|   |   |   |   |   |   |       `---W3DTruckDraw.cpp
|   |   |   |   |   |   +---GUI
|   |   |   |   |   |   |   +---Gadget
|   |   |   |   |   |   |   |   +---W3DCheckBox.cpp
|   |   |   |   |   |   |   |   +---W3DComboBox.cpp
|   |   |   |   |   |   |   |   +---W3DHorizontalSlider.cpp
|   |   |   |   |   |   |   |   +---W3DListBox.cpp
|   |   |   |   |   |   |   |   +---W3DProgressBar.cpp
|   |   |   |   |   |   |   |   +---W3DPushButton.cpp
|   |   |   |   |   |   |   |   +---W3DRadioButton.cpp
|   |   |   |   |   |   |   |   +---W3DStaticText.cpp
|   |   |   |   |   |   |   |   +---W3DTabControl.cpp
|   |   |   |   |   |   |   |   +---W3DTextEntry.cpp
|   |   |   |   |   |   |   |   `---W3DVerticalSlider.cpp
|   |   |   |   |   |   |   +---GUICallbacks
|   |   |   |   |   |   |   |   +---W3DControlBar.cpp
|   |   |   |   |   |   |   |   +---W3DMainMenu.cpp
|   |   |   |   |   |   |   |   `---W3DMOTD.cpp
|   |   |   |   |   |   |   +---W3DGameFont.cpp
|   |   |   |   |   |   |   +---W3DGameWindow.cpp
|   |   |   |   |   |   |   `---W3DGameWindowManager.cpp
|   |   |   |   |   |   +---Shaders
|   |   |   |   |   |   |   +---fterrain.nvp
|   |   |   |   |   |   |   +---fterrain0.nvp
|   |   |   |   |   |   |   +---fterrainnoise.nvp
|   |   |   |   |   |   |   +---fterrainnoise2.nvp
|   |   |   |   |   |   |   +---invmonochrome.nvp
|   |   |   |   |   |   |   +---monochrome.nvp
|   |   |   |   |   |   |   +---motionblur.nvp
|   |   |   |   |   |   |   +---MotionBlur.nvv
|   |   |   |   |   |   |   +---roadnoise2.nvp
|   |   |   |   |   |   |   +---terrain.nvp
|   |   |   |   |   |   |   +---terrainnoise.nvp
|   |   |   |   |   |   |   +---terrainnoise2.nvp
|   |   |   |   |   |   |   +---Trees.nvp
|   |   |   |   |   |   |   `---Trees.nvv
|   |   |   |   |   |   +---Shadow
|   |   |   |   |   |   |   +---W3DBufferManager.cpp
|   |   |   |   |   |   |   +---W3DProjectedShadow.cpp
|   |   |   |   |   |   |   +---W3DShadow.cpp
|   |   |   |   |   |   |   `---W3DVolumetricShadow.cpp
|   |   |   |   |   |   +---Water
|   |   |   |   |   |   |   +---W3DWater.cpp
|   |   |   |   |   |   |   +---W3DWaterTracks.cpp
|   |   |   |   |   |   |   +---wave.nvp
|   |   |   |   |   |   |   `---wave.nvv
|   |   |   |   |   |   +---BaseHeightMap.cpp
|   |   |   |   |   |   +---camerashakesystem.cpp
|   |   |   |   |   |   +---FlatHeightMap.cpp
|   |   |   |   |   |   +---HeightMap.cpp
|   |   |   |   |   |   +---TerrainTex.cpp
|   |   |   |   |   |   +---TileData.cpp
|   |   |   |   |   |   +---W3DAssetManager.cpp
|   |   |   |   |   |   +---W3DAssetManagerExposed.cpp
|   |   |   |   |   |   +---W3DBibBuffer.cpp
|   |   |   |   |   |   +---W3DBridgeBuffer.cpp
|   |   |   |   |   |   +---W3DCustomEdging.cpp
|   |   |   |   |   |   +---W3DDebugDisplay.cpp
|   |   |   |   |   |   +---W3DDebugIcons.cpp
|   |   |   |   |   |   +---W3DDisplay.cpp
|   |   |   |   |   |   +---W3DDisplayString.cpp
|   |   |   |   |   |   +---W3DDisplayStringManager.cpp
|   |   |   |   |   |   +---W3DDynamicLight.cpp
|   |   |   |   |   |   +---W3DFileSystem.cpp
|   |   |   |   |   |   +---W3DGameClient.cpp
|   |   |   |   |   |   +---W3DGranny.cpp
|   |   |   |   |   |   +---W3DInGameUI.cpp
|   |   |   |   |   |   +---W3DMouse.cpp
|   |   |   |   |   |   +---W3DParticleSys.cpp
|   |   |   |   |   |   +---W3DPoly.cpp
|   |   |   |   |   |   +---W3DPropBuffer.cpp
|   |   |   |   |   |   +---W3DRoadBuffer.cpp
|   |   |   |   |   |   +---W3DScene.cpp
|   |   |   |   |   |   +---W3DShaderManager.cpp
|   |   |   |   |   |   +---W3DShroud.cpp
|   |   |   |   |   |   +---W3DSmudge.cpp
|   |   |   |   |   |   +---W3DSnow.cpp
|   |   |   |   |   |   +---W3DStatusCircle.cpp
|   |   |   |   |   |   +---W3DTerrainBackground.cpp
|   |   |   |   |   |   +---W3DTerrainTracks.cpp
|   |   |   |   |   |   +---W3DTerrainVisual.cpp
|   |   |   |   |   |   +---W3DTreeBuffer.cpp
|   |   |   |   |   |   +---W3DVideoBuffer.cpp
|   |   |   |   |   |   +---W3DView.cpp
|   |   |   |   |   |   +---W3dWaypointBuffer.cpp
|   |   |   |   |   |   +---W3DWebBrowser.cpp
|   |   |   |   |   |   `---WorldHeightMap.cpp
|   |   |   |   |   `---GameLogic
|   |   |   |   |       +---W3DGameLogic.cpp
|   |   |   |   |       +---W3DGhostObject.cpp
|   |   |   |   |       `---W3DTerrainLogic.cpp
|   |   |   |   `---Win32Device
|   |   |   |       +---Common
|   |   |   |       |   +---Win32BIGFile.cpp
|   |   |   |       |   +---Win32BIGFileSystem.cpp
|   |   |   |       |   +---Win32CDManager.cpp
|   |   |   |       |   +---Win32GameEngine.cpp
|   |   |   |       |   +---Win32LocalFile.cpp
|   |   |   |       |   +---Win32LocalFileSystem.cpp
|   |   |   |       |   `---Win32OSDisplay.cpp
|   |   |   |       `---GameClient
|   |   |   |           +---Win32DIKeyboard.cpp
|   |   |   |           +---Win32DIMouse.cpp
|   |   |   |           `---Win32Mouse.cpp
|   |   |   +---CMakeLists.txt
|   |   |   `---GameEngineDevice.dsp
|   |   +---GameNetwork
|   |   |   +---Include
|   |   |   |   `---Common
|   |   |   `---CMakeLists.txt
|   |   +---Libraries
|   |   |   +---Include
|   |   |   |   +---dx8stub
|   |   |   |   +---Granny
|   |   |   |   |   `---.gitignore
|   |   |   |   +---Lib
|   |   |   |   |   +---BaseType.h
|   |   |   |   |   `---trig.h
|   |   |   |   +---MSS
|   |   |   |   |   `---.gitignore
|   |   |   |   +---rts
|   |   |   |   |   +---debug.h
|   |   |   |   |   `---profile.h
|   |   |   |   +---CrossPlatform.h
|   |   |   |   +---D3dx8math.h
|   |   |   |   +---D3DXCompat.h
|   |   |   |   +---dx8stub.h
|   |   |   |   +---dxfile.h
|   |   |   |   `---gnu_regex.h
|   |   |   +---Lib
|   |   |   |   `---.gitignore
|   |   |   `---Source
|   |   |       +---Benchmark
|   |   |       |   +---Benchmark.dsp
|   |   |       |   +---benchmark.h
|   |   |       |   `---CMakeLists.txt
|   |   |       +---Compression
|   |   |       |   +---CompLibHeader
|   |   |       |   |   `---lzhl.h
|   |   |       |   +---EAC
|   |   |       |   |   +---btreeabout.cpp
|   |   |       |   |   +---btreecodex.h
|   |   |       |   |   +---btreedecode.cpp
|   |   |       |   |   +---btreeencode.cpp
|   |   |       |   |   +---codex.h
|   |   |       |   |   +---gimex.h
|   |   |       |   |   +---huffabout.cpp
|   |   |       |   |   +---huffcodex.h
|   |   |       |   |   +---huffdecode.cpp
|   |   |       |   |   +---huffencode.cpp
|   |   |       |   |   +---refabout.cpp
|   |   |       |   |   +---refcodex.h
|   |   |       |   |   +---refdecode.cpp
|   |   |       |   |   `---refencode.cpp
|   |   |       |   +---LZHCompress
|   |   |       |   |   +---CompLibHeader
|   |   |       |   |   |   `---.gitignore
|   |   |       |   |   +---CompLibSource
|   |   |       |   |   |   `---.gitignore
|   |   |       |   |   +---NoxCompress.cpp
|   |   |       |   |   `---NoxCompress.h
|   |   |       |   +---ZLib
|   |   |       |   |   +---.gitignore
|   |   |       |   |   `---zlib.h
|   |   |       |   +---CMakeLists.txt
|   |   |       |   +---Compression.dsp
|   |   |       |   +---Compression.h
|   |   |       |   `---CompressionManager.cpp
|   |   |       +---debug
|   |   |       |   +---debug_dlg
|   |   |       |   |   +---debug_dlg.cpp
|   |   |       |   |   +---debug_dlg.dsp
|   |   |       |   |   +---debug_dlg.rc
|   |   |       |   |   `---resource.h
|   |   |       |   +---netserv
|   |   |       |   |   +---netserv.cpp
|   |   |       |   |   `---netserv.dsp
|   |   |       |   +---test1
|   |   |       |   |   +---test1.cpp
|   |   |       |   |   `---test1.dsp
|   |   |       |   +---test2
|   |   |       |   |   +---default.dbgcmd
|   |   |       |   |   +---resource.h
|   |   |       |   |   +---StdAfx.cpp
|   |   |       |   |   +---StdAfx.h
|   |   |       |   |   +---test2.cpp
|   |   |       |   |   +---test2.dsp
|   |   |       |   |   `---test2.rc
|   |   |       |   +---test3
|   |   |       |   |   +---test3.cpp
|   |   |       |   |   `---test3.dsp
|   |   |       |   +---test4
|   |   |       |   |   +---test4.cpp
|   |   |       |   |   `---test4.dsp
|   |   |       |   +---test5
|   |   |       |   |   +---test5.cpp
|   |   |       |   |   `---test5.dsp
|   |   |       |   +---test6
|   |   |       |   |   +---test6.cpp
|   |   |       |   |   `---test6.dsp
|   |   |       |   +---_pch.cpp
|   |   |       |   +---_pch.h
|   |   |       |   +---CMakeLists.txt
|   |   |       |   +---compile_doxygen.bat
|   |   |       |   +---debug_cmd.cpp
|   |   |       |   +---debug_cmd.h
|   |   |       |   +---debug_debug.cpp
|   |   |       |   +---debug_debug.h
|   |   |       |   +---debug_doc.h
|   |   |       |   +---debug_except.cpp
|   |   |       |   +---debug_getdefaultcommands.cpp
|   |   |       |   +---debug_internal.cpp
|   |   |       |   +---debug_io_con.cpp
|   |   |       |   +---debug_io_flat.cpp
|   |   |       |   +---debug_io_net.cpp
|   |   |       |   +---debug_io_ods.cpp
|   |   |       |   +---debug_io.h
|   |   |       |   +---debug_macro.h
|   |   |       |   +---debug_purecall.cpp
|   |   |       |   +---debug_stack.cpp
|   |   |       |   +---debug_stack.h
|   |   |       |   +---debug_stack.inl
|   |   |       |   +---debug.cpp
|   |   |       |   +---debug.dox
|   |   |       |   +---debug.dsp
|   |   |       |   +---debug.dsw
|   |   |       |   +---debug.h
|   |   |       |   +---internal_except.h
|   |   |       |   +---internal_io.h
|   |   |       |   +---internal.h
|   |   |       |   `---rc_exception.inl
|   |   |       +---DX90SDK
|   |   |       |   `---.gitignore
|   |   |       +---EABrowserDispatch
|   |   |       |   +---BrowserDispatch.idl
|   |   |       |   `---EABrowserDispatch.dsp
|   |   |       +---GameSpy
|   |   |       |   +---.gitignore
|   |   |       |   +---CMakeLists.txt
|   |   |       |   `---GameSpyStub.h
|   |   |       +---max4sdk
|   |   |       |   `---.gitignore
|   |   |       +---profile
|   |   |       |   +---test1
|   |   |       |   |   +---test1.cpp
|   |   |       |   |   `---test1.dsp
|   |   |       |   +---_pch.cpp
|   |   |       |   +---_pch.h
|   |   |       |   +---CMakeLists.txt
|   |   |       |   +---compile_doxygen.bat
|   |   |       |   +---internal_cmd.h
|   |   |       |   +---internal_funclevel.h
|   |   |       |   +---internal_highlevel.h
|   |   |       |   +---internal_result.h
|   |   |       |   +---internal.h
|   |   |       |   +---profile_cmd.cpp
|   |   |       |   +---profile_doc.h
|   |   |       |   +---profile_funclevel.cpp
|   |   |       |   +---profile_funclevel.h
|   |   |       |   +---profile_highlevel.cpp
|   |   |       |   +---profile_highlevel.h
|   |   |       |   +---profile_priv.dox
|   |   |       |   +---profile_result.cpp
|   |   |       |   +---profile_result.h
|   |   |       |   +---profile.cpp
|   |   |       |   +---profile.dox
|   |   |       |   +---profile.dsp
|   |   |       |   +---profile.dsw
|   |   |       |   `---profile.h
|   |   |       +---STLport-4.5.3
|   |   |       |   `---.gitignore
|   |   |       +---WPAudio
|   |   |       |   +---AUD_Assert.cpp
|   |   |       |   +---AUD_Attributes.cpp
|   |   |       |   +---AUD_Cache.cpp
|   |   |       |   +---AUD_Channel.cpp
|   |   |       |   +---AUD_Device.cpp
|   |   |       |   +---AUD_DSoundDriver.cpp
|   |   |       |   +---AUD_Events.cpp
|   |   |       |   +---AUD_Level.cpp
|   |   |       |   +---AUD_List.cpp
|   |   |       |   +---AUD_Lock.cpp
|   |   |       |   +---AUD_Memory.cpp
|   |   |       |   +---AUD_Profiler.cpp
|   |   |       |   +---AUD_Source.cpp
|   |   |       |   +---AUD_StreamBuffering.cpp
|   |   |       |   +---AUD_Streamer.cpp
|   |   |       |   +---AUD_Time.cpp
|   |   |       |   +---AUD_Windows.cpp
|   |   |       |   `---WPAudio.dsp
|   |   |       +---WWVegas
|   |   |       |   +---Miles6
|   |   |       |   |   `---.gitignore
|   |   |       |   +---WW3D2
|   |   |       |   |   +---RequiredAssets
|   |   |       |   |   |   +---AddProjectorGradient.tga
|   |   |       |   |   |   +---Dazzle.INI
|   |   |       |   |   |   +---MultProjectorGradient.tga
|   |   |       |   |   |   +---ShatterAVel.tbl
|   |   |       |   |   |   +---ShatterPlanes0.w3d
|   |   |       |   |   |   +---ShatterVel.tbl
|   |   |       |   |   |   `---w3d_missing_texture.tga
|   |   |       |   |   +---VulkanBackend
|   |   |       |   |   |   +---CMakeLists.txt
|   |   |       |   |   |   +---VulkanRenderDevice.cpp
|   |   |       |   |   |   `---VulkanRenderDevice.h
|   |   |       |   |   +---aabtree.cpp
|   |   |       |   |   +---aabtree.h
|   |   |       |   |   +---aabtreebuilder.cpp
|   |   |       |   |   +---aabtreebuilder.h
|   |   |       |   |   +---agg_def.cpp
|   |   |       |   |   +---agg_def.h
|   |   |       |   |   +---animatedsoundmgr.cpp
|   |   |       |   |   +---animatedsoundmgr.h
|   |   |       |   |   +---animobj.cpp
|   |   |       |   |   +---animobj.h
|   |   |       |   |   +---assetmgr.cpp
|   |   |       |   |   +---assetmgr.h
|   |   |       |   |   +---assetstatus.cpp
|   |   |       |   |   +---assetstatus.h
|   |   |       |   |   +---bitmaphandler.cpp
|   |   |       |   |   +---bitmaphandler.h
|   |   |       |   |   +---bmp2d.cpp
|   |   |       |   |   +---bmp2d.h
|   |   |       |   |   +---boxrobj.cpp
|   |   |       |   |   +---boxrobj.h
|   |   |       |   |   +---bw_render.cpp
|   |   |       |   |   +---bw_render.h
|   |   |       |   |   +---bwrender.cpp
|   |   |       |   |   +---bwrender.h
|   |   |       |   |   +---camera.cpp
|   |   |       |   |   +---camera.h
|   |   |       |   |   +---classid.h
|   |   |       |   |   +---CMakeLists.txt
|   |   |       |   |   +---collect.cpp
|   |   |       |   |   +---collect.h
|   |   |       |   |   +---colorspace.h
|   |   |       |   |   +---coltest.cpp
|   |   |       |   |   +---coltest.h
|   |   |       |   |   +---coltype.h
|   |   |       |   |   +---composite.cpp
|   |   |       |   |   +---composite.h
|   |   |       |   |   +---dazzle.cpp
|   |   |       |   |   +---dazzle.h
|   |   |       |   |   +---ddsfile.cpp
|   |   |       |   |   +---ddsfile.h
|   |   |       |   |   +---decalmsh.cpp
|   |   |       |   |   +---decalmsh.h
|   |   |       |   |   +---decalsys.cpp
|   |   |       |   |   +---decalsys.h
|   |   |       |   |   +---distlod.cpp
|   |   |       |   |   +---distlod.h
|   |   |       |   |   +---dllist.h
|   |   |       |   |   +---DX8 Rationalizations.txt
|   |   |       |   |   +---DX8 Status.txt
|   |   |       |   |   +---dx8caps.cpp
|   |   |       |   |   +---dx8caps.h
|   |   |       |   |   +---dx8fvf.cpp
|   |   |       |   |   +---dx8fvf.h
|   |   |       |   |   +---dx8indexbuffer.cpp
|   |   |       |   |   +---dx8indexbuffer.h
|   |   |       |   |   +---dx8list.h
|   |   |       |   |   +---dx8polygonrenderer.cpp
|   |   |       |   |   +---dx8polygonrenderer.h
|   |   |       |   |   +---dx8renderer.cpp
|   |   |       |   |   +---dx8renderer.h
|   |   |       |   |   +---dx8rendererdebugger.cpp
|   |   |       |   |   +---dx8rendererdebugger.h
|   |   |       |   |   +---dx8texman.cpp
|   |   |       |   |   +---dx8texman.h
|   |   |       |   |   +---DX8ToolModifications.txt
|   |   |       |   |   +---dx8vertexbuffer.cpp
|   |   |       |   |   +---dx8vertexbuffer.h
|   |   |       |   |   +---dx8webbrowser.cpp
|   |   |       |   |   +---dx8webbrowser.h
|   |   |       |   |   +---dx8wrapper.cpp
|   |   |       |   |   +---dx8wrapper.h
|   |   |       |   |   +---dynamesh.cpp
|   |   |       |   |   +---dynamesh.h
|   |   |       |   |   +---font3d.cpp
|   |   |       |   |   +---font3d.h
|   |   |       |   |   +---formconv.cpp
|   |   |       |   |   +---formconv.h
|   |   |       |   |   +---FramGrab.cpp
|   |   |       |   |   +---framgrab.h
|   |   |       |   |   +---hanim.cpp
|   |   |       |   |   +---hanim.h
|   |   |       |   |   +---hanimmgr.cpp
|   |   |       |   |   +---hanimmgr.h
|   |   |       |   |   +---hcanim.cpp
|   |   |       |   |   +---hcanim.h
|   |   |       |   |   +---hlod.cpp
|   |   |       |   |   +---hlod.h
|   |   |       |   |   +---hmdldef.cpp
|   |   |       |   |   +---hmdldef.H
|   |   |       |   |   +---hmorphanim.cpp
|   |   |       |   |   +---hmorphanim.h
|   |   |       |   |   +---hrawanim.cpp
|   |   |       |   |   +---hrawanim.h
|   |   |       |   |   +---htree.cpp
|   |   |       |   |   +---htree.h
|   |   |       |   |   +---htreemgr.cpp
|   |   |       |   |   +---htreemgr.h
|   |   |       |   |   +---intersec.cpp
|   |   |       |   |   +---intersec.h
|   |   |       |   |   +---intersec.inl
|   |   |       |   |   +---inttest.h
|   |   |       |   |   +---layer.cpp
|   |   |       |   |   +---layer.h
|   |   |       |   |   +---light.cpp
|   |   |       |   |   +---light.h
|   |   |       |   |   +---lightenvironment.cpp
|   |   |       |   |   +---lightenvironment.h
|   |   |       |   |   +---line3d.cpp
|   |   |       |   |   +---line3d.h
|   |   |       |   |   +---linegrp.cpp
|   |   |       |   |   +---linegrp.h
|   |   |       |   |   +---mapper.cpp
|   |   |       |   |   +---mapper.h
|   |   |       |   |   +---MAPPERS.TXT
|   |   |       |   |   +---matinfo.cpp
|   |   |       |   |   +---matinfo.h
|   |   |       |   |   +---matpass.cpp
|   |   |       |   |   +---matpass.h
|   |   |       |   |   +---matrixmapper.cpp
|   |   |       |   |   +---matrixmapper.h
|   |   |       |   |   +---mesh.cpp
|   |   |       |   |   +---mesh.h
|   |   |       |   |   +---meshbuild.cpp
|   |   |       |   |   +---meshbuild.h
|   |   |       |   |   +---meshdam.cpp
|   |   |       |   |   +---meshdam.h
|   |   |       |   |   +---meshgeometry.cpp
|   |   |       |   |   +---meshgeometry.h
|   |   |       |   |   +---meshmatdesc.cpp
|   |   |       |   |   +---meshmatdesc.h
|   |   |       |   |   +---meshmdl.cpp
|   |   |       |   |   +---meshmdl.h
|   |   |       |   |   +---meshmdlio.cpp
|   |   |       |   |   +---metalmap.cpp
|   |   |       |   |   +---metalmap.h
|   |   |       |   |   +---missingtexture.cpp
|   |   |       |   |   +---missingtexture.h
|   |   |       |   |   +---motchan.cpp
|   |   |       |   |   +---motchan.h
|   |   |       |   |   +---nullrobj.cpp
|   |   |       |   |   +---nullrobj.h
|   |   |       |   |   +---part_buf.cpp
|   |   |       |   |   +---part_buf.h
|   |   |       |   |   +---part_emt.cpp
|   |   |       |   |   +---part_emt.h
|   |   |       |   |   +---part_ldr.cpp
|   |   |       |   |   +---part_ldr.h
|   |   |       |   |   +---pivot.cpp
|   |   |       |   |   +---pivot.h
|   |   |       |   |   +---pointgr.cpp
|   |   |       |   |   +---pointgr.h
|   |   |       |   |   +---polyinfo.cpp
|   |   |       |   |   +---polyinfo.h
|   |   |       |   |   +---pot.cpp
|   |   |       |   |   +---pot.h
|   |   |       |   |   +---predlod.cpp
|   |   |       |   |   +---predlod.h
|   |   |       |   |   +---prim_anim.cpp
|   |   |       |   |   +---prim_anim.h
|   |   |       |   |   +---projector.cpp
|   |   |       |   |   +---projector.h
|   |   |       |   |   +---proto.cpp
|   |   |       |   |   +---proto.h
|   |   |       |   |   +---proxy.h
|   |   |       |   |   +---rddesc.h
|   |   |       |   |   +---render2d.cpp
|   |   |       |   |   +---render2d.h
|   |   |       |   |   +---render2dsentence.cpp
|   |   |       |   |   +---render2dsentence.h
|   |   |       |   |   +---RenderObjectGuide.txt
|   |   |       |   |   +---renderobjectrecycler.cpp
|   |   |       |   |   +---renderobjectrecycler.h
|   |   |       |   |   +---rendobj.cpp
|   |   |       |   |   +---rendobj.h
|   |   |       |   |   +---rinfo.cpp
|   |   |       |   |   +---rinfo.h
|   |   |       |   |   +---ringobj.cpp
|   |   |       |   |   +---ringobj.h
|   |   |       |   |   +---robjlist.h
|   |   |       |   |   +---scene.cpp
|   |   |       |   |   +---scene.h
|   |   |       |   |   +---segline.cpp
|   |   |       |   |   +---segline.h
|   |   |       |   |   +---seglinerenderer.cpp
|   |   |       |   |   +---seglinerenderer.h
|   |   |       |   |   +---shader.cpp
|   |   |       |   |   +---shader.h
|   |   |       |   |   +---shattersystem.cpp
|   |   |       |   |   +---shattersystem.h
|   |   |       |   |   +---shdlib.h
|   |   |       |   |   +---snappts.cpp
|   |   |       |   |   +---snapPts.h
|   |   |       |   |   +---sortingrenderer.cpp
|   |   |       |   |   +---sortingrenderer.h
|   |   |       |   |   +---soundlibrarybridge.h
|   |   |       |   |   +---soundrobj.cpp
|   |   |       |   |   +---soundrobj.h
|   |   |       |   |   +---sphereobj.cpp
|   |   |       |   |   +---sphereobj.h
|   |   |       |   |   +---sr_util.cpp
|   |   |       |   |   +---sr_util.h
|   |   |       |   |   +---State Management.txt
|   |   |       |   |   +---static_sort_list.cpp
|   |   |       |   |   +---static_sort_list.h
|   |   |       |   |   +---statistics.cpp
|   |   |       |   |   +---statistics.h
|   |   |       |   |   +---streak.cpp
|   |   |       |   |   +---streak.h
|   |   |       |   |   +---streakRender.cpp
|   |   |       |   |   +---streakRender.h
|   |   |       |   |   +---stripoptimizer.cpp
|   |   |       |   |   +---stripoptimizer.h
|   |   |       |   |   +---surfaceclass.cpp
|   |   |       |   |   +---surfaceclass.h
|   |   |       |   |   +---texfcach.cpp
|   |   |       |   |   +---texfcach.h
|   |   |       |   |   +---texproject.cpp
|   |   |       |   |   +---texproject.h
|   |   |       |   |   +---textdraw.cpp
|   |   |       |   |   +---textdraw.h
|   |   |       |   |   +---texture.cpp
|   |   |       |   |   +---texture.h
|   |   |       |   |   +---texturefile.cpp
|   |   |       |   |   +---texturefile.h
|   |   |       |   |   +---texturefilter.cpp
|   |   |       |   |   +---texturefilter.h
|   |   |       |   |   +---textureloader.cpp
|   |   |       |   |   +---textureloader.h
|   |   |       |   |   +---texturethumbnail.cpp
|   |   |       |   |   +---texturethumbnail.h
|   |   |       |   |   +---txt.cpp
|   |   |       |   |   +---txt.h
|   |   |       |   |   +---txt2d.cpp
|   |   |       |   |   +---txt2d.h
|   |   |       |   |   +---vertmaterial.cpp
|   |   |       |   |   +---vertmaterial.h
|   |   |       |   |   +---visrasterizer.cpp
|   |   |       |   |   +---visrasterizer.h
|   |   |       |   |   +---w3d_dep.cpp
|   |   |       |   |   +---w3d_dep.h
|   |   |       |   |   +---w3d_file.h
|   |   |       |   |   +---w3d_obsolete.h
|   |   |       |   |   +---w3d_util.cpp
|   |   |       |   |   +---w3d_util.h
|   |   |       |   |   +---w3derr.h
|   |   |       |   |   +---w3dexclusionlist.cpp
|   |   |       |   |   +---w3dexclusionlist.h
|   |   |       |   |   +---ww3d.cpp
|   |   |       |   |   +---ww3d.h
|   |   |       |   |   +---ww3d2.dsp
|   |   |       |   |   +---ww3dformat.cpp
|   |   |       |   |   +---ww3dformat.h
|   |   |       |   |   +---ww3dids.h
|   |   |       |   |   `---ww3dtrig.h
|   |   |       |   +---WWAudio
|   |   |       |   |   +---AABTreeSoundCullClass.h
|   |   |       |   |   +---AudibleSound.cpp
|   |   |       |   |   +---AudibleSound.h
|   |   |       |   |   +---AudioEvents.h
|   |   |       |   |   +---AudioSaveLoad.cpp
|   |   |       |   |   +---AudioSaveLoad.h
|   |   |       |   |   +---CMakeLists.txt
|   |   |       |   |   +---FilteredSound.cpp
|   |   |       |   |   +---FilteredSound.h
|   |   |       |   |   +---Listener.cpp
|   |   |       |   |   +---Listener.h
|   |   |       |   |   +---listenerhandle.cpp
|   |   |       |   |   +---listenerhandle.h
|   |   |       |   |   +---LogicalListener.cpp
|   |   |       |   |   +---LogicalListener.h
|   |   |       |   |   +---LogicalSound.cpp
|   |   |       |   |   +---LogicalSound.h
|   |   |       |   |   +---PriorityVector.h
|   |   |       |   |   +---sound2dhandle.cpp
|   |   |       |   |   +---sound2dhandle.h
|   |   |       |   |   +---Sound3D.cpp
|   |   |       |   |   +---Sound3D.h
|   |   |       |   |   +---sound3dhandle.cpp
|   |   |       |   |   +---sound3dhandle.h
|   |   |       |   |   +---SoundBuffer.cpp
|   |   |       |   |   +---SoundBuffer.h
|   |   |       |   |   +---SoundChunkIDs.h
|   |   |       |   |   +---SoundCullObj.h
|   |   |       |   |   +---soundhandle.cpp
|   |   |       |   |   +---soundhandle.h
|   |   |       |   |   +---SoundPseudo3D.cpp
|   |   |       |   |   +---SoundPseudo3D.h
|   |   |       |   |   +---SoundScene.cpp
|   |   |       |   |   +---SoundScene.h
|   |   |       |   |   +---SoundSceneObj.cpp
|   |   |       |   |   +---SoundSceneObj.h
|   |   |       |   |   +---soundstreamhandle.cpp
|   |   |       |   |   +---soundstreamhandle.h
|   |   |       |   |   +---Threads.cpp
|   |   |       |   |   +---Threads.h
|   |   |       |   |   +---Utils.cpp
|   |   |       |   |   +---Utils.h
|   |   |       |   |   +---WWAudio.cpp
|   |   |       |   |   +---WWAudio.dsp
|   |   |       |   |   `---WWAudio.h
|   |   |       |   +---WWDebug
|   |   |       |   |   +---CMakeLists.txt
|   |   |       |   |   +---wwdebug.cpp
|   |   |       |   |   +---wwdebug.dsp
|   |   |       |   |   +---wwdebug.h
|   |   |       |   |   +---wwhack.h
|   |   |       |   |   +---wwmemlog.cpp
|   |   |       |   |   +---wwmemlog.h
|   |   |       |   |   +---wwprofile.cpp
|   |   |       |   |   `---wwprofile.h
|   |   |       |   +---WWDownload
|   |   |       |   |   +---CMakeLists.txt
|   |   |       |   |   +---Download.cpp
|   |   |       |   |   +---Download.h
|   |   |       |   |   +---DownloadDebug.h
|   |   |       |   |   +---downloaddefs.h
|   |   |       |   |   +---FTP.CPP
|   |   |       |   |   +---ftp.h
|   |   |       |   |   +---ftpdefs.h
|   |   |       |   |   +---registry.cpp
|   |   |       |   |   +---Registry.h
|   |   |       |   |   +---urlBuilder.cpp
|   |   |       |   |   +---urlBuilder.h
|   |   |       |   |   `---WWDownload.dsp
|   |   |       |   +---WWLib
|   |   |       |   |   +---_convert.cpp
|   |   |       |   |   +---_convert.h
|   |   |       |   |   +---_mono.cpp
|   |   |       |   |   +---_mono.h
|   |   |       |   |   +---_timer.cpp
|   |   |       |   |   +---_timer.h
|   |   |       |   |   +---_xmouse.h
|   |   |       |   |   +---always.h
|   |   |       |   |   +---argv.cpp
|   |   |       |   |   +---argv.h
|   |   |       |   |   +---b64pipe.cpp
|   |   |       |   |   +---b64pipe.h
|   |   |       |   |   +---b64straw.cpp
|   |   |       |   |   +---b64straw.h
|   |   |       |   |   +---base64.cpp
|   |   |       |   |   +---base64.h
|   |   |       |   |   +---bfiofile.cpp
|   |   |       |   |   +---bfiofile.h
|   |   |       |   |   +---binheap.h
|   |   |       |   |   +---bittype.h
|   |   |       |   |   +---blit.cpp
|   |   |       |   |   +---blit.h
|   |   |       |   |   +---blitblit.h
|   |   |       |   |   +---blitter.h
|   |   |       |   |   +---blowfish.cpp
|   |   |       |   |   +---blowfish.h
|   |   |       |   |   +---blowpipe.cpp
|   |   |       |   |   +---blowpipe.h
|   |   |       |   |   +---blwstraw.cpp
|   |   |       |   |   +---blwstraw.h
|   |   |       |   |   +---bool.h
|   |   |       |   |   +---borlandc.h
|   |   |       |   |   +---bound.h
|   |   |       |   |   +---BSEARCH.H
|   |   |       |   |   +---bsurface.h
|   |   |       |   |   +---buff.cpp
|   |   |       |   |   +---BUFF.H
|   |   |       |   |   +---bufffile.cpp
|   |   |       |   |   +---bufffile.h
|   |   |       |   |   +---CallbackHook.h
|   |   |       |   |   +---chunkio.cpp
|   |   |       |   |   +---chunkio.h
|   |   |       |   |   +---CMakeLists.txt
|   |   |       |   |   +---convert.cpp
|   |   |       |   |   +---Convert.h
|   |   |       |   |   +---cpudetect.cpp
|   |   |       |   |   +---cpudetect.h
|   |   |       |   |   +---crandom.h
|   |   |       |   |   +---crc.cpp
|   |   |       |   |   +---CRC.H
|   |   |       |   |   +---crcpipe.cpp
|   |   |       |   |   +---crcpipe.h
|   |   |       |   |   +---crcstraw.cpp
|   |   |       |   |   +---crcstraw.h
|   |   |       |   |   +---critsection.cpp
|   |   |       |   |   +---critsection.h
|   |   |       |   |   +---cstraw.cpp
|   |   |       |   |   +---cstraw.h
|   |   |       |   |   +---data.cpp
|   |   |       |   |   +---data.h
|   |   |       |   |   +---ddraw.cpp
|   |   |       |   |   +---dib.cpp
|   |   |       |   |   +---dib.h
|   |   |       |   |   +---draw.cpp
|   |   |       |   |   +---draw.h
|   |   |       |   |   +---dsurface.cpp
|   |   |       |   |   +---dsurface.h
|   |   |       |   |   +---Except.cpp
|   |   |       |   |   +---Except.h
|   |   |       |   |   +---FastAllocator.cpp
|   |   |       |   |   +---FastAllocator.h
|   |   |       |   |   +---ffactory.cpp
|   |   |       |   |   +---ffactory.h
|   |   |       |   |   +---fixed.cpp
|   |   |       |   |   +---fixed.h
|   |   |       |   |   +---FONT.H
|   |   |       |   |   +---gcd_lcm.cpp
|   |   |       |   |   +---gcd_lcm.h
|   |   |       |   |   +---global.h
|   |   |       |   |   +---hash.cpp
|   |   |       |   |   +---hash.h
|   |   |       |   |   +---hashcalc.h
|   |   |       |   |   +---HASHLIST.H
|   |   |       |   |   +---hashtab.h
|   |   |       |   |   +---hashtemplate.h
|   |   |       |   |   +---hsv.cpp
|   |   |       |   |   +---hsv.h
|   |   |       |   |   +---IFF.H
|   |   |       |   |   +---incdec.h
|   |   |       |   |   +---INDEX.H
|   |   |       |   |   +---ini.cpp
|   |   |       |   |   +---INI.H
|   |   |       |   |   +---inisup.h
|   |   |       |   |   +---int.cpp
|   |   |       |   |   +---INT.H
|   |   |       |   |   +---iostruct.h
|   |   |       |   |   +---jshell.cpp
|   |   |       |   |   +---keyboard.cpp
|   |   |       |   |   +---keyboard.h
|   |   |       |   |   +---LaunchWeb.cpp
|   |   |       |   |   +---LaunchWeb.h
|   |   |       |   |   +---lcw.cpp
|   |   |       |   |   +---LCW.H
|   |   |       |   |   +---lcwpipe.cpp
|   |   |       |   |   +---lcwpipe.h
|   |   |       |   |   +---LISTNODE.H
|   |   |       |   |   +---load.cpp
|   |   |       |   |   +---lzo_conf.h
|   |   |       |   |   +---lzo.cpp
|   |   |       |   |   +---lzo.h
|   |   |       |   |   +---lzo1x_c.cpp
|   |   |       |   |   +---lzo1x_d.cpp
|   |   |       |   |   +---lzo1x.h
|   |   |       |   |   +---lzoconf.h
|   |   |       |   |   +---lzopipe.cpp
|   |   |       |   |   +---lzopipe.h
|   |   |       |   |   +---lzostraw.cpp
|   |   |       |   |   +---lzostraw.h
|   |   |       |   |   +---md5.cpp
|   |   |       |   |   +---md5.h
|   |   |       |   |   +---mempool.h
|   |   |       |   |   +---misc.h
|   |   |       |   |   +---mixfile.cpp
|   |   |       |   |   +---mixfile.h
|   |   |       |   |   +---mmsys.h
|   |   |       |   |   +---mono.cpp
|   |   |       |   |   +---MONO.H
|   |   |       |   |   +---MONODRVR.H
|   |   |       |   |   +---mpmath.cpp
|   |   |       |   |   +---MPMATH.H
|   |   |       |   |   +---mpu.cpp
|   |   |       |   |   +---MPU.H
|   |   |       |   |   +---msgloop.cpp
|   |   |       |   |   +---msgloop.h
|   |   |       |   |   +---multilist.cpp
|   |   |       |   |   +---multilist.h
|   |   |       |   |   +---mutex.h
|   |   |       |   |   +---noinit.h
|   |   |       |   |   +---notifier.h
|   |   |       |   |   +---nstrdup.cpp
|   |   |       |   |   +---nstrdup.h
|   |   |       |   |   +---ntree.h
|   |   |       |   |   +---obscure.cpp
|   |   |       |   |   +---obscure.h
|   |   |       |   |   +---palette.cpp
|   |   |       |   |   +---PALETTE.H
|   |   |       |   |   +---pcx.cpp
|   |   |       |   |   +---pcx.H
|   |   |       |   |   +---pipe.cpp
|   |   |       |   |   +---PIPE.H
|   |   |       |   |   +---pk.cpp
|   |   |       |   |   +---PK.H
|   |   |       |   |   +---pkpipe.cpp
|   |   |       |   |   +---pkpipe.h
|   |   |       |   |   +---pkstraw.cpp
|   |   |       |   |   +---pkstraw.h
|   |   |       |   |   +---point.cpp
|   |   |       |   |   +---Point.h
|   |   |       |   |   +---ramfile.cpp
|   |   |       |   |   +---RAMFILE.H
|   |   |       |   |   +---random.cpp
|   |   |       |   |   +---RANDOM.H
|   |   |       |   |   +---rawfile.cpp
|   |   |       |   |   +---RAWFILE.H
|   |   |       |   |   +---rc4.cpp
|   |   |       |   |   +---rc4.h
|   |   |       |   |   +---rcfile.cpp
|   |   |       |   |   +---rcfile.h
|   |   |       |   |   +---readline.cpp
|   |   |       |   |   +---readline.h
|   |   |       |   |   +---realcrc.cpp
|   |   |       |   |   +---realcrc.h
|   |   |       |   |   +---ref_ptr.h
|   |   |       |   |   +---refcount.cpp
|   |   |       |   |   +---refcount.h
|   |   |       |   |   +---regexpr.cpp
|   |   |       |   |   +---regexpr.h
|   |   |       |   |   +---registry.cpp
|   |   |       |   |   +---registry.h
|   |   |       |   |   +---rgb.cpp
|   |   |       |   |   +---RGB.H
|   |   |       |   |   +---rle.cpp
|   |   |       |   |   +---RLE.H
|   |   |       |   |   +---rlerle.h
|   |   |       |   |   +---rndstraw.cpp
|   |   |       |   |   +---RNDSTRAW.H
|   |   |       |   |   +---rndstrng.cpp
|   |   |       |   |   +---rndstrng.h
|   |   |       |   |   +---rng.h
|   |   |       |   |   +---rsacrypt.h
|   |   |       |   |   +---sampler.cpp
|   |   |       |   |   +---sampler.h
|   |   |       |   |   +---search.h
|   |   |       |   |   +---sha.cpp
|   |   |       |   |   +---sha.h
|   |   |       |   |   +---shapeset.h
|   |   |       |   |   +---shapipe.cpp
|   |   |       |   |   +---shapipe.h
|   |   |       |   |   +---sharebuf.h
|   |   |       |   |   +---shastraw.cpp
|   |   |       |   |   +---shastraw.h
|   |   |       |   |   +---Signaler.h
|   |   |       |   |   +---simplevec.h
|   |   |       |   |   +---SLIST.H
|   |   |       |   |   +---slnode.cpp
|   |   |       |   |   +---SLNODE.H
|   |   |       |   |   +---smartptr.h
|   |   |       |   |   +---srandom.cpp
|   |   |       |   |   +---srandom.h
|   |   |       |   |   +---stimer.cpp
|   |   |       |   |   +---stimer.h
|   |   |       |   |   +---stl.h
|   |   |       |   |   +---straw.cpp
|   |   |       |   |   +---STRAW.H
|   |   |       |   |   +---strtok_r.cpp
|   |   |       |   |   +---strtok_r.h
|   |   |       |   |   +---surface.cpp
|   |   |       |   |   +---Surface.h
|   |   |       |   |   +---surfrect.h
|   |   |       |   |   +---swap.h
|   |   |       |   |   +---systimer.cpp
|   |   |       |   |   +---systimer.h
|   |   |       |   |   +---tagblock.cpp
|   |   |       |   |   +---TagBlock.h
|   |   |       |   |   +---TARGA.CPP
|   |   |       |   |   +---TARGA.H
|   |   |       |   |   +---textfile.cpp
|   |   |       |   |   +---textfile.h
|   |   |       |   |   +---tgatodxt.cpp
|   |   |       |   |   +---tgatodxt.h
|   |   |       |   |   +---thread.cpp
|   |   |       |   |   +---thread.h
|   |   |       |   |   +---timer.h
|   |   |       |   |   +---trackwin.h
|   |   |       |   |   +---trackxy.h
|   |   |       |   |   +---trect.h
|   |   |       |   |   +---trim.cpp
|   |   |       |   |   +---trim.h
|   |   |       |   |   +---uarray.h
|   |   |       |   |   +---vector.cpp
|   |   |       |   |   +---Vector.H
|   |   |       |   |   +---verchk.cpp
|   |   |       |   |   +---verchk.h
|   |   |       |   |   +---visualc.h
|   |   |       |   |   +---WATCOM.H
|   |   |       |   |   +---widestring.cpp
|   |   |       |   |   +---widestring.h
|   |   |       |   |   +---win.cpp
|   |   |       |   |   +---win.h
|   |   |       |   |   +---WWCOMUtil.cpp
|   |   |       |   |   +---WWCOMUtil.h
|   |   |       |   |   +---wwfile.cpp
|   |   |       |   |   +---WWFILE.H
|   |   |       |   |   +---wwfont.cpp
|   |   |       |   |   +---wwfont.h
|   |   |       |   |   +---wwlib.dsp
|   |   |       |   |   +---wwmouse.cpp
|   |   |       |   |   +---wwmouse.h
|   |   |       |   |   +---wwstring.cpp
|   |   |       |   |   +---wwstring.h
|   |   |       |   |   +---xmouse.h
|   |   |       |   |   +---xpipe.cpp
|   |   |       |   |   +---XPIPE.H
|   |   |       |   |   +---xstraw.cpp
|   |   |       |   |   +---XSTRAW.H
|   |   |       |   |   +---xsurface.cpp
|   |   |       |   |   `---xsurface.h
|   |   |       |   +---WWMath
|   |   |       |   |   +---aabox.cpp
|   |   |       |   |   +---aabox.h
|   |   |       |   |   +---aabtreecull.cpp
|   |   |       |   |   +---aabtreecull.h
|   |   |       |   |   +---aaplane.h
|   |   |       |   |   +---cardinalspline.cpp
|   |   |       |   |   +---cardinalspline.h
|   |   |       |   |   +---castres.h
|   |   |       |   |   +---catmullromspline.cpp
|   |   |       |   |   +---catmullromspline.h
|   |   |       |   |   +---CMakeLists.txt
|   |   |       |   |   +---colmath.cpp
|   |   |       |   |   +---colmath.h
|   |   |       |   |   +---colmathaabox.cpp
|   |   |       |   |   +---colmathaabox.h
|   |   |       |   |   +---colmathaabtri.cpp
|   |   |       |   |   +---colmathfrustum.cpp
|   |   |       |   |   +---colmathfrustum.h
|   |   |       |   |   +---colmathinlines.h
|   |   |       |   |   +---colmathline.cpp
|   |   |       |   |   +---colmathline.h
|   |   |       |   |   +---colmathobbobb.cpp
|   |   |       |   |   +---colmathobbox.cpp
|   |   |       |   |   +---colmathobbtri.cpp
|   |   |       |   |   +---colmathplane.cpp
|   |   |       |   |   +---colmathplane.h
|   |   |       |   |   +---colmathsphere.cpp
|   |   |       |   |   +---cullsys.cpp
|   |   |       |   |   +---cullsys.h
|   |   |       |   |   +---culltype.h
|   |   |       |   |   +---curve.cpp
|   |   |       |   |   +---curve.h
|   |   |       |   |   +---euler.cpp
|   |   |       |   |   +---euler.h
|   |   |       |   |   +---frustum.cpp
|   |   |       |   |   +---frustum.h
|   |   |       |   |   +---gridcull.cpp
|   |   |       |   |   +---gridcull.h
|   |   |       |   |   +---hermitespline.cpp
|   |   |       |   |   +---hermitespline.h
|   |   |       |   |   +---lineseg.cpp
|   |   |       |   |   +---lineseg.h
|   |   |       |   |   +---lookuptable.cpp
|   |   |       |   |   +---lookuptable.h
|   |   |       |   |   +---matrix3.cpp
|   |   |       |   |   +---matrix3.h
|   |   |       |   |   +---matrix3d.cpp
|   |   |       |   |   +---matrix3d.h
|   |   |       |   |   +---matrix4.cpp
|   |   |       |   |   +---matrix4.h
|   |   |       |   |   +---normalcone.h
|   |   |       |   |   +---obbox.cpp
|   |   |       |   |   +---obbox.h
|   |   |       |   |   +---ode.cpp
|   |   |       |   |   +---ode.h
|   |   |       |   |   +---plane.h
|   |   |       |   |   +---pot.cpp
|   |   |       |   |   +---pot.h
|   |   |       |   |   +---quat.cpp
|   |   |       |   |   +---quat.h
|   |   |       |   |   +---rect.h
|   |   |       |   |   +---sphere.h
|   |   |       |   |   +---tcbspline.cpp
|   |   |       |   |   +---tcbspline.h
|   |   |       |   |   +---tri.cpp
|   |   |       |   |   +---tri.h
|   |   |       |   |   +---v3_rnd.cpp
|   |   |       |   |   +---v3_rnd.h
|   |   |       |   |   +---vector2.h
|   |   |       |   |   +---vector2i.h
|   |   |       |   |   +---vector3.h
|   |   |       |   |   +---Vector3i.h
|   |   |       |   |   +---vector4.h
|   |   |       |   |   +---vehiclecurve.cpp
|   |   |       |   |   +---vehiclecurve.h
|   |   |       |   |   +---vp.cpp
|   |   |       |   |   +---vp.h
|   |   |       |   |   +---wwmath.cpp
|   |   |       |   |   +---wwmath.dsp
|   |   |       |   |   +---wwmath.h
|   |   |       |   |   `---wwmathids.h
|   |   |       |   +---WWSaveLoad
|   |   |       |   |   +---CMakeLists.txt
|   |   |       |   |   +---definition.cpp
|   |   |       |   |   +---definition.h
|   |   |       |   |   +---definitionclassids.h
|   |   |       |   |   +---definitionfactory.cpp
|   |   |       |   |   +---definitionfactory.h
|   |   |       |   |   +---definitionfactorymgr.cpp
|   |   |       |   |   +---definitionfactorymgr.h
|   |   |       |   |   +---definitionmgr.cpp
|   |   |       |   |   +---definitionmgr.h
|   |   |       |   |   +---editable.h
|   |   |       |   |   +---parameter.cpp
|   |   |       |   |   +---parameter.h
|   |   |       |   |   +---parameterlist.h
|   |   |       |   |   +---parametertypes.h
|   |   |       |   |   +---persist.h
|   |   |       |   |   +---persistfactory.cpp
|   |   |       |   |   +---persistfactory.h
|   |   |       |   |   +---pointerremap.cpp
|   |   |       |   |   +---pointerremap.h
|   |   |       |   |   +---postloadable.h
|   |   |       |   |   +---saveload.cpp
|   |   |       |   |   +---saveload.h
|   |   |       |   |   +---saveloadids.h
|   |   |       |   |   +---saveloadstatus.cpp
|   |   |       |   |   +---saveloadstatus.h
|   |   |       |   |   +---saveloadsubsystem.cpp
|   |   |       |   |   +---saveloadsubsystem.h
|   |   |       |   |   +---simpledefinitionfactory.h
|   |   |       |   |   +---simpleparameter.h
|   |   |       |   |   +---twiddler.cpp
|   |   |       |   |   +---twiddler.h
|   |   |       |   |   +---wwsaveload.cpp
|   |   |       |   |   +---wwsaveload.dsp
|   |   |       |   |   `---wwsaveload.h
|   |   |       |   +---wwshade
|   |   |       |   |   +---CMakeLists.txt
|   |   |       |   |   +---shd6bumpdiff_constants.h
|   |   |       |   |   +---shd6bumpdiff.cpp
|   |   |       |   |   +---shd6bumpdiff.h
|   |   |       |   |   +---shd6bumpdiff.vsh
|   |   |       |   |   +---shd6bumpspec_constants.h
|   |   |       |   |   +---shd6bumpspec.cpp
|   |   |       |   |   +---shd6bumpspec.h
|   |   |       |   |   +---shd6bumpspec.vsh
|   |   |       |   |   +---shd7bumpdiff_constants.h
|   |   |       |   |   +---shd7bumpdiff.cpp
|   |   |       |   |   +---shd7bumpdiff.h
|   |   |       |   |   +---shd7bumpdiffpass0.vsh
|   |   |       |   |   +---shd7bumpdiffpass1.vsh
|   |   |       |   |   +---shd7bumpspec_constants.h
|   |   |       |   |   +---shd7bumpspec.cpp
|   |   |       |   |   +---shd7bumpspec.h
|   |   |       |   |   +---shd7bumpspecpass0.vsh
|   |   |       |   |   +---shd7bumpspecpass1.vsh
|   |   |       |   |   +---shd8bumpdiff_constants.h
|   |   |       |   |   +---shd8bumpdiff.cpp
|   |   |       |   |   +---shd8bumpdiff.h
|   |   |       |   |   +---shd8bumpdiff.psh
|   |   |       |   |   +---shd8bumpdiff.vsh
|   |   |       |   |   +---shd8bumpspec_constants.h
|   |   |       |   |   +---shd8bumpspec.cpp
|   |   |       |   |   +---shd8bumpspec.h
|   |   |       |   |   +---shd8bumpspec.psh
|   |   |       |   |   +---shd8bumpspec.vsh
|   |   |       |   |   +---shd8ssbumpdiff.psh
|   |   |       |   |   +---shd8ssbumpdiff.vsh
|   |   |       |   |   +---shd8ssbumpspec.psh
|   |   |       |   |   +---shd8ssbumpspec.vsh
|   |   |       |   |   +---shdbumpdiff.cpp
|   |   |       |   |   +---shdbumpdiff.h
|   |   |       |   |   +---shdbumpspec.cpp
|   |   |       |   |   +---shdbumpspec.h
|   |   |       |   |   +---shdclassids.h
|   |   |       |   |   +---shdcubemap.cpp
|   |   |       |   |   +---shdcubemap.h
|   |   |       |   |   +---shddef.cpp
|   |   |       |   |   +---shddef.h
|   |   |       |   |   +---shddeffactory.cpp
|   |   |       |   |   +---shddeffactory.h
|   |   |       |   |   +---shddefmanager.cpp
|   |   |       |   |   +---shddefmanager.h
|   |   |       |   |   +---shddump.h
|   |   |       |   |   +---shdforcelinks.cpp
|   |   |       |   |   +---shdforcelinks.h
|   |   |       |   |   +---shdglossmask.cpp
|   |   |       |   |   +---shdglossmask.h
|   |   |       |   |   +---shdhw_constants.h
|   |   |       |   |   +---shdhwshader.cpp
|   |   |       |   |   +---shdhwshader.h
|   |   |       |   |   +---shdinterface.cpp
|   |   |       |   |   +---shdinterface.h
|   |   |       |   |   +---shdlegacyw3d.cpp
|   |   |       |   |   +---shdlegacyw3d.h
|   |   |       |   |   +---shdlib.cpp
|   |   |       |   |   +---shdloader.cpp
|   |   |       |   |   +---shdloader.h
|   |   |       |   |   +---shdmesh.cpp
|   |   |       |   |   +---shdmesh.h
|   |   |       |   |   +---shdpp.exe
|   |   |       |   |   +---shdrenderer.cpp
|   |   |       |   |   +---shdrenderer.h
|   |   |       |   |   +---shdsimple.cpp
|   |   |       |   |   +---shdsimple.h
|   |   |       |   |   +---shdsubmesh.cpp
|   |   |       |   |   +---shdsubmesh.h
|   |   |       |   |   `---wwshade.dsp
|   |   |       |   `---Wwutil
|   |   |       |       +---CMakeLists.txt
|   |   |       |       +---mathutil.cpp
|   |   |       |       +---mathutil.h
|   |   |       |       +---miscutil.cpp
|   |   |       |       +---miscutil.h
|   |   |       |       `---wwutil.dsp
|   |   |       +---template.cpp
|   |   |       `---template.h
|   |   +---Main
|   |   |   +---CMakeLists.txt
|   |   |   +---Generals.ico
|   |   |   +---resource.h
|   |   |   +---RTS.RC
|   |   |   +---WinMain.cpp
|   |   |   `---WinMain.h
|   |   +---Tools
|   |   |   +---assetcull
|   |   |   |   +---assetcull.cpp
|   |   |   |   `---assetcull.dsp
|   |   |   +---Autorun
|   |   |   |   +---ARGS.CPP
|   |   |   |   +---ARGS.H
|   |   |   |   +---arrow.cur
|   |   |   |   +---autorun.cpp
|   |   |   |   +---Autorun.dsp
|   |   |   |   +---Autorun.dsw
|   |   |   |   +---autorun.h
|   |   |   |   +---Autorun.ICO
|   |   |   |   +---AUTORUN.RC
|   |   |   |   +---CallbackHook.h
|   |   |   |   +---CDCNTRL.CPP
|   |   |   |   +---CDCNTRL.H
|   |   |   |   +---DrawButton.cpp
|   |   |   |   +---DrawButton.h
|   |   |   |   +---EZGIMEX.cpp
|   |   |   |   +---GameText.cpp
|   |   |   |   +---GameText.h
|   |   |   |   +---GETCD.CPP
|   |   |   |   +---GetCD.h
|   |   |   |   +---gimex.h
|   |   |   |   +---IGR.cpp
|   |   |   |   +---IGR.h
|   |   |   |   +---Jsupport.cpp
|   |   |   |   +---JSUPPORT.H
|   |   |   |   +---leanAndMeanAutorun.h
|   |   |   |   +---Locale_API.cpp
|   |   |   |   +---Locale_API.h
|   |   |   |   +---locale.cpp
|   |   |   |   +---locale.h
|   |   |   |   +---POINT.h
|   |   |   |   +---RECT.h
|   |   |   |   +---resource.h
|   |   |   |   +---TTFont.cpp
|   |   |   |   +---TTFont.h
|   |   |   |   +---Utils.cpp
|   |   |   |   +---Utils.h
|   |   |   |   +---ViewHTML.cpp
|   |   |   |   +---ViewHTML.h
|   |   |   |   +---WinFix.CPP
|   |   |   |   +---WinFix.H
|   |   |   |   +---Wnd_file.cpp
|   |   |   |   +---Wnd_File.h
|   |   |   |   +---WSYS_File.cpp
|   |   |   |   +---WSYS_file.h
|   |   |   |   +---WSYS_FileSystem.cpp
|   |   |   |   +---WSYS_FileSystem.h
|   |   |   |   +---WSYS_RAMFile.cpp
|   |   |   |   +---WSYS_RAMFile.h
|   |   |   |   +---WSYS_StdFile.cpp
|   |   |   |   +---WSYS_StdFile.h
|   |   |   |   +---WSYS_StdFileSystem.cpp
|   |   |   |   `---WSYS_StdFileSystem.h
|   |   |   +---Babylon
|   |   |   |   +---res
|   |   |   |   |   +---Babylon.ico
|   |   |   |   |   +---Babylon.rc2
|   |   |   |   |   +---bitmap1.bmp
|   |   |   |   |   +---noxstring.ico
|   |   |   |   |   +---noxstring.rc2
|   |   |   |   |   +---pause.bmp
|   |   |   |   |   +---paused.bmp
|   |   |   |   |   +---playd.bmp
|   |   |   |   |   +---playu.bmp
|   |   |   |   |   `---stop.bmp
|   |   |   |   +---Babylon.cpp
|   |   |   |   +---Babylon.dsp
|   |   |   |   +---Babylon.dsw
|   |   |   |   +---Babylon.h
|   |   |   |   +---Babylon.odl
|   |   |   |   +---Babylon.rc
|   |   |   |   +---Babylon.reg
|   |   |   |   +---BABYLON.XLT
|   |   |   |   +---BabylonDlg.cpp
|   |   |   |   +---BabylonDlg.h
|   |   |   |   +---bin.cpp
|   |   |   |   +---bin.h
|   |   |   |   +---DlgProxy.cpp
|   |   |   |   +---DlgProxy.h
|   |   |   |   +---excel8.cpp
|   |   |   |   +---excel8.h
|   |   |   |   +---expimp.cpp
|   |   |   |   +---expimp.h
|   |   |   |   +---ExportDlg.cpp
|   |   |   |   +---ExportDlg.h
|   |   |   |   +---fileops.cpp
|   |   |   |   +---fileops.h
|   |   |   |   +---GenerateDlg.cpp
|   |   |   |   +---GenerateDlg.h
|   |   |   |   +---iff.cpp
|   |   |   |   +---iff.h
|   |   |   |   +---list.cpp
|   |   |   |   +---list.h
|   |   |   |   +---loadsave.cpp
|   |   |   |   +---loadsave.h
|   |   |   |   +---MatchDlg.cpp
|   |   |   |   +---MatchDlg.h
|   |   |   |   +---olestring.cpp
|   |   |   |   +---olestring.h
|   |   |   |   +---ProceedDlg.cpp
|   |   |   |   +---ProceedDlg.h
|   |   |   |   +---Report.cpp
|   |   |   |   +---Report.h
|   |   |   |   +---resource.h
|   |   |   |   +---resource.hm
|   |   |   |   +---RetranslateDlg.cpp
|   |   |   |   +---RetranslateDlg.h
|   |   |   |   +---StdAfx.cpp
|   |   |   |   +---StdAfx.h
|   |   |   |   +---STRCHECK.PL
|   |   |   |   +---transcs.cpp
|   |   |   |   +---transcs.h
|   |   |   |   +---TransDB.cpp
|   |   |   |   +---TransDB.h
|   |   |   |   +---VerifyDlg.cpp
|   |   |   |   +---VerifyDlg.h
|   |   |   |   +---VerifyTextDlg.cpp
|   |   |   |   +---VerifyTextDlg.h
|   |   |   |   +---ViewDBsDlg.cpp
|   |   |   |   +---VIEWDBSII.cpp
|   |   |   |   +---VIEWDBSII.h
|   |   |   |   +---XLStuff.cpp
|   |   |   |   `---XLStuff.h
|   |   |   +---buildVersionUpdate
|   |   |   |   +---buildVersionUpdate.cpp
|   |   |   |   `---buildVersionUpdate.dsp
|   |   |   +---Compress
|   |   |   |   +---Compress.cpp
|   |   |   |   `---Compress.dsp
|   |   |   +---CRCDiff
|   |   |   |   +---bottom.html
|   |   |   |   +---CRCDiff.cpp
|   |   |   |   +---CRCDiff.dsp
|   |   |   |   +---debug.cpp
|   |   |   |   +---debug.h
|   |   |   |   +---expander.cpp
|   |   |   |   +---expander.h
|   |   |   |   +---KVPair.cpp
|   |   |   |   +---KVPair.h
|   |   |   |   +---misc.h
|   |   |   |   +---row.html
|   |   |   |   +---style.css
|   |   |   |   `---top.html
|   |   |   +---DebugWindow
|   |   |   |   +---res
|   |   |   |   |   `---DebugWindow.rc2
|   |   |   |   +---DebugWindow.cpp
|   |   |   |   +---DebugWindow.def
|   |   |   |   +---DebugWindow.dsp
|   |   |   |   +---DebugWindow.dsw
|   |   |   |   +---DebugWindow.h
|   |   |   |   +---DebugWindow.rc
|   |   |   |   +---DebugWindowDialog.cpp
|   |   |   |   +---DebugWindowDialog.h
|   |   |   |   +---DebugWindowExport.h
|   |   |   |   +---post-build.bat
|   |   |   |   +---Resource.h
|   |   |   |   +---StdAfx.cpp
|   |   |   |   `---StdAfx.h
|   |   |   +---GUIEdit
|   |   |   |   +---Include
|   |   |   |   |   +---DialogProc.h
|   |   |   |   |   +---EditWindow.h
|   |   |   |   |   +---GUIEdit.h
|   |   |   |   |   +---GUIEditColor.h
|   |   |   |   |   +---GUIEditDisplay.h
|   |   |   |   |   +---GUIEditWindowManager.h
|   |   |   |   |   +---HierarchyView.h
|   |   |   |   |   +---LayoutScheme.h
|   |   |   |   |   +---Properties.h
|   |   |   |   |   `---WinMain.h
|   |   |   |   +---Resource
|   |   |   |   |   +---GUIEdit.ico
|   |   |   |   |   +---GUIEdit.rc
|   |   |   |   |   +---resource.h
|   |   |   |   |   `---small.ico
|   |   |   |   +---Source
|   |   |   |   |   +---Dialog Procedures
|   |   |   |   |   |   +---CallbackEditor.cpp
|   |   |   |   |   |   +---CheckBoxProperties.cpp
|   |   |   |   |   |   +---ColorDialog.cpp
|   |   |   |   |   |   +---ComboBoxProperties.cpp
|   |   |   |   |   |   +---GenericProperties.cpp
|   |   |   |   |   |   +---GridSettings.cpp
|   |   |   |   |   |   +---ListboxProperties.cpp
|   |   |   |   |   |   +---NewLayoutDialog.cpp
|   |   |   |   |   |   +---ProgressBarProperties.cpp
|   |   |   |   |   |   +---PushButtonProperties.cpp
|   |   |   |   |   |   +---RadioButtonProperties.cpp
|   |   |   |   |   |   +---SliderProperties.cpp
|   |   |   |   |   |   +---StaticTextProperties.cpp
|   |   |   |   |   |   +---TabControlProperties.cpp
|   |   |   |   |   |   `---TextEntryProperties.cpp
|   |   |   |   |   +---EditWindow.cpp
|   |   |   |   |   +---GUIEdit.cpp
|   |   |   |   |   +---GUIEditDisplay.cpp
|   |   |   |   |   +---GUIEditWindowManager.cpp
|   |   |   |   |   +---HierarchyView.cpp
|   |   |   |   |   +---LayoutScheme.cpp
|   |   |   |   |   +---Properties.cpp
|   |   |   |   |   +---Save.cpp
|   |   |   |   |   `---WinMain.cpp
|   |   |   |   `---GUIEdit.dsp
|   |   |   +---ImagePacker
|   |   |   |   +---Include
|   |   |   |   |   +---ImageDirectory.h
|   |   |   |   |   +---ImageInfo.h
|   |   |   |   |   +---ImagePacker.h
|   |   |   |   |   +---TexturePage.h
|   |   |   |   |   +---WindowProc.h
|   |   |   |   |   `---WinMain.h
|   |   |   |   +---Resource
|   |   |   |   |   +---ImagePacker.rc
|   |   |   |   |   `---Resource.h
|   |   |   |   +---Source
|   |   |   |   |   +---Window Procedures
|   |   |   |   |   |   +---DirectorySelect.cpp
|   |   |   |   |   |   +---ImageErrorProc.cpp
|   |   |   |   |   |   +---ImagePackerProc.cpp
|   |   |   |   |   |   +---PageErrorProc.cpp
|   |   |   |   |   |   `---PreviewProc.cpp
|   |   |   |   |   +---ImageInfo.cpp
|   |   |   |   |   +---ImagePacker.cpp
|   |   |   |   |   +---TexturePage.cpp
|   |   |   |   |   `---WinMain.cpp
|   |   |   |   `---ImagePacker.dsp
|   |   |   +---Launcher
|   |   |   |   +---DatGen
|   |   |   |   |   +---DatGen.cpp
|   |   |   |   |   `---DatGen.dsp
|   |   |   |   +---SafeDisk
|   |   |   |   |   `---.gitignore
|   |   |   |   +---Toolkit
|   |   |   |   |   +---Debug
|   |   |   |   |   |   +---DebugPrint.cpp
|   |   |   |   |   |   `---DebugPrint.h
|   |   |   |   |   +---Storage
|   |   |   |   |   |   +---File.cpp
|   |   |   |   |   |   +---File.h
|   |   |   |   |   |   +---Rights.h
|   |   |   |   |   |   `---Stream.h
|   |   |   |   |   `---Support
|   |   |   |   |       +---RefCounted.h
|   |   |   |   |       +---RefPtr.h
|   |   |   |   |       +---StringConvert.cpp
|   |   |   |   |       +---StringConvert.h
|   |   |   |   |       +---UString.cpp
|   |   |   |   |       +---UString.h
|   |   |   |   |       +---UTypes.h
|   |   |   |   |       `---Visualc.h
|   |   |   |   +---BFISH.CPP
|   |   |   |   +---BFISH.H
|   |   |   |   +---configfile.cpp
|   |   |   |   +---configfile.h
|   |   |   |   +---dialog.cpp
|   |   |   |   +---dialog.h
|   |   |   |   +---dictionary.h
|   |   |   |   +---filed.h
|   |   |   |   +---findpatch.cpp
|   |   |   |   +---findpatch.h
|   |   |   |   +---Generals.ico
|   |   |   |   +---launcher.dsp
|   |   |   |   +---launcher1.rc
|   |   |   |   +---loadbmp.cpp
|   |   |   |   +---loadbmp.h
|   |   |   |   +---main.cpp
|   |   |   |   +---monod.cpp
|   |   |   |   +---monod.h
|   |   |   |   +---odevice.h
|   |   |   |   +---patch.cpp
|   |   |   |   +---patch.h
|   |   |   |   +---process.cpp
|   |   |   |   +---process.h
|   |   |   |   +---Protect.cpp
|   |   |   |   +---Protect.h
|   |   |   |   +---resource.h
|   |   |   |   +---streamer.cpp
|   |   |   |   +---streamer.h
|   |   |   |   +---wdebug.cpp
|   |   |   |   +---wdebug.h
|   |   |   |   +---winblows.cpp
|   |   |   |   +---winblows.h
|   |   |   |   +---wstring.cpp
|   |   |   |   +---wstring.h
|   |   |   |   `---wstypes.h
|   |   |   +---mangler
|   |   |   |   +---wlib
|   |   |   |   |   +---arraylist.h
|   |   |   |   |   +---configfile.cpp
|   |   |   |   |   +---configfile.h
|   |   |   |   |   +---critsec.cpp
|   |   |   |   |   +---critsec.h
|   |   |   |   |   +---dictionary.h
|   |   |   |   |   +---filed.h
|   |   |   |   |   +---linkedlist.h
|   |   |   |   |   +---Makefile
|   |   |   |   |   +---mboxd.h
|   |   |   |   |   +---monod.cpp
|   |   |   |   |   +---monod.h
|   |   |   |   |   +---odevice.h
|   |   |   |   |   +---sem4.cpp
|   |   |   |   |   +---sem4.h
|   |   |   |   |   +---stderrd.h
|   |   |   |   |   +---stdoutd.h
|   |   |   |   |   +---streamer.cpp
|   |   |   |   |   +---streamer.h
|   |   |   |   |   +---syslogd.cpp
|   |   |   |   |   +---syslogd.h
|   |   |   |   |   +---threadfac.cpp
|   |   |   |   |   +---threadfac.h
|   |   |   |   |   +---threadsafe.h
|   |   |   |   |   +---timezone.cpp
|   |   |   |   |   +---timezone.h
|   |   |   |   |   +---ustring.h
|   |   |   |   |   +---wdebug.cpp
|   |   |   |   |   +---wdebug.h
|   |   |   |   |   +---wstring.cpp
|   |   |   |   |   +---wstring.h
|   |   |   |   |   +---wstypes.h
|   |   |   |   |   +---wtime.cpp
|   |   |   |   |   +---wtime.h
|   |   |   |   |   +---xtime.cpp
|   |   |   |   |   `---xtime.h
|   |   |   |   +---wnet
|   |   |   |   |   +---field.cpp
|   |   |   |   |   +---field.h
|   |   |   |   |   +---Makefile
|   |   |   |   |   +---packet.cpp
|   |   |   |   |   +---packet.h
|   |   |   |   |   +---tcp.cpp
|   |   |   |   |   +---tcp.h
|   |   |   |   |   +---udp.cpp
|   |   |   |   |   `---udp.h
|   |   |   |   +---crc.cpp
|   |   |   |   +---crc.h
|   |   |   |   +---endian.h
|   |   |   |   +---Makefile
|   |   |   |   +---mangler.cpp
|   |   |   |   +---mangler.dsp
|   |   |   |   +---mangler.dsw
|   |   |   |   +---mangler.h
|   |   |   |   +---manglertest.cpp
|   |   |   |   `---manglertest.dsp
|   |   |   +---MapCacheBuilder
|   |   |   |   +---Include
|   |   |   |   |   `---WinMain.h
|   |   |   |   +---Resource
|   |   |   |   |   +---MapCacheBuilder.rc
|   |   |   |   |   `---Resource.h
|   |   |   |   +---Source
|   |   |   |   |   `---WinMain.cpp
|   |   |   |   `---MapCacheBuilder.dsp
|   |   |   +---matchbot
|   |   |   |   +---wlib
|   |   |   |   |   +---arraylist.h
|   |   |   |   |   +---configfile.cpp
|   |   |   |   |   +---configfile.h
|   |   |   |   |   +---critsec.cpp
|   |   |   |   |   +---critsec.h
|   |   |   |   |   +---dictionary.h
|   |   |   |   |   +---filed.h
|   |   |   |   |   +---linkedlist.h
|   |   |   |   |   +---mboxd.h
|   |   |   |   |   +---monod.cpp
|   |   |   |   |   +---monod.h
|   |   |   |   |   +---odevice.h
|   |   |   |   |   +---sem4.cpp
|   |   |   |   |   +---sem4.h
|   |   |   |   |   +---stderrd.h
|   |   |   |   |   +---stdoutd.h
|   |   |   |   |   +---streamer.cpp
|   |   |   |   |   +---streamer.h
|   |   |   |   |   +---syslogd.cpp
|   |   |   |   |   +---syslogd.h
|   |   |   |   |   +---threadfac.cpp
|   |   |   |   |   +---threadfac.h
|   |   |   |   |   +---threadsafe.h
|   |   |   |   |   +---timezone.cpp
|   |   |   |   |   +---timezone.h
|   |   |   |   |   +---ustring.h
|   |   |   |   |   +---wdebug.cpp
|   |   |   |   |   +---wdebug.h
|   |   |   |   |   +---wstring.cpp
|   |   |   |   |   +---wstring.h
|   |   |   |   |   +---wstypes.h
|   |   |   |   |   +---wtime.cpp
|   |   |   |   |   +---wtime.h
|   |   |   |   |   +---xtime.cpp
|   |   |   |   |   `---xtime.h
|   |   |   |   +---wnet
|   |   |   |   |   +---field.cpp
|   |   |   |   |   +---field.h
|   |   |   |   |   +---packet.cpp
|   |   |   |   |   +---packet.h
|   |   |   |   |   +---tcp.cpp
|   |   |   |   |   +---tcp.h
|   |   |   |   |   +---udp.cpp
|   |   |   |   |   `---udp.h
|   |   |   |   +---debug.cpp
|   |   |   |   +---debug.h
|   |   |   |   +---encrypt.cpp
|   |   |   |   +---encrypt.h
|   |   |   |   +---generals.cpp
|   |   |   |   +---generals.h
|   |   |   |   +---global.cpp
|   |   |   |   +---global.h
|   |   |   |   +---main.cpp
|   |   |   |   +---matcher.cpp
|   |   |   |   +---matcher.h
|   |   |   |   +---mydebug.cpp
|   |   |   |   +---mydebug.h
|   |   |   |   +---rand.cpp
|   |   |   |   `---rand.h
|   |   |   +---NVASM
|   |   |   |   `---.gitignore
|   |   |   +---ParticleEditor
|   |   |   |   +---res
|   |   |   |   |   `---ParticleEditor.rc2
|   |   |   |   +---CButtonShowColor.cpp
|   |   |   |   +---CButtonShowColor.h
|   |   |   |   +---CColorAlphaDialog.cpp
|   |   |   |   +---CColorAlphaDialog.h
|   |   |   |   +---CParticleEditorPage.h
|   |   |   |   +---CSwitchesDialog.cpp
|   |   |   |   +---CSwitchesDialog.h
|   |   |   |   +---EmissionTypePanels.cpp
|   |   |   |   +---EmissionTypePanels.h
|   |   |   |   +---ISwapablePanel.h
|   |   |   |   +---MoreParmsDialog.cpp
|   |   |   |   +---MoreParmsDialog.h
|   |   |   |   +---ParticleEditor.cpp
|   |   |   |   +---ParticleEditor.def
|   |   |   |   +---ParticleEditor.dsp
|   |   |   |   +---ParticleEditor.dsw
|   |   |   |   +---ParticleEditor.h
|   |   |   |   +---ParticleEditor.rc
|   |   |   |   +---ParticleEditorDialog.cpp
|   |   |   |   +---ParticleEditorDialog.h
|   |   |   |   +---ParticleEditorExport.h
|   |   |   |   +---ParticleTypePanels.cpp
|   |   |   |   +---ParticleTypePanels.h
|   |   |   |   +---post-build-Release.bat
|   |   |   |   +---post-build.bat
|   |   |   |   +---Resource.h
|   |   |   |   +---ShaderTypePanels.cpp
|   |   |   |   +---ShaderTypePanels.h
|   |   |   |   +---StdAfx.cpp
|   |   |   |   +---StdAfx.h
|   |   |   |   +---VelocityTypePanels.cpp
|   |   |   |   `---VelocityTypePanels.h
|   |   |   +---PATCHGET
|   |   |   |   +---CHATAPI.CPP
|   |   |   |   +---CHATAPI.H
|   |   |   |   +---COMINIT.CPP
|   |   |   |   +---COMINIT.H
|   |   |   |   +---debug.cpp
|   |   |   |   +---debug.h
|   |   |   |   +---DownloadManager.cpp
|   |   |   |   +---DownloadManager.h
|   |   |   |   +---Generals.ico
|   |   |   |   +---patchgrabber.dsp
|   |   |   |   +---PROCESS.CPP
|   |   |   |   +---PROCESS.H
|   |   |   |   +---registry.cpp
|   |   |   |   +---Registry.h
|   |   |   |   +---RESOURCE.H
|   |   |   |   +---SCRIPT1.RC
|   |   |   |   +---WINBLOWS.CPP
|   |   |   |   +---WINBLOWS.H
|   |   |   |   `---WSTYPES.H
|   |   |   +---textureCompress
|   |   |   |   +---resource.h
|   |   |   |   +---textureCompress.cpp
|   |   |   |   +---textureCompress.dsp
|   |   |   |   +---textureCompress.dsw
|   |   |   |   `---textureCompress.rc
|   |   |   +---timingTest
|   |   |   |   +---StdAfx.cpp
|   |   |   |   +---StdAfx.h
|   |   |   |   +---timingTest.cpp
|   |   |   |   +---timingTest.dsp
|   |   |   |   `---timingTest.dsw
|   |   |   +---versionUpdate
|   |   |   |   +---versionUpdate.cpp
|   |   |   |   `---versionUpdate.dsp
|   |   |   +---wolSetup
|   |   |   |   +---WOLAPI
|   |   |   |   |   +---chatdefs.h
|   |   |   |   |   +---downloaddefs.h
|   |   |   |   |   +---ftpdefs.h
|   |   |   |   |   +---netutildefs.h
|   |   |   |   |   +---wolapi_i.c
|   |   |   |   |   +---wolapi.dll
|   |   |   |   |   +---wolapi.h
|   |   |   |   |   `---woldbg.dll
|   |   |   |   +---makedist.bat
|   |   |   |   +---resource.h
|   |   |   |   +---small.ico
|   |   |   |   +---StdAfx.cpp
|   |   |   |   +---StdAfx.h
|   |   |   |   +---verchk.cpp
|   |   |   |   +---verchk.h
|   |   |   |   +---wolInit.cpp
|   |   |   |   +---wolSetup.cpp
|   |   |   |   +---wolSetup.dsp
|   |   |   |   +---wolSetup.dsw
|   |   |   |   +---wolSetup.h
|   |   |   |   +---wolSetup.ico
|   |   |   |   `---wolSetup.rc
|   |   |   +---WorldBuilder
|   |   |   |   +---include
|   |   |   |   |   +---addplayerdialog.h
|   |   |   |   |   +---AutoEdgeOutTool.h
|   |   |   |   |   +---BaseBuildProps.h
|   |   |   |   |   +---BlendEdgeTool.h
|   |   |   |   |   +---BlendMaterial.h
|   |   |   |   |   +---BorderTool.h
|   |   |   |   |   +---brushoptions.h
|   |   |   |   |   +---BrushTool.h
|   |   |   |   |   +---BuildList.h
|   |   |   |   |   +---BuildListTool.h
|   |   |   |   |   +---CameraOptions.h
|   |   |   |   |   +---CellWidth.h
|   |   |   |   |   +---CFixTeamOwnerDialog.h
|   |   |   |   |   +---ContourOptions.h
|   |   |   |   |   +---CUndoable.h
|   |   |   |   |   +---DrawObject.h
|   |   |   |   |   +---EditAction.h
|   |   |   |   |   +---EditCondition.h
|   |   |   |   |   +---EditCoordParameter.h
|   |   |   |   |   +---EditGroup.h
|   |   |   |   |   +---EditObjectParameter.h
|   |   |   |   |   +---EditParameter.h
|   |   |   |   |   +---euladialog.h
|   |   |   |   |   +---ExportScriptsOptions.h
|   |   |   |   |   +---EyedropperTool.h
|   |   |   |   |   +---FeatherOptions.h
|   |   |   |   |   +---FeatherTool.h
|   |   |   |   |   +---FenceOptions.h
|   |   |   |   |   +---FenceTool.h
|   |   |   |   |   +---FloodFillTool.h
|   |   |   |   |   +---GlobalLightOptions.h
|   |   |   |   |   +---GroveOptions.h
|   |   |   |   |   +---GroveTool.h
|   |   |   |   |   +---HandScrollTool.h
|   |   |   |   |   +---ImpassableOptions.h
|   |   |   |   |   +---LayersList.h
|   |   |   |   |   +---LightOptions.h
|   |   |   |   |   +---MainFrm.h
|   |   |   |   |   +---mapobjectprops.h
|   |   |   |   |   +---MapPreview.h
|   |   |   |   |   +---MapSettings.h
|   |   |   |   |   +---MeshMoldOptions.h
|   |   |   |   |   +---MeshMoldTool.h
|   |   |   |   |   +---MoundOptions.h
|   |   |   |   |   +---MoundTool.h
|   |   |   |   |   +---MyToolbar.h
|   |   |   |   |   +---NewHeightMap.h
|   |   |   |   |   +---ObjectOptions.h
|   |   |   |   |   +---ObjectPreview.h
|   |   |   |   |   +---ObjectTool.h
|   |   |   |   |   +---OpenMap.h
|   |   |   |   |   +---OptionsPanel.h
|   |   |   |   |   +---PickUnitDialog.h
|   |   |   |   |   +---playerlistdlg.h
|   |   |   |   |   +---PointerTool.h
|   |   |   |   |   +---PolygonTool.h
|   |   |   |   |   +---propedit.h
|   |   |   |   |   +---RampOptions.h
|   |   |   |   |   +---RampTool.h
|   |   |   |   |   +---RoadOptions.h
|   |   |   |   |   +---RoadTool.h
|   |   |   |   |   +---RulerOptions.h
|   |   |   |   |   +---RulerTool.h
|   |   |   |   |   +---SaveMap.h
|   |   |   |   |   +---ScorchOptions.h
|   |   |   |   |   +---ScorchTool.h
|   |   |   |   |   +---ScriptActionsFalse.h
|   |   |   |   |   +---ScriptActionsTrue.h
|   |   |   |   |   +---ScriptConditions.h
|   |   |   |   |   +---ScriptDialog.h
|   |   |   |   |   +---ScriptProperties.h
|   |   |   |   |   +---SelectMacrotexture.h
|   |   |   |   |   +---ShadowOptions.h
|   |   |   |   |   +---SplashScreen.h
|   |   |   |   |   +---StdAfx.h
|   |   |   |   |   +---TeamBehavior.h
|   |   |   |   |   +---TeamGeneric.h
|   |   |   |   |   +---TeamIdentity.h
|   |   |   |   |   +---TeamObjectProperties.h
|   |   |   |   |   +---TeamReinforcement.h
|   |   |   |   |   +---teamsdialog.h
|   |   |   |   |   +---TerrainMaterial.h
|   |   |   |   |   +---TerrainModal.h
|   |   |   |   |   +---TerrainSwatches.h
|   |   |   |   |   +---TileTool.h
|   |   |   |   |   +---Tool.h
|   |   |   |   |   +---WaterOptions.h
|   |   |   |   |   +---WaterTool.h
|   |   |   |   |   +---WaypointOptions.h
|   |   |   |   |   +---WaypointTool.h
|   |   |   |   |   +---WBFrameWnd.h
|   |   |   |   |   +---WBHeightMap.h
|   |   |   |   |   +---WBPopupSlider.h
|   |   |   |   |   +---wbview.h
|   |   |   |   |   +---wbview3d.h
|   |   |   |   |   +---WHeightMapEdit.h
|   |   |   |   |   +---WorldBuilder.h
|   |   |   |   |   +---WorldBuilderDoc.h
|   |   |   |   |   `---WorldBuilderView.h
|   |   |   |   +---res
|   |   |   |   |   +---cross.cur
|   |   |   |   |   +---folder.bmp
|   |   |   |   |   +---foldersc.bmp
|   |   |   |   |   +---icon2.ico
|   |   |   |   |   +---IDB_DownArrow.bmp
|   |   |   |   |   +---IDB_ROAD_CORNERS.bmp
|   |   |   |   |   +---IDC_AUTO_EDGE_OUT.cur
|   |   |   |   |   +---IDC_BLEND_EDGE.cur
|   |   |   |   |   +---IDC_BUILD_LIST_TOOL.cur
|   |   |   |   |   +---IDC_BUILD_MOVE.cur
|   |   |   |   |   +---IDC_BUILD_POINTER.cur
|   |   |   |   |   +---IDC_BUILD_ROTATE.cur
|   |   |   |   |   +---IDC_CLIFF.cur
|   |   |   |   |   +---IDC_EYEDROPPER.cur
|   |   |   |   |   +---IDC_FENCE.cur
|   |   |   |   |   +---IDC_FLOOD_FILL.cur
|   |   |   |   |   +---IDC_GROVE.cur
|   |   |   |   |   +---IDC_HAND_SCROLL.cur
|   |   |   |   |   +---IDC_MOLD_POINTER.cur
|   |   |   |   |   +---IDC_MOVE_POINTER.cur
|   |   |   |   |   +---IDC_PLACE_OBJECT.cur
|   |   |   |   |   +---IDC_POINTER.cur
|   |   |   |   |   +---IDC_POLYGON_MOVE.cur
|   |   |   |   |   +---IDC_POLYGON_PLUS.cur
|   |   |   |   |   +---IDC_POLYGON.cur
|   |   |   |   |   +---IDC_RAMP.cur
|   |   |   |   |   +---IDC_ROAD.cur
|   |   |   |   |   +---IDC_ROTATE.cur
|   |   |   |   |   +---IDC_Scorch.cur
|   |   |   |   |   +---IDC_WATER_MOVE.cur
|   |   |   |   |   +---IDC_WATER_PLUS.cur
|   |   |   |   |   +---IDC_WATER.cur
|   |   |   |   |   +---IDC_WAYPOINT.cur
|   |   |   |   |   +---IDI_Hide.ico
|   |   |   |   |   +---IDI_Show.ico
|   |   |   |   |   +---IDI_Thumb.ico
|   |   |   |   |   +---resource.h
|   |   |   |   |   +---TileTool.cur
|   |   |   |   |   +---Toolbar.bmp
|   |   |   |   |   +---toolbar1.bmp
|   |   |   |   |   +---toolbar2.bmp
|   |   |   |   |   +---WorldBuilder.bmp
|   |   |   |   |   +---WorldBuilder.ico
|   |   |   |   |   +---WorldBuilder.rc
|   |   |   |   |   +---WorldBuilder.rc2
|   |   |   |   |   `---WorldBuilderDoc.ico
|   |   |   |   +---src
|   |   |   |   |   +---addplayerdialog.cpp
|   |   |   |   |   +---AutoEdgeOutTool.cpp
|   |   |   |   |   +---BaseBuildProps.cpp
|   |   |   |   |   +---BlendEdgeTool.cpp
|   |   |   |   |   +---BlendMaterial.cpp
|   |   |   |   |   +---BorderTool.cpp
|   |   |   |   |   +---brushoptions.cpp
|   |   |   |   |   +---BrushTool.cpp
|   |   |   |   |   +---BuildList.cpp
|   |   |   |   |   +---BuildListTool.cpp
|   |   |   |   |   +---CameraOptions.cpp
|   |   |   |   |   +---CButtonShowColor.cpp
|   |   |   |   |   +---CButtonShowColor.h
|   |   |   |   |   +---CellWidth.cpp
|   |   |   |   |   +---CFixTeamOwnerDialog.cpp
|   |   |   |   |   +---ContourOptions.cpp
|   |   |   |   |   +---CUndoable.cpp
|   |   |   |   |   +---DrawObject.cpp
|   |   |   |   |   +---EditAction.cpp
|   |   |   |   |   +---EditCondition.cpp
|   |   |   |   |   +---EditCoordParameter.cpp
|   |   |   |   |   +---EditGroup.cpp
|   |   |   |   |   +---EditObjectParameter.cpp
|   |   |   |   |   +---EditParameter.cpp
|   |   |   |   |   +---EulaDialog.cpp
|   |   |   |   |   +---ExportScriptsOptions.cpp
|   |   |   |   |   +---EyedropperTool.cpp
|   |   |   |   |   +---FeatherOptions.cpp
|   |   |   |   |   +---FeatherTool.cpp
|   |   |   |   |   +---FenceOptions.cpp
|   |   |   |   |   +---FenceTool.cpp
|   |   |   |   |   +---FloodFillTool.cpp
|   |   |   |   |   +---GlobalLightOptions.cpp
|   |   |   |   |   +---GroveOptions.cpp
|   |   |   |   |   +---GroveTool.cpp
|   |   |   |   |   +---HandScrollTool.cpp
|   |   |   |   |   +---ImpassableOptions.cpp
|   |   |   |   |   +---LayersList.cpp
|   |   |   |   |   +---LightOptions.cpp
|   |   |   |   |   +---MainFrm.cpp
|   |   |   |   |   +---mapobjectprops.cpp
|   |   |   |   |   +---MapPreview.cpp
|   |   |   |   |   +---MapSettings.cpp
|   |   |   |   |   +---MeshMoldOptions.cpp
|   |   |   |   |   +---MeshMoldTool.cpp
|   |   |   |   |   +---MoundOptions.cpp
|   |   |   |   |   +---MoundTool.cpp
|   |   |   |   |   +---MyToolbar.cpp
|   |   |   |   |   +---NewHeightMap.cpp
|   |   |   |   |   +---ObjectOptions.cpp
|   |   |   |   |   +---ObjectPreview.cpp
|   |   |   |   |   +---ObjectTool.cpp
|   |   |   |   |   +---OpenMap.cpp
|   |   |   |   |   +---OptionsPanel.cpp
|   |   |   |   |   +---PickUnitDialog.cpp
|   |   |   |   |   +---playerlistdlg.cpp
|   |   |   |   |   +---PointerTool.cpp
|   |   |   |   |   +---PolygonTool.cpp
|   |   |   |   |   +---propedit.cpp
|   |   |   |   |   +---RampOptions.cpp
|   |   |   |   |   +---RampTool.cpp
|   |   |   |   |   +---RoadOptions.cpp
|   |   |   |   |   +---RoadTool.cpp
|   |   |   |   |   +---RulerOptions.cpp
|   |   |   |   |   +---RulerTool.cpp
|   |   |   |   |   +---SaveMap.cpp
|   |   |   |   |   +---ScorchOptions.cpp
|   |   |   |   |   +---ScorchTool.cpp
|   |   |   |   |   +---ScriptActionsFalse.cpp
|   |   |   |   |   +---ScriptActionsTrue.cpp
|   |   |   |   |   +---ScriptConditions.cpp
|   |   |   |   |   +---ScriptDialog.cpp
|   |   |   |   |   +---ScriptProperties.cpp
|   |   |   |   |   +---SelectMacrotexture.cpp
|   |   |   |   |   +---ShadowOptions.cpp
|   |   |   |   |   +---SplashScreen.cpp
|   |   |   |   |   +---StdAfx.cpp
|   |   |   |   |   +---TeamBehavior.cpp
|   |   |   |   |   +---TeamGeneric.cpp
|   |   |   |   |   +---TeamIdentity.cpp
|   |   |   |   |   +---TeamObjectProperties.cpp
|   |   |   |   |   +---TeamReinforcement.cpp
|   |   |   |   |   +---teamsdialog.cpp
|   |   |   |   |   +---TerrainMaterial.cpp
|   |   |   |   |   +---TerrainModal.cpp
|   |   |   |   |   +---TerrainSwatches.cpp
|   |   |   |   |   +---TileTool.cpp
|   |   |   |   |   +---Tool.cpp
|   |   |   |   |   +---WaterOptions.cpp
|   |   |   |   |   +---WaterTool.cpp
|   |   |   |   |   +---WaypointOptions.cpp
|   |   |   |   |   +---WaypointTool.cpp
|   |   |   |   |   +---WBFrameWnd.cpp
|   |   |   |   |   +---WBHeightMap.cpp
|   |   |   |   |   +---WBPopupSlider.cpp
|   |   |   |   |   +---wbview.cpp
|   |   |   |   |   +---wbview3d.cpp
|   |   |   |   |   +---WHeightMapEdit.cpp
|   |   |   |   |   +---WorldBuilder.cpp
|   |   |   |   |   +---WorldBuilderDoc.cpp
|   |   |   |   |   `---WorldBuilderView.cpp
|   |   |   |   `---WorldBuilder.dsp
|   |   |   `---WW3D
|   |   |       +---max2w3d
|   |   |       |   +---Res
|   |   |       |   |   +---DISK12.ICO
|   |   |       |   |   +---one.bmp
|   |   |       |   |   +---orig.ico
|   |   |       |   |   +---orig1.ico
|   |   |       |   |   +---two.bmp
|   |   |       |   |   `---ww3d.bmp
|   |   |       |   +---aabtreebuilder.cpp
|   |   |       |   +---aabtreebuilder.h
|   |   |       |   +---AlphaModifier.cpp
|   |   |       |   +---AlphaModifier.h
|   |   |       |   +---animationcompressionsettings.cpp
|   |   |       |   +---animationcompressionsettings.h
|   |   |       |   +---AppData.cpp
|   |   |       |   +---bchannel.cpp
|   |   |       |   +---bchannel.h
|   |   |       |   +---boneicon.cpp
|   |   |       |   +---boneicon.h
|   |   |       |   +---bpick.cpp
|   |   |       |   +---bpick.h
|   |   |       |   +---changes.txt
|   |   |       |   +---colboxsave.cpp
|   |   |       |   +---colboxsave.h
|   |   |       |   +---dazzlesave.cpp
|   |   |       |   +---dazzlesave.h
|   |   |       |   +---dllmain.cpp
|   |   |       |   +---dllmain.h
|   |   |       |   +---ExportAll.cpp
|   |   |       |   +---ExportAllDlg.cpp
|   |   |       |   +---ExportAllDlg.h
|   |   |       |   +---exportlog.cpp
|   |   |       |   +---exportlog.h
|   |   |       |   +---floaterdialog.cpp
|   |   |       |   +---floaterdialog.h
|   |   |       |   +---FormClass.cpp
|   |   |       |   +---FormClass.h
|   |   |       |   +---gamemaps.cpp
|   |   |       |   +---gamemaps.h
|   |   |       |   +---GameMtl.cpp
|   |   |       |   +---gamemtl.h
|   |   |       |   +---GameMtlDlg.cpp
|   |   |       |   +---GameMtlDlg.h
|   |   |       |   +---GameMtlForm.cpp
|   |   |       |   +---GameMtlForm.h
|   |   |       |   +---GameMtlPassDlg.cpp
|   |   |       |   +---GameMtlPassDlg.h
|   |   |       |   +---GameMtlShaderDlg.cpp
|   |   |       |   +---GameMtlShaderDlg.h
|   |   |       |   +---GameMtlTextureDlg.cpp
|   |   |       |   +---GameMtlTextureDlg.h
|   |   |       |   +---GameMtlVertexMaterialDlg.cpp
|   |   |       |   +---GameMtlVertexMaterialDlg.h
|   |   |       |   +---genlodextensiondialog.cpp
|   |   |       |   +---genlodextensiondialog.h
|   |   |       |   +---genmtlnamesdialog.cpp
|   |   |       |   +---genmtlnamesdialog.h
|   |   |       |   +---gennamesdialog.cpp
|   |   |       |   +---gennamesdialog.h
|   |   |       |   +---geometryexportcontext.h
|   |   |       |   +---geometryexporttask.cpp
|   |   |       |   +---geometryexporttask.h
|   |   |       |   +---gmtldlg.cpp
|   |   |       |   +---gridsnapmodifier.cpp
|   |   |       |   +---gridsnapmodifier.h
|   |   |       |   +---hiersave.cpp
|   |   |       |   +---hiersave.h
|   |   |       |   +---hlodsave.cpp
|   |   |       |   +---hlodsave.h
|   |   |       |   +---InputDlg.cpp
|   |   |       |   +---InputDlg.h
|   |   |       |   +---LightGlareSave.cpp
|   |   |       |   +---LightGlareSave.h
|   |   |       |   +---logdlg.cpp
|   |   |       |   +---logdlg.h
|   |   |       |   +---max2w3d.def
|   |   |       |   +---max2w3d.dsp
|   |   |       |   +---max2w3d.dsw
|   |   |       |   +---max2w3d.rc
|   |   |       |   +---maxworldinfo.cpp
|   |   |       |   +---maxworldinfo.h
|   |   |       |   +---meshbuild.cpp
|   |   |       |   +---meshbuild.h
|   |   |       |   +---meshcon.cpp
|   |   |       |   +---meshcon.h
|   |   |       |   +---MeshDeform.cpp
|   |   |       |   +---MeshDeform.h
|   |   |       |   +---MeshDeformData.cpp
|   |   |       |   +---MeshDeformData.h
|   |   |       |   +---MeshDeformDefs.h
|   |   |       |   +---MeshDeformPanel.cpp
|   |   |       |   +---MeshDeformPanel.h
|   |   |       |   +---MeshDeformSave.cpp
|   |   |       |   +---MeshDeformSave.h
|   |   |       |   +---MeshDeformSaveDefs.h
|   |   |       |   +---MeshDeformSaveSet.cpp
|   |   |       |   +---MeshDeformSaveSet.h
|   |   |       |   +---MeshDeformSet.cpp
|   |   |       |   +---MeshDeformSet.h
|   |   |       |   +---MeshDeformUndo.cpp
|   |   |       |   +---MeshDeformUndo.h
|   |   |       |   +---meshsave.cpp
|   |   |       |   +---meshsave.h
|   |   |       |   +---motion.cpp
|   |   |       |   +---motion.h
|   |   |       |   +---namedsel.cpp
|   |   |       |   +---namedsel.h
|   |   |       |   +---nullsave.cpp
|   |   |       |   +---nullsave.h
|   |   |       |   +---PCToPS2Material.cpp
|   |   |       |   +---presetexportoptionsdialog.cpp
|   |   |       |   +---presetexportoptionsdialog.h
|   |   |       |   +---PS2GameMtl.cpp
|   |   |       |   +---PS2GameMtlShaderDlg.cpp
|   |   |       |   +---PS2GameMtlShaderDlg.h
|   |   |       |   +---rcmenu.cpp
|   |   |       |   +---rcmenu.h
|   |   |       |   +---resource.h
|   |   |       |   +---SceneSetup.cpp
|   |   |       |   +---SceneSetupDlg.cpp
|   |   |       |   +---SceneSetupDlg.h
|   |   |       |   +---simpdib.cpp
|   |   |       |   +---simpdib.h
|   |   |       |   +---skin.cpp
|   |   |       |   +---skin.h
|   |   |       |   +---SkinCopy.cpp
|   |   |       |   +---skindata.cpp
|   |   |       |   +---skindata.h
|   |   |       |   +---SnapPoints.cpp
|   |   |       |   +---SnapPoints.h
|   |   |       |   +---TARGA.CPP
|   |   |       |   +---TARGA.H
|   |   |       |   +---util.cpp
|   |   |       |   +---util.h
|   |   |       |   +---Utility.cpp
|   |   |       |   +---vchannel.cpp
|   |   |       |   +---vchannel.h
|   |   |       |   +---vxl.cpp
|   |   |       |   +---vxl.h
|   |   |       |   +---vxldbg.cpp
|   |   |       |   +---vxldbg.h
|   |   |       |   +---vxllayer.cpp
|   |   |       |   +---vxllayer.h
|   |   |       |   +---w3d_file.h
|   |   |       |   +---w3d_obsolete.h
|   |   |       |   +---w3dappdata.cpp
|   |   |       |   +---w3dappdata.h
|   |   |       |   +---w3ddesc.cpp
|   |   |       |   +---w3ddesc.h
|   |   |       |   +---w3ddlg.cpp
|   |   |       |   +---w3ddlg.h
|   |   |       |   +---w3dexp.cpp
|   |   |       |   +---w3dexp.h
|   |   |       |   +---w3dmtl.cpp
|   |   |       |   +---w3dmtl.h
|   |   |       |   +---w3dutil.cpp
|   |   |       |   `---w3dutil.h
|   |   |       `---pluglib
|   |   |           +---aaplane.h
|   |   |           +---always.h
|   |   |           +---BITTYPE.H
|   |   |           +---bool.h
|   |   |           +---borlandc.h
|   |   |           +---chunkio.cpp
|   |   |           +---chunkio.h
|   |   |           +---errclass.h
|   |   |           +---EULER.CPP
|   |   |           +---EULER.H
|   |   |           +---hashcalc.h
|   |   |           +---hsv.cpp
|   |   |           +---hsv.h
|   |   |           +---iostruct.h
|   |   |           +---jshell.cpp
|   |   |           +---matrix3d.cpp
|   |   |           +---matrix3d.h
|   |   |           +---matrix4.cpp
|   |   |           +---matrix4.h
|   |   |           +---nodefilt.cpp
|   |   |           +---nodefilt.h
|   |   |           +---nodelist.cpp
|   |   |           +---nodelist.h
|   |   |           +---noinit.h
|   |   |           +---palette.cpp
|   |   |           +---palette.h
|   |   |           +---plane.h
|   |   |           +---pluglib.dsp
|   |   |           +---PROGRESS.H
|   |   |           +---rawfile.cpp
|   |   |           +---rawfile.h
|   |   |           +---realcrc.cpp
|   |   |           +---realcrc.h
|   |   |           +---rgb.cpp
|   |   |           +---rgb.h
|   |   |           +---uarray.h
|   |   |           +---Vector.CPP
|   |   |           +---Vector.H
|   |   |           +---vector2.h
|   |   |           +---vector3.h
|   |   |           +---vector3i.h
|   |   |           +---vector4.h
|   |   |           +---visualc.h
|   |   |           +---w3d_file.h
|   |   |           +---w3dquat.cpp
|   |   |           +---w3dquat.h
|   |   |           +---watcom.h
|   |   |           +---win.h
|   |   |           +---wwfile.h
|   |   |           +---wwmath.cpp
|   |   |           +---wwmath.h
|   |   |           +---WWmatrix3.cpp
|   |   |           `---WWmatrix3.h
|   |   +---RTS.dsp
|   |   `---RTS.dsw
|   +---Run
|   |   +---BrowserEngine.dll
|   |   `---place_steam_build_here.txt
|   +---Shaders
|   |   +---PostProcess
|   |   |   +---DLSS.hlsl
|   |   |   `---Shadows.hlsl
|   |   +---Shared.hlsli
|   |   +---Terrain.hlsl
|   |   +---UI.hlsl
|   |   +---Unit.hlsl
|   |   +---VulkanBasic.frag
|   |   `---VulkanBasic.vert
|   +---Test
|   |   +---Smoke
|   |   |   `---smoke_test.py
|   |   +---Unit
|   |   |   +---test_ini_parser.cpp
|   |   |   `---test_pathfinding.cpp
|   |   `---CMakeLists.txt
|   +---.gitignore
|   `---CMakeLists.txt

---
## Build Issue Summary

The project failed to build due to several compilation errors:

### 1. **String class issues** (`wwstring.h`)
- `StringClass::StringClass(const TCHAR*, bool)` — redefinition of default argument (parameter 1), function already defined/declared
- `StringClass::operator=(const TCHAR*)` — function already defined or declared
- `C2264` errors — errors in function definition/declaration throughout the class
- `C2084` errors — function already has a body (duplicate implementations)

### 2. **TCHAR vs char conversion** (`wwstring.h`, `miscutil.cpp`)
- `strtrim(TCHAR*)` cannot convert from `TCHAR*` to `char*`
- `Format()` cannot convert from `const char[9]` to `const TCHAR*`
- `GetFileAttributesA/LPCSTR` vs `GetFileAttributesW/LPCWSTR` conflicts

### 3. **StringClass to const char* conversion** (`parameter.h`, `shddef.cpp`, `hanimmgr.h`, `rawfile.h`)
- No user-defined conversion operator from `const StringClass` to `const char*`

### 4. **Missing DirectX SDK** (`dx8wrapper.h`)
- `d3d8.h`: No such file or directory — DirectX 8 SDK headers not found

### 5. **time_t type mismatch** (`miscutil.cpp`)
- `ctime()` cannot convert argument from `long*` to `const time_t*`

### Root Cause
The codebase was originally built with older compilers (MSVC 6.0 era). Changes were made to `wwstring.h` (likely attempting Unicode/ANSI refactoring) that introduced duplicate declarations/definitions. The Unicode (`_UNICODE`) define causes Windows API functions to resolve to `*W` (wide) variants, but the code still passes narrow strings. Additionally, the legacy DirectX 8 render path references headers no longer available in modern Windows SDKs.
<!-- 