#ifndef Change_log

	/*		30_09_2017
			-----------------------------------------------------------------------------------------------------------------------
	gamedata:
	(~)		system.ltx 						---> slot
	(+)		items.ltx 						---> [detektor_...] ---> belt = true
	(+)		actor.ltx 						---> camera_height_factor = 0.95
	(+) 	task_manager.script 			---> проверка на 'defend_object'
			-----------------------------------------------------------------------------------------------------------------------
	(/)		ui_st_other.xml 				---> ui_quick_slot_use_str_0
	(/)		ui_keybinding.xml	 			---> kb_slot_quick_0
	(=)		inventory_new.xml 				---> condition_prog_ess_bar ---> condition_progRess_bar (1/3)
	(=)		inventory_new_16.xml 			---> condition_prog_ess_bar ---> condition_progRess_bar (2/3)
			-----------------------------------------------------------------------------------------------------------------------
	xray:
	(=)		UICellItem.cpp 					---> condition_progRess_bar (3/3) <--- condition_prog_ess_bar 
	(+)		3rd party\Xiph\libvorbis\lib\info.c ---> #pragma warning(disable:4238) 
	(+)		base_client_classes_script.cpp 	---> #pragma warning(disable:4482)
	(+)		UIMainIngameWnd.cpp 			---> #pragma warning(disable:4482)
			-----------------------------------------------------------------------------------------------------------------------
	(=)		script_game_object_script.cpp 	---> 'ePostSave' ---> eBeforeSave'
	(+)		FStaticRender.cpp 				---> KD_DETAIL_RADIUS ---> #include "../../../build_config_defines.h"
	(+)		r2.cpp 							---> KD_DETAIL_RADIUS ---> #include "../../../build_config_defines.h"
			-----------------------------------------------------------------------------------------------------------------------
	(+) 	SoundRender_Source_loader.cpp 	---> При отсутствии звукового файла будет сообщение в консоли. 	// by Zagolski //
	(=)		actor_statistic_mgr.cpp 		---> Исправление учета статистики 								// by lvg_brest //
	(=)		HangingLamp.cpp 				---> if(!PPhysicsShell()) 			// Очень странный вылет 	// by SkyLoader //	
	(+)		UIInventoryWnd.cpp 				---> #define HIDE_WEAPON_IN_INV 	// Спрячем/показываем предмет в руках, когда откр./закр. инвентарь. // by Shkiper2012 //
			-----------------------------------------------------------------------------------------------------------------------
	(=)		Inventory.cpp 					---> Если на ГГ надет броник с включенным ПНВ, то надо его выключить. // by Kondr48 //
	(=) 	WeaponMagazined.cpp 			---> m_set_next_ammoType_on_reload 	// by Sin! // 
	(=) 	WeaponMagazined.cpp 			---> #define NO_AUTO_RELOAD_WPN 	// Блокируем авто-перезарядку и сброс зума, когда закончились патроны. // by Shkiper2012 //
	(=) 	x_ray.cpp 						--->  Фикс полосы загрузки 			// by SkyLoader //	
			-----------------------------------------------------------------------------------------------------------------------
	(=)		UIDiaryWnd2.cpp 				---> Исправление отображения зеленым цветом прочитанных записей в разделе КПК Дневник. // by lvg_brest //
	(=)		UIDiaryWnd.h 					---> ...
	(=)		UICarBodyWnd.cpp 				---> Исправление отображения параметра "отношение" при обыске тел монстров // by lvg_brest //
	(=)		UICharacterInfo.cpp				---> ... + Исправление работы статика биографии в разделе КПК Ранги.cpp
	(=)		UICharacterInfo.h				---> ...
			-----------------------------------------------------------------------------------------------------------------------
	(=)		UIGameTutorialSimpleItem.cpp 	---> Исправление залипания курсора мыши в главном меню после просмотра титров.cpp // by lvg_brest //
	(=)		Level_network.cpp 				---> Исправление сохранения клиентских объектов. // by Shoker //
	(=)		HW.cpp 							---> Фикс вертикальной синхронизации (r2) // by SkyLoader //
	(=)		ActorInput.cpp 					---> #define NO_MOUSE_WHELL_SWITCH_SLOT // Убирает возможность переключаться между слотами колесиком мыши. // by Shkiper2012 //
			-----------------------------------------------------------------------------------------------------------------------
xxx	(~) 	xrCore\log.cpp 					---> force_flush_log = true; ---> нужно, чтобы поймать вылет после разговора с НПС, которые что-нибудь передают ГГ.
			-----------------------------------------------------------------------------------------------------------------------
	*/

	/** 	02_10_2017 ** START ************************************* ../build_config_defines.h *************************************** 
	(+)		xrGame\Actor.cpp 							---> + ../ ---> "../../../build_config_defines.h"
	(=)		xrGame\ActorInput.cpp 						---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\Actor_Events.cpp 					---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\alife_object_registry.cpp 			---> + ../ ---> "../../../build_config_defines.h"
			-----------------------------------------------------------------------------------------------------------------------
	(+)		xrGame\alife_simulator.cpp 					---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\alife_spawn_registry.cpp 			---> + ../ ---> "../../../build_config_defines.h"
	(-)		xrGame\Bolt.h 								---> delete ---> "../../../build_config_defines.h"
	(-)		xrGame\Bolt.cpp 							---> delete ---> "../../../build_config_defines.h"
			-----------------------------------------------------------------------------------------------------------------------
	(+)		xrGame\ai_space.cpp 						---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\CustomZone.cpp 						---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\EffectorZoomInertion.cpp 			---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\Grenade.cpp 							---> + ../ ---> "../../../build_config_defines.h"
			-----------------------------------------------------------------------------------------------------------------------
	(+)		xrGame\Inventory.cpp 						---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\Inventory.h 							---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\inventory_space.h 					---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\Missile.cpp 							---> + ../ ---> "../../../build_config_defines.h"
			-----------------------------------------------------------------------------------------------------------------------
	(+)		xrGame\script_binder_object_wrapper.cpp 	---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\script_engine.cpp 					---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\script_storage.cpp 					---> + ../ ---> "../../../build_config_defines.h"
			-----------------------------------------------------------------------------------------------------------------------
	(+)		xrGame\ui\UIInventoryWnd.cpp 				---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\ui\uiinventorywnd2.cpp 				---> + ../ ---> "../../../build_config_defines.h"
	(+-)	xrGame\ui\UIMessages.h 						---> + ../ ---> "../../../build_config_defines.h" и удалено || defined(INV_DOUBLE_WPN_SLOTS)
	(+)		xrGame\ui\UIPdaWnd.cpp 						---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\UIGameSP.cpp 						---> + ../ ---> "../../../build_config_defines.h"
			-----------------------------------------------------------------------------------------------------------------------
	(+)		xrGame\Weapon.cpp 							---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\weaponBM16.h 						---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\weaponBM16.cpp 						---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\WeaponKnife.cpp 						---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\WeaponKnife.h 						---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\WeaponMagazined.cpp					---> + ../ ---> "../../../build_config_defines.h"
			-----------------------------------------------------------------------------------------------------------------------
	(+)		xrGame\xr_level_controller.cpp				---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\xr_level_controller.h				---> + ../ ---> "../../../build_config_defines.h"
			-----------------------------------------------------------------------------------------------------------------------
	(+)		xrGame\xrServer_Object_Base.cpp				---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\xrServer_Objects_ALife.cpp			---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\xrServer_Objects_ALife.h				---> + ../ ---> "../../../build_config_defines.h"
	(+)		xrGame\xrServer_process_event_ownership.cpp	---> + ../ ---> "../../../build_config_defines.h"
			-----------------------------------------------------------------------------------------------------------------------
	(-)		luabind\class.hpp 							---> delete ---> "../../../build_config_defines.h"
	(-)		luabind\config.hpp 							---> delete ---> "../../../build_config_defines.h"
	** FINISH ************************************* ../build_config_defines.h ***************************************/

	/*		03_10_2017
			-----------------------------------------------------------------------------------------------------------------------
	(+)		xr_3da\device.cpp 					---> #pragma warning(push) и (pop)
	(+)		libtheora\lib\analyze.c 			---> OC_MV_ZERO = {0,0}; 		// fixed C4132 //
	(+)		libtheora\lib\x86_vc\mmxencfrag.c 	---> ret --> ret1 и ret2 		// fixed C4405 //
			-----------------------------------------------------------------------------------------------------------------------
	(~)		Переименовал проект 'libvorbisfile' в 'libvorbisfile_static'. Всё равно используется только статическая либа.
	(+)		Прописал в свойствах проектов пути к инклудам и либа от dx9sdk 2007 и 2010.
	(~)		Изменил путь из 'Program Files x86' в 'Program Files'
	(~)		Исправил в свойствах проектов пути к инклудам и либа Luabind, LuaJIT.
	(-)		Удалил   в свойствах проектов пути к инклудам и либа FreeImage, MagicSoftware, xrLua, luabind_old.
			-----------------------------------------------------------------------------------------------------------------------
	(+)		system.ltx 	---> [actor_schedule] t_min = 0; t_max = 1; для Lua-перехватчика от alpet.
	(+)		w_binoc.ltx ---> scope_dynamic_zoom = true  ---> После правки в ActorInput.cpp, чтобы работала кратность зума у бинокля и оружия.
			-----------------------------------------------------------------------------------------------------------------------
	*/
	
	/** 	XX_10_2017 ******** // fixed warnings and errors // ********
			xrgame\game_cl_artefacthunt.cpp(442): 	warning C4723: potential divide by 0
			xrGame\ui\UIProgressShape.cpp			warning C4723: potential divide by 0
			xiph\libtheora\lib\decode.c(1582): 		warning C4701: potentially uninitialized local variable 'last_zzi' used
			base_client_classes_script.cpp(488): 	warning C4800: 'BOOL' : forcing value to bool 'true' or 'false' (performance warning)
			HUDCrosshair.cpp(46): 					warning C4800: 'BOOL' : forcing value to bool 'true' or 'false' (performance warning)
			script_game_object_script4.cpp(325): 	warning C4800: 'BOOL' : forcing value to bool 'true' or 'false' (performance warning)
			ui\UICellItem.cpp(149): 				warning C4244: 'argument' : conversion from 'int' to 'float', possible loss of data
			script_actor.cpp(8): 					warning C4627: '#include "StdAfx.h"': skipped when looking for precompiled header use 	| Add directive to 'pch_script.h' or rebuild precompiled header
			derived_client_classes.cpp(9): 			warning C4627: '#include "StdAfx.h"': skipped when looking for precompiled header use	| Add directive to 'pch_script.h' or rebuild precompiled header
			ui\UICellCustomItems.cpp(473): 			warning C4995: 'memset': name was marked as #pragma deprecated
			object_actions.cpp(56): 				warning C4310: cast truncates constant value
			pch_script.cpp(5): 						warning C4503: 'Loki::TL::Erase<TList,T>::In<Loki::Typelist<T,U>>' : decorated name length exceeded, name was truncated
			raypick.cpp(10): 						warning C4482: nonstandard extension used: enum 'collide::rq_target' used in qualified name
			ui\UIStatic.cpp(520): 					warning C4482: nonstandard extension used: enum 'CGameFont::EAligment' used in qualified name
			ui\UIDragDropListEx.cpp(110): 			warning C4482: nonstandard extension used: enum 'EUIMessages' used in qualified name
			ui\UIDragDropListEx.cpp(160): 			warning C4482: nonstandard extension used: enum 'EUIMessages' used in qualified name
			ui\UIMainIngameWnd.cpp(1273): 			warning C4482: nonstandard extension used: enum 'CUIWeaponCellItem::eAddonType' used in qualified name
			ui\UIMainIngameWnd.cpp(1279): 			warning C4482: nonstandard extension used: enum 'CUIWeaponCellItem::eAddonType' used in qualified name
			ui\UIMainIngameWnd.cpp(1285): 			warning C4482: nonstandard extension used: enum 'CUIWeaponCellItem::eAddonType' used in qualified name
			script_engine.cpp(434): 				warning C4482: nonstandard extension used: enum 'ScriptStorage::ELuaMessageType' used in qualified name
			ui/uiabstract.h(61): 					warning C4100: 'vis' : unreferenced formal parameter
			*************************************************************/

	/*		05_10_2017
	(+)		xrGame\WeaponMagazined.cpp 	---> HUD_SOUND::StopSound(sndReload);
	(/)		#pragma todo
	(/)		#pragma message
	(=)		// fixed warnings and errors //
	(+)		task_manager.script 		---> из репо KRodinn [НС2016] ---> чтобы не вылетало из-за диалогов.
	*/
	
	/* 		07_10_2017
	(/)		xrGame\xrServer_process_event_destroy.cpp 	---> SV:ge_destroy: [%d] not found on server
	(/)		xrGame\group_hierarchy_holder.cpp 			---> DEBUG: m_members.erase, member = %p 
	*/
	
	/* 		09_10_2017
	(+)		xrCore\xrCore.cpp 						---> CoUninitialize();
	(-)		xrCore\xrCore.cpp 						---> CoInitializeEx	(NULL, COINIT_MULTITHREADED);
	(=)		xrGame\hit_memory_manager.cpp   		---> Исправление неправильной загрузки памяти нпс: revolucas/CoC-Xray@01e05b0
	(=)		xrGame\sound_memory_manager.cpp 		---> Исправление неправильной загрузки памяти нпс: revolucas/CoC-Xray@01e05b0
	(=)		xrGame\visual_memory_manager.cpp 		---> Исправление неправильной загрузки памяти нпс: revolucas/CoC-Xray@01e05b0
	(=)		xrGame\DestroyablePhysicsObject.cpp 	---> who_object ? (who_object->lua_game_object()) : 0 		// by Alundaio //
	(=)		gamedata\config\misc\task_manager.ltx 	---> Ошибки в конфиге task_manager.ltx ---> запятые 		// by KRodin //
xxx	(=)		xrGame\ui\uiabstract.h 					---> SetTextureVisible(bool vis)	{m_bTextureVisible = vis;}
	(+)		xr_3da\xrGame\Weapon.cpp 				---> ONE_CLICK_ZOOM // Зум в один клик. Теперь не нужно удерживать клавишу прицеливания. //
	(+)		xr_3da\xrGame\Weapon.cpp 				---> if( ... (flags&CMD_START) ... ) // Corrected zooming in/out command handler // by Sin! //
	======= build 6822 =======		
	*/
	
	/*		17_10_2017
	(=)		xrCore\_cylinder.h 								---> _valid(c.m_radius); // by OpenXRay //
	(/)		xr_3da\xrGame\shared_data.h 					---> Log("DestroySingleton::RefCounter:",_refcount);
	(/)		xr_3da\xrGame\Level.cpp 						---> Msg("* ProcessGameEvents, spawn event postponed. Events rest = %d", game_events->queue.size());	
			-------------------------------------------------------------------------------------------------------------------------------
	(/)		xr_3da\xrGame\Inventory.cpp						---> Чтобы не было строки в выпадающем списке с действиями "Перенести в слот", когда предмет итак уже в слоте.
	(=)		xrGame\derived_client_classes.cpp 				---> ("eat_start_portions_num", &CEatableItem::m_iStartPortionsNum) // by Карлан //
	(=)		xrRender\WallmarksEngine.cpp 					---> Правка на 100% появление бладмарков // ssaCLIP // by SkyLoader //
	(=)		xr_3da\xrSheduler.cpp 							---> "../../build_config_defines.h" // by KRodin: добавил забытый инклуд //
			-------------------------------------------------------------------------------------------------------------------------------
	(-)		xrGame\ui\UIMainIngameWnd.h 					---> ui_disk_io ---> убрал с худа мигающую иконку дискеты.
	(-)		xrGame\ui\UIMainIngameWnd.cpp 					---> ui_disk_io ---> убрал с худа мигающую иконку дискеты.
	(-)		xrGame\ui\UIInventoryWnd.cpp 					---> ../build_config_defines.h
 	(+)		xrGame\ui\UIInventoryWnd.h 						---> ../build_config_defines.h
	(+)		xrGame\inventory_item.h 						---> ../build_config_defines.h
	(+)		xrGame\xrServer_process_event_ownership.cpp 	---> #ifdef DEBUG "sv !ownership ... " #endif
			-------------------------------------------------------------------------------------------------------------------------------
	(+)		gamedata\config\m_netpk.ltx						---> NET-packet -- by Artos --
	(+)		gamedata\scripts\m_netpk.script 				---> NET-packet -- by Artos --
	(+)		gamedata\scripts\m_netpk_readme.txt				---> NET-packet -- by Artos --
	(+)		gamedata\scripts\xr_box.script 					---> Правка проваливания предметов через текстуры при разбивании ящиков. -- Автор Bak. --
			-------------------------------------------------------------------------------------------------------------------------------
	(~)		gamedata\config\weapons\w_bolt.ltx 				---> force_grow_speed	= 15 ;; скорость набора силы броска (метры в секунду)
	(~)		gamedata\config\ui\inventory_new.xml
	(~)		gamedata\config\ui\inventory_new_16.xml
	(+)		gamedata\scripts\ui_main_menu.script
			-------------------------------------------------------------------------------------------------------------------------------
	(+)		gamedata\scripts\ui_cheat_base.script 			---> Спаун-меню -- by naxac --
	(+)		gamedata\scripts\ui_cheat_naxac.script 			---> Спаун-меню -- by naxac --
	(+)		gamedata\textures\ui\ui_cheat_naxac.dds			---> Спаун-меню -- by naxac --
	(+)		gamedata\textures\ui\ui_inv_belt_w_slots.dds 	---> Текстура для инвентаря.
			-------------------------------------------------------------------------------------------------------------------------------
	(+)		xrGame\ui\UICarBodyWnd.cpp 						---> HIDE_WEAPON_IN_INV
	(+)		xrGame\ui\UIPdaWnd.cpp							---> HIDE_WEAPON_IN_INV
	(+)		xrGame\ui\UIWpnParams.cpp 						---> wpn_knife ---> Чтобы не отображались полоски точности, скорострельности для ножа.
 	(/)		xrGame\alife_simulator_base.cpp 				---> Msg("#SE_DBG: CALifeSimulatorBase '%s' ->m_objects = 0x%p ",
	(+)		xrCore\LocatorAPI.cpp 							---> #pragma warning(pop)
	(~)		xrGame\ai\monsters\basemonster\base_monster_startup.cpp ---> color_gray, color_add // by PVS-Studio //
			-------------------------------------------------------------------------------------------------------------------------------
	======= build 6834 =======			
	*/
	
	/*		25_10_2017
			3rd party\Xiph\libvorbis\lib\info.c 				---> #pragma warning(disable:4996)
			xr_3da\xrGame\ui\UIMainIngameWnd.cpp				---> CUIWindow* sil = ...
			xr_3da\xrGame\Weapon... 							---> [Bugfix] Incorrect weapon weight calculation // by Sin! //
	======= build 6837 (Глюк: НПС без оружия, если дальше границы прехода оффлайн-онлайн. TODO: пофиксить это!!! ) =======
	*/
	
	/*		26_10_2017
	(~)		xrGame\game_base.h 								---> BlockedByID = 0; BlockTime = 0; 							// by PVS-Studio //
xxx	(=)		xrGame\ui\uiabstract.h 							---> SetTextureVisible(bool vis)	{m_bTextureVisible = vis;} 	// by PVS-Studio // 
															---> Есть подозрениея, что из-за этого, пропадает оружие у НПС. //
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	(~)		xrGame\ai\crow\ai_crow.cpp 						---> [Bugfix] Crows fix 										// by Sin! //
	(~)		xrGame\WeaponMagazinedWGrenade.cpp 				---> [Bugfix] Fix disappearing grenade 							// by Sin! //
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	(~)		xrGame\WeaponBinoculars.cpp 					---> m_fRTZoomFactor = g_fov; ---> чтобы, у бинокля был меньший зум изначально.
	(=)		xrGame\AI\Crow\ai_crow.cpp 						---> Вороны больше не вылетают из одной точки на земле 							// by Charsi //
	(=)		xrGame\CustomMonster.cpp 						---> Фикс зависания шкалы освещенности/заметности при переходе врага в оффлайн 	// by KRodin //
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	(=)		gamedata\scripts\xr_effects.script 				---> Так вот из-за чего краснел снайпер на базе Свободы при подходе к забору! 	-- by KRodin --
	(~)		gamedata\scripts\xr_motivator.script 			---> motivator_binder:reinit() ---> if self.object:alive() then
	(~)		gamedata\scripts\gulag_military.script 			---> Мутанты на барьере будут нападать не дожидаясь полного кол-ва. А то толпятся всё время у перехода на радар -- by KRodin --
	(~)		gamedata\scripts\xr_meet.script 				---> Чтобы не стояли и не пялились часами. -- Не знаю, кто автор. --
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	(=)		gamedata\config\scripts\yan\yan_scientist.ltx 	---> Чтобы Сахаров не повторял одну и туже фразу после загрузки сейва. 			;; by KRodin ;;
	(+)		gamedata\config\text\rus\ui_st_other.xml 		---> Создание актора ---> st_actor_netspawn
	(/)		gamedata\config\ui\maingame.xml 				---> ui_hud_icon_PDA 		---> Надоедливая мигающая иконка ПДА.
	(/)		gamedata\config\ui\maingame_16.xml 				---> ui_hud_icon_PDA 		---> Надоедливая мигающая иконка ПДА.
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	(=)		xrGame\ai\trader\trader_animation.cpp 			---> Звуки торговца теперь идут от торговца, а не проигрываются в голове у ГГ 	// by abramcumner //
	(=)		xrGame\ai\trader\trader_animation.cpp 			---> Теперь задаю позицию при проигрывании 3Д-звука торговцем  					// by abramcumner //
xxx	(=)		xrGame\Ai\Trader\ai_trader.cpp 					---> Теперь торговец не крутит головой вслед за ГГ  							// by abramcumner //
	(=)		xrGame\ui\UIButton.cpp 							---> fixed OnMouseAction 														// by kolmogor //
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	(+)		xrGame\inventory_item.h 						---> virtual void SetWeight(float w){ m_weight = w; } ---> Нужна для EAT_PORTIONS_INFLUENCE
	(+)		xrGame\eatable_item.cpp 						---> EAT_PORTIONS_INFLUENCE ---> Уменьшаем вес и цену предмета, после использования. 	// by Real Wolf //
	(+)		xrGame\Actor.cpp 								---> RepackAmmo() 			---> Перепаковщик патронов 									// by Charsi //
	(-)		xrGame\GamePersistent.cpp 						---> Убирано троеточие в строках, типа: "Клиент:Синхронизация..." ---> sprintf_s (buff, "%s...", CStringTable().translate(str).c_str());
	(+)		xrGame\eatable_item.h 							---> int GetStartPortionsNum() const { return m_iStartPortionsNum; }; 					// by Shkiper2012 //
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	======= build 6842 =======
	*/
	
	/*		07_11_2017
	(+)		// Методы для предметов на классе CEatableItem // by Shkiper2012 //
			int GetPortions();					---> local portions 	  = obj:get_portions()
			int GetStartPortions(); 			---> local start_portions = obj:get_start_portions()
			--
			xr_3da\xrGame\script_game_object_script3.cpp
			xr_3da\xrGame\script_game_object.h
			xr_3da\xrGame\script_game_object.cpp
			--
			Для несъедобных предметов будет всегда = 0.
			У съедобных ---> если порции = -1, будет возвращать = 1.
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
xxx	(=)		Отключил правку 					---> "Торговец не крутит головой вслед за ГГ" 						---> т.к. он стал как слепой, смотрит в одну точку.
	(+)		xrGame\ui\UITradeWnd.h 				---> Заливка предметов, которые в слоте или на поясе, синим цветом. ---> ColorizeItem()
	(+)		xrGame\ui\UITradeWnd.cpp 			---> + Добавлена проверка на флаг "Не-торгуемости".  				---> ColorizeItem()
	(+)		xrGame\ui\UICarBodyWnd.h 			---> Заливка предметов, которые в слоте или на поясе, синим цветом. ---> ColorizeItem()
	(+)		xrGame\ui\UICarBodyWnd.cpp 			---> Заливка предметов, которые в слоте или на поясе, синим цветом. ---> ColorizeItem()
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	(-)		Вырезал все ссылки на "BATTLEYE"
	(-)		Удалены все ссылки на "xrd3d9-null"
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	======= build 6850 =======			
	*/
	
	/*		10_11_2017
	(~)		xrGame\ai\Monsters\Controller\controller_psy_aura.cpp ---> небольшие правки ---> m_fake_max_add_dist, m_fake_min_add_dist.
	(=)		xrGame\ui\UICarBodyWnd.cpp 						---> fix scrolling
	(+)		xrGame\script_engine.cpp 						---> lua_gc (lua(),LUA_GCCOLLECT,0); 	---> CScriptEngine::collect_all_garbage()
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
xxx	(+)		xrGame\ui\UICellItem.cpp 						---> xr_delete 							---> если, включить эту правку, то будет !вылет! при использовании инвентаря. <---
	(+)		xrGame\ui\UIInventoryWnd.h 						---> бинокль, фонарь, нож.
	(+)		xrGame\ui\UIInventoryWnd.cpp 					---> бинокль, фонарь, нож + небольшие правки: if( !pActor ) return;
	(+)		xrGame\ui\uiinventorywnd2.cpp 					---> бинокль, фонарь, нож + UIPropertiesBox.IsShown
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	(~)		xrGame\ui\UIInventoryWnd3.cpp 					---> небольшие правки 					---> !m_pInv->InSlot(CurrentIItem())
	(~)		xrGame\ui\UIMainIngameWnd.cpp 					---> небольшие правки 					---> ALife::_OBJECT_ID _id
	(~)		xrGame\ui\UIScrollBar.cpp						---> небольшие правки 					---> +1
	(~)		xrGame\ui\UITradeWnd.cpp 						---> небольшие правки 					---> обновляем только торговый лист тогровца.
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	(+)		xrGame\alife_simulator_script.cpp 				---> iterate_objects() 					// by Charsi // 
	(-)		xrGame\base_client_classes_script.cpp 			---> удалил ---> ::EIIFlags:: 			// fixed C4482 //
	(~)		xrGame\console_commands.cpp 					---> CCC_DemoRecord 					---> не включаем, если локация не загружена, 
	(~)														---> CCC_LoadLastSave 					---> проверка существует ли сейв, 
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	(~)		xrGame\alife_update_manager.cpp 				---> 'change_level_autosave' 			---> название сейва при переходе на другую локацию.
	(+)		xrGame\CustomOutfit.cpp 						---> m_eItemPlace == eItemPlaceSlot
	(=)		xrGame\CustomZone.cpp 							---> Исправление не отключения света после выключения аномалии. // by lvg_brest //
	(~)		xrGame\InventoryBox.h 							---> public: xr_vector<u16> m_items; 	---> для IterateInventoryBox()
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	|>>>| 	Вырезаем авто-сейв. 							|>>>|
	(-)		xrGame\Actor_Sleep.cpp							---> #include "autosave_manager.h" 
	(-)		xrGame\Level.h									---> #include "autosave_manager.h" 		---> CAutosaveManager  *m_autosave_manager;
	(-)		xrGame\Level.cpp								---> #include "autosave_manager.h" 		---> CAutosaveManager  *m_autosave_manager;
	(-)		xrGame\ActorCondition.cpp 						---> #include "autosave_manager.h"
	(-)		xrGame\console_commands.cpp 					---> #include "autosave_manager.h"  +  if (!Level().autosave_manager().ready_for_autosave()){ ...
	(-)		xrGame\Level_input.cpp 							---> #include "autosave_manager.h"
	(-)		xrGame\enemy_manager.h 							---> #include "autosave_manager.h" 		---> set_ready_to_save()
	(-)		xrGame\enemy_manager.cpp 						---> #include "autosave_manager.h" 		---> set_ready_to_save()
	(-)		xrGame\CustomMonster.h 							---> set_ready_to_save()
	(-)		xrGame\CustomMonster.cpp 						---> set_ready_to_save()
	(-)		xrGame\Entity.h									---> set_ready_to_save()
	(-)		xrGame\Entity.cpp								---> set_ready_to_save()
	|<<<| 	Вырезаем авто-сейв. 							|<<<|
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	(+)		xrGame\level_script.cpp							---> iterate_online_objects(), 			// by Charsi //
															---> GetTargetObj(), GetTargetDist(), 	// by Golden Sphere Mod //
	(+)		xrGame\script_game_object.h						---> IterateBelt() 						// by Kondr48 //
															---> IterateInventoryBox() 				// кто-то перенес из ЧН //
															---> void SetActorDirection( float dir, float pitch, float roll );
	(~)		xrGame\script_game_object2.cpp					---> void SetActorDirection( float dir, float pitch = 0.f, float roll = 0.f)
	(+)		xrGame\script_game_object_inventory_owner.cpp 	---> IterateBelt(), IterateInventoryBox()
	(+)		xrGame\script_game_object_script3.cpp 			---> IterateBelt(), IterateInventoryBox()
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	(+)		xrGame\script_particles.cpp 					---> if (!m_particles) Msg("CScriptParticles::CScriptParticles : critical error ...
	(/)		xrGame\trade2.cpp 								---> небольшие правки 					---> //float deficit_factor = 1.f;
	(+)		xrGame\WeaponRG6.cpp							---> небольшие правки 					---> if(GetState() == eIdle && iAmmoElapsed ... + return t;
	(~)		xrGame\xrServer_Objects_script.cpp 				---> setup_direction 					---> sobj:setup_direction( x, y, z )
	(+)		xr_object_list.h 								---> IC xr_map<u32,CObject*> GetMap() 	---> для iterate_online_objects()
	(~)		xrGame\ui\UIDragDropListEx.cpp 					---> немного ускорим скролл 			---> for( u8 i = 0; i < 3; ++i ) m_vScrollBar->TryScrollInc();
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	======= build 6853 =======			
	*/

	/*		12_11_2017
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	(+)		Функция перемотки времени из CoP 				---> level.change_game_time( u32 days, u32 hours, u32 mins ) 				// by Kondr48 //
			level_script.cpp
			alife_time_manager.h
			alife_time_manager_inline.h 
			Environment.h
			Environment.cpp
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	(~) 	xrGame\game_sv_single.cpp 						---> st_restart_simulator ---> game_sv_Single::restart_simulator
	(/)		xrGame\xrServer.cpp 							---> Player not found. New player created.
	(/)		xrNetServer\NET_Server.cpp 						---> MaxPlayers = 32
	(+)		xrGame\console_commands.cpp 					---> Ставим паузу во время быстрого сохранения. ---> Device.Pause( TRUE, ...
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
xxx	(=)		xrGame\ActorAnimation.cpp 						---> Измененная анимация безоружного ГГ "_torso_0_aim_0"->"_torso_5_aim_0" 	// by Cut X-Ray // 
xxx															---> Вылет из-за отсутствия этой анимации: 'cl_torso_5_aim_0'
	(=)		xrGame\WeaponMagazinedWGrenade.cpp 				---> m_fZoomFactor = g_fov; 												// Karlan: сбрасываем зум. //
	(=)		xrRender\xrRender_console.cpp					---> Исправлен "купол" над актором, вызывающий баг с тенями. 				// by Stalker_Monolit //
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	(=)		xrGame\derived_client_classes.cpp 				---> scrope_zoom_factor ---> scope_zoom_factor
	(-)		xrGame\alife_anomalous_zone.cpp 				---> ;;
	(+)		xrGame\PhraseScript.cpp 						---> R_ASSERT3(functor_exists, "Cannot find precondition: ...
	(+)		Environment_misc.cpp 							---> Проверка на "CEnvAmbient::load: sound_section '%s' not found"
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	(+)		xrGame\key_binding_registrator_script.cpp 		---> добавлены бинды клавиш key_bindings и DIK_keys из _g.script
	(+)		xrGame\UICustomItem.cpp							---> float kx =	(UI()->is_16_9_mode())?(UI()->get_current_kx()):1.0f;
	(+)		xrGame\ui_base.h								---> get_current_kx()
	(+)		xrGame\ui_base.cpp								---> get_current_kx()
			-------------------------------------------------------------------------------------------------------------------------------------------------------------------
	======= build 6854 (вылет из-за отсутствия анимации безоружного ГГ: 'cl_torso_5_aim_0' ) =======			
	*/
	
#endif

#ifndef Legend & Shkiper_Marker's
	// xxx - откат правки. //
	// UNKNOW_shkiper_marker // 	-  (?)  - узнать, что это, для чего, как используется, если используется.
	// TODO_shkiper_marker // 		-  (#)  - (нужно/желательно) сделать!
	// WIP_shkiper_marker //		-  (@)  - делаю сейчас!
	// ADD_shkiper_marker // 		-  (+)  - добавлено
	// DELME_shkiper_marker //  	-  (-)  - можно/нужно удалить! либо уже удалено!
	// CHANGE_shkiper_marker //  	-  (~)  - изменено
	// BUG_FIX_shkiper_marker //  	-  (=)  - пофикшено
	// FIXME_shkiper_marker //  	-  (!)  - !!!Нужно исправить!!!
	// INFO_shkiper_marker //  		-  (i)  - Принять к сведению, может пригодиться!
	// COMMENT_shkiper_marker //  	-  (/) 	- закомментировал.
 	// >>> ---> -- начало куска кода/сообщения -- >>> begin >>>
 	// <<< <--- --  конец куска кода/сообщения -- <<< end <<<
	// Формат даты изменения: 00_00_0000 //
#endif