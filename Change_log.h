#ifndef Changes_log

	/*		30_09_2017
			-----------------------------------------------------------------------------------------------------------------------
	gamedata:
	(~)		system.ltx 				---> slot
	(+)		items.ltx 				---> [detektor_...] ---> belt = true
	(+)		actor.ltx 				---> camera_height_factor = 0.95
	(+) 	task_manager.script 	---> проверка на 'defend_object'
			-----------------------------------------------------------------------------------------------------------------------
	(/)		ui_st_other.xml 		---> ui_quick_slot_use_str_0
	(/)		ui_keybinding.xml	 	---> kb_slot_quick_0
	(=)		inventory_new.xml 		= condition_prog_ess_bar ---> condition_progRess_bar (1/3)
	(=)		inventory_new_16.xml 	= condition_prog_ess_bar ---> condition_progRess_bar (2/3)
			-----------------------------------------------------------------------------------------------------------------------
	xray:
	(=)		UICellItem.cpp 			= condition_prog_ess_bar ---> condition_progRess_bar (3/3)
	(+)		3rd party\Xiph\libvorbis\lib\info.c ---> #pragma warning(disable:4238) 
	(+)		base_client_classes_script.cpp 		---> #pragma warning(disable:4482)
	(+)		UIMainIngameWnd.cpp.cpp 			---> #pragma warning(disable:4482)
			-----------------------------------------------------------------------------------------------------------------------
	(=)		script_game_object_script.cpp 	---> 'ePostSave' ---> eBeforeSave'
	(+)		FStaticRender.cpp 				---> KD_DETAIL_RADIUS ---> #include "../../../build_config_defines.h"
	(+)		r2.cpp 							---> KD_DETAIL_RADIUS ---> #include "../../../build_config_defines.h"
			-----------------------------------------------------------------------------------------------------------------------
	(+) 	SoundRender_Source_loader.cpp 	---> При отсутствии звукового файла будет сообщение в консоли. 	// by Zagolski //
	(=)		actor_statistic_mgr.cpp 		---> Исправление учета статистики 								// by lvg_brest //
	(=)		HangingLamp.cpp 				---> if(!PPhysicsShell()) 	// Очень странный вылет 			// by SkyLoader //	
	(+)		UIInventoryWnd.cpp 				---> #define HIDE_WEAPON_IN_INV 	// Спрячем/показываем предмет в руках, когда откр./закр. инвентарь. // by Shkiper2012 //
			-----------------------------------------------------------------------------------------------------------------------
	(=)		Inventory.cpp 			---> Если на ГГ надет броник с включенным ПНВ, то надо его выключить. // by Kondr48 //
	(=) 	WeaponMagazined.cpp 	---> m_set_next_ammoType_on_reload 	// by 'Gunslinger mod' // 
	(=) 	WeaponMagazined.cpp 	---> #define NO_AUTO_RELOAD_WPN 	// Блокируем авто-перезарядку и сброс зума, когда закончились патроны. // by Shkiper2012 //
	(=) 	x_ray.cpp 				--->  Фикс полосы загрузки 			// by SkyLoader //	
			-----------------------------------------------------------------------------------------------------------------------
	(=)		UIDiaryWnd2.cpp 		---> Исправление отображения зеленым цветом прочитанных записей в разделе КПК Дневник. // by lvg_brest //
	(=)		UIDiaryWnd.h 			---> ...
	(=)		UICarBodyWnd.cpp 		---> Исправление отображения параметра "отношение" при обыске тел монстров // by lvg_brest //
	(=)		UICharacterInfo.cpp		---> ... + Исправление работы статика биографии в разделе КПК Ранги.cpp
	(=)		UICharacterInfo.h		---> ...
			-----------------------------------------------------------------------------------------------------------------------
	(=)		UIGameTutorialSimpleItem.cpp 	---> Исправление залипания курсора мыши в главном меню после просмотра титров.cpp // by lvg_brest //
	(=)		Level_network.cpp 				---> Исправление сохранения клиентских объектов. // by Shoker //
	(=)		HW.cpp 							---> Фикс вертикальной синхронизации (r2) // by SkyLoader //
	(=)		ActorInput.cpp 					---> #define NO_MOUSE_WHELL_SWITCH_SLOT // Убирает возможность переключаться между слотами колесиком мыши. // by Shkiper2012 //
			-----------------------------------------------------------------------------------------------------------------------
	(~) 	xrCore\log.cpp 			---> force_flush_log = true; ---> нужно, чтобы поймать вылет после разговора с НПС, которые что-нибудь передают ГГ.
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
	(+)		xrGame\EffectorZoomInertion.h 				---> + ../ ---> "../../../build_config_defines.h"
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
	(+)		libtheora\lib\analyze.c 			---> ... = {0, 0}; 					// CHANGE_shkiper_marker // 02_10_2017 // fixed C4132 //
	(+)		libtheora\lib\mcenc.c 				---> #pragma warning(disable:4127) 	// CHANGE_shkiper_marker // 02_10_2017 // fixed C4132 //
	(+)		libtheora\lib\x86_vc\mmxencfrag.c 	---> ret --> ret1 и ret2 			// CHANGE_shkiper_marker // 02_10_2017 // fixed C4405 //
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
			xrgame\game_cl_artefacthunt.cpp(442): 		warning C4723: potential divide by 0
			xrGame\ui\UIProgressShape.cpp				warning C4723: potential divide by 0
			x:\trunk\3rd party\xiph\libtheora\lib\decode.c(1582): 			warning C4701: potentially uninitialized local variable 'last_zzi' used
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
	(+)		task_manager.script 		---> из репо KRodinn ---> чтобы не вылетало из-за диалогов.
	*/
	
	/* 		07_10_2017
	(/)		xrGame\xrServer_process_event_destroy.cpp 	---> SV:ge_destroy: [%d] not found on server
	(/)		xrGame\group_hierarchy_holder.cpp 			---> DEBUG: m_members.erase, member = %p 
	*/
	
	/* 		09_10_2017
	(+)		xrCore\xrCore.cpp ---> CoUninitialize();
	(-)		xrCore\xrCore.cpp ---> CoInitializeEx	(NULL, COINIT_MULTITHREADED);
	(=)		xrGame\hit_memory_manager.cpp   		---> Исправление неправильной загрузки памяти нпс: revolucas/CoC-Xray@01e05b0
	(=)		xrGame\sound_memory_manager.cpp 		---> Исправление неправильной загрузки памяти нпс: revolucas/CoC-Xray@01e05b0
	(=)		xrGame\visual_memory_manager.cpp 		---> Исправление неправильной загрузки памяти нпс: revolucas/CoC-Xray@01e05b0
	(=)		xrGame\DestroyablePhysicsObject.cpp 	---> who_object ? (who_object->lua_game_object()) : 0 	// fixed by Alundaio //
	(=)		gamedata\config\misc\task_manager.ltx 	---> Ошибки в конфиге task_manager'a ---> запятые 		// fixed by KRodin //
	(=)		xrGame\ui\uiabstract.h 					---> SetTextureVisible(bool vis)	{m_bTextureVisible = vis;}
	(+)		xr_3da\xrGame\Weapon.cpp 				---> ONE_CLICK_ZOOM // Зум в один клик. Теперь не нужно удерживать клавишу прицеливания.
	*/
	
	/* 		10_10_2017
	(=)		xrCore\_cylinder.h 					--->  _valid(c.m_radius); // by OpenXRay //
	(=)		xrGame\ActorEffector.cpp 			---> OpenXRay/xray-16@741031c
	(=)		xrGame\ai\stalker\ai_stalker.cpp 	---> OpenXRay/xray-16@741031c
	(/)		xr_3da\xrGame\shared_data.h 		---> Log("DestroySingleton::RefCounter:",_refcount);
	(/)		xr_3da\xrGame\Level.cpp 			---> Msg("* ProcessGameEvents, spawn event postponed. Events rest = %d", game_events->queue.size());	
	(/)		xr_3da\xrGame\Inventory.cpp			---> Чтобы не было строки в выпадающем списке с действиями "Перенести в слот", когда предмет итак уже в слоте.
	(=)		xrGame\weaponBM16.cpp 				---> (с) НаноБот фикс вылета: если не нашли нужной анимацией для класса БМ16. 26.09.2016
	(=)		xrGame\derived_client_classes.cpp 	---> ("eat_start_portions_num", &CEatableItem::m_iStartPortionsNum) // by Карлан //
	(=)		xrRender\WallmarksEngine.cpp 		---> Правка на 100% появление бладмарков // by SkyLoader //
	*/

#endif

#ifndef Shkiper_Marker's
	// UNKNOW_shkiper_marker // 	-  (?)  - узнать, что это, для чего, как используется, если используется.
	// TODO_shkiper_marker // 		-  (#)  - (нужно/желательно) сделать!
	// WIP_shkiper_marker //		-  (@)  - делаю сейчас!
	// ADD_shkiper_marker // 		-  (+)  - добавлено
	// DELME_shkiper_marker //  	-  (-)  - (можно/нужно) удалить!
	// CHANGE_shkiper_marker //  	-  (~)  - изменено
	// BUG_FIX_shkiper_marker //  	-  (=)  - пофикшено
	// FIXME_shkiper_marker //  	-  (!)  - !!!Нужно исправить!!!
	// INFO_shkiper_marker //  		-  (i)  - Принять к сведению, может пригодиться!
	// COMMENT_shkiper_marker //  	-  (/) 	- закомментировал.
 	// >>> ---> -- начало куска кода/сообщения -- >>> begin >>>
 	// <<< <--- --  конец куска кода/сообщения -- <<< end <<<
	// Формат даты изменения: 	00_00_000
#endif
