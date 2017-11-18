--[[ -------------------------------------------------------------------------------------------------------
-- File: 			_test_script_pcall.lua
-- Idea: 			Malandrinus
-- Description: 	Тестовый полигон для экспериментов со скриптами. Запускается в безопасном режиме (pcall).
------------------------------------------------------------------------------------------------------------
-- local debug_log 		= false 	-- Пишем лог? 	Да = true / Нет = false
-- local module_init 	= true
-- local module_name 	= script_name()
-- local dbg_logf 		= function(fmt,...) if debug_log then log1(fmt,...) end end
-- if module_init then
	-- dbg_logf("**DBG: INIT_MODULE: "..module_name..".script -- Ok. --")
-- end
------------------------------------------------------------------------------------------------------------
-- log1(" " ..tostring(  ) )
-- dbg_logf(" " ..tostring(  ) )
--]] -------------------------------------------------------------------------------------------------------
if (not log1) or (type(log1) ~= 'function')  then
	local console = nil
	log1 = function(fmt, ...)
		if not console then console = get_console() end
		console:execute(string.gsub(string.format(fmt,...), " ", "_"))
	end
end
local ini = system_ini() local function dbg_logf(fmt,...) log1(fmt,...) end

 
 
 
 
 
 
	
	
	

-------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------


-- Перезагрузка скрипта. --
-- _G.bind_stalker = nil
-- __scripts_header_add.add_header()


--[=[ 	-- Смотрим какой сейчас сэт погоды и его секции. --
function show_sect_weather()
    local time_h 		= sr_timer.time2str(level.get_time_hours()) -- текущий игровой час
	local ini 			= system_ini()								-- для чтения конфигов
	local weather 		= level.get_weather() 						-- текущий тип погоды
	local weather_sect 	= ini:r_string("weathers", weather) 		-- секция погоды, соответствующая текущему типу
	local weather_time 	= tostring(time_h)..":00:00"				-- какой текущий час погоды в текущей секции
	
	if ini:section_exist(weather_sect) and ini:line_exist(weather_sect, weather_time) then
		local time_sect = ini:r_string(weather_sect, weather_time) 			-- секция текущей погоды на данный час
		news_manager.send_tip(db.actor, "Сэт погоды    : "..tostring(weather)..
									 "\\nТекущая секция : "..tostring(time_sect).."", nil, nil, 7000)
	else
		news_manager.send_tip(db.actor, "Сэт погоды: "..tostring(weather).."\\nВнмание! \\nТекущая секция погоды отсутствует в сэте!", nil, nil, 7000)
	end 
end 
show_sect_weather()
--]=]


--[=[ 	-- FOV --
-- original_fov_shoc = 67.5
-- local f = device().fov -- текущий fov, на данный момент.
-- log1("  device().fov  =  "..tostring( f ))

local g = device():get_fov()
log1("  device().fov  =  "..tostring( g ))

device():set_fov( 67.5 )

local h = device():get_fov()
log1("  device().fov  =  "..tostring( h ))
--]=]


--[=[ 	-- iterate_objects -- итерация по объектам. -- довольно дорогая ф-ция, лучше пользовать при загрузке локации. --
local func = function( sobj )
	local sobj_name = sobj:name()
	log1(" sobj_name = ".. tostring( sobj_name ))
-- 	local sobj_sect_name = sobj:section_name()
-- 	log1(" sobj_sect_name = ".. tostring( sobj_sect_name ))
end
alife():iterate_objects( func )
--]=]


--[=[ 	-- iterate_online_objects -- итерация по онлайн-объектам. --
	local func = function( obj )
		local obj_sect = obj:section()
		log1("obj_sect = ".. tostring( obj_sect ))
	end
	level.iterate_online_objects( func )
--]=]


--[=[ 	-- get_target_obj() -- объект на который смотрим -- get_target_dist() -- дистанция до объекта, на который смотрим. --

	local target_obj 	= level.get_target_obj()
	local target_dist 	= level.get_target_dist()
	local section 		= target_obj:section()
	local target_obj_id = target_obj:id()
	
	log1("section = "..tostring(section))
	log1("target_dist = "..tostring(target_dist))
	log1("target_obj_id = "..tostring(target_obj_id))
--]=]


--[=[ 	-- iterate_inventory_box() -- итерация по ящику. --

-- 	local sobj = alife():object( 1078 ) 		-- Ящик в лагере новичков, у костра. --
-- 	local inv_box = level.object_by_id(sobj.id)
	
	local inv_box = level.object_by_id( 1078 )	-- Ящик в лагере новичков, у костра. --
	if inv_box then
		log1(" inv_box 2 ")
		local func = function( item )
			local section = item:section()
			log1("section = "..tostring(section))
		end
		inv_box:iterate_inventory_box( func )
	end
--]=]


--[=[ 	-- iterate_belt() -- итерация по поясу ГГ. --
	local func = function( item )
		local section = item:section()
		log1("section = "..tostring(section))
	end
	db.actor:iterate_belt( func, db.actor )
--]=]


--[=[ 	-- UsedAI_Locations -- Правка проваливания предметов через текстуры при разбивании ящиков. -->>-- Автор Bak. -->>--
		local obj_itm 	= alife():create( item, position, obj:level_vertex_id(), obj:game_vertex_id() )
		local sobj_item = alife():object( obj_itm.id )
		local pk 		= m_netpk.get( sobj_item )
		local data 		= pk:get()
		data.object_flags = bit_and( data.object_flags, bit_not( 128 ) ) 	-- снять 		флаг flUsedAI_Locations
	-- 	data.object_flags = bit_or(data.object_flags, 128) 					-- установить 	флаг flUsedAI_Locations
		pk:set( data )
--]=]


--[=[ 	-- spawn_item_in_inv --
function spawn_item_in_inv(section,npc)
	local npc = (npc or db.actor)
	
	local sobj_abstr = alife():create(section,
			npc:position(),
			npc:level_vertex_id(),	
			npc:game_vertex_id(),
			npc:id())
	if sobj_abstr then
		return alife():object(sobj_abstr.id)
	else	

		return false
	end
end
local t ={
	"novice_outfit",
	"outfit_novice_m1",
	"bandit_outfit",
	"outfit_bandit_m1",
	"killer_outfit",
	"outfit_killer_m1",
	"monolit_outfit",
	"specops_outfit",
	"outfit_specnaz_m1",
	"military_outfit",
	"stalker_outfit",
	"outfit_stalker_m1",
	"outfit_stalker_m2",
	"scientific_outfit",
	"exo_outfit",
	"outfit_exo_m1",
	"svoboda_light_outfit",
	"svoboda_heavy_outfit",
	"outfit_svoboda_m1",
	"dolg_outfit",
	"outfit_dolg_m1",
	"dolg_scientific_outfit",
	"ecolog_outfit",
	"protection_outfit"
}


for k, v in pairs( t ) do 
	spawn_item_in_inv(v)
end
--]=]


--[=[ 	-- Цветной текст в логе... --
log1("##Проверка лога...") -- синевато-зеленый 	-- не заметное.
log1("~~Проверка лога...") -- жёлтый 			-- нужное
log1("**Проверка лога...") -- серый 			-- не значительные
log1("!!Проверка лога...") -- красный 			-- ошибка
log1("--Проверка лога...") -- зелёный 			-- все нормально, заметное.
--]=]


--[=[ 	-- Высота камеры актора. --
-- Установка высоты камеры актора. --
function set_camera_height(v)
	db.actor:set_actor_float(nil, v, 1204)
end

-- Получение высоты камеры актора. --
function get_camera_height()
	return db.actor:get_actor_float(1204)
end

-- Получение высоты камеры актора из файла "actor.ltx". --
function get_camera_height_default()
	return system_ini():r_float ("actor","camera_height_factor")
end
--]=]


--[=[ 	-- Спавн --
-- Рыжий лес --
-- alife():create("lim_monolith_str1_respawn",vector():set(-107.492,0.274,-270.274), 10879, 3241)
-- alife():create("lim_monolith_str2_respawn",vector():set(-108.492,0.274,-270.274), 10879, 3241)
-- alife():create("lim_monolith_str3_respawn",vector():set(-109.492,0.274,-270.274), 10879, 3241)
-- alife():create("lim_monolith_str4_respawn",vector():set(-110.492,0.274,-270.274), 10879, 3241)
-- alife():create("lim_monolith_str5_respawn",vector():set(-111.492,0.274,-270.274), 10879, 3241)
-- alife():create("lim_monolith_str6_respawn",vector():set(-112.492,0.274,-270.274), 10879, 3241)
-- alife():create("lim_monolith_str7_respawn",vector():set(-113.492,0.274,-270.274), 10879, 3241)
------------------
-- alife():create("rf_dolg_razvedch1",vector():set(-111.492,0.274,-270.274), 10879, 3241)
-- alife():create("rf_dolg_razvedch2",vector():set(-112.492,0.274,-270.274), 10879, 3241)
-- alife():create("rf_dolg_razvedch3",vector():set(-113.492,0.274,-270.274), 10879, 3241)
-- alife():create("rf_dolg_razvedch4",vector():set(-114.492,0.274,-270.274), 10879, 3241)

-- Лиманск --
-- alife():create("lim_monolith_str1_respawn",vector():set(43.492,8.274,224.274), 46629, 3021)
-- alife():create("lim_monolith_str2_respawn",vector():set(44.492,8.274,224.274), 46629, 3021)
-- alife():create("lim_monolith_str3_respawn",vector():set(45.492,8.274,224.274), 46629, 3021)
-- alife():create("lim_monolith_str4_respawn",vector():set(46.492,8.274,224.274), 46629, 3021)
-- alife():create("lim_monolith_str5_respawn",vector():set(47.492,8.274,224.274), 46629, 3021)
-- alife():create("lim_monolith_str6_respawn",vector():set(48.492,8.274,224.274), 46629, 3021)
-- alife():create("lim_monolith_str7_respawn",vector():set(49.492,8.274,224.274), 46629, 3021)
--]=]


--[=[ 	-- Вылеты --
---------------------------------------------------------------------------------------------------------
stack traceback:
	d:\games\s.t.a.l.k.e.r\gamedata\scripts\_g.script:1403: in function 'abort'
	...games\s.t.a.l.k.e.r\gamedata\scripts\xr_sound.script:184: in function 'play_sound'
	...games\s.t.a.l.k.e.r\gamedata\scripts\xr_sound.script:163: in function 'update'
	...s\s.t.a.l.k.e.r\gamedata\scripts\xr_motivator.script:401: in function <...s\s.t.a.l.k.e.r\gamedata\scripts\xr_motivator.script:371>
!![error] ABORT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
!![error] ABORT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
!![error] ABORT ~~~ ОПИСАНИЕ ОШИБКИ: 
!![error] ABORT ~~~ ERROR: ILLEGAL PLAY SOUND!!! false for opkon71_sold3 1499
!![error] ABORT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
!![error] ABORT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
!![error] ABORT ~~~ abort_counter  =  3
!![error] ABORT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Log file has been saved successfully!
---------------------------------------------------------------------------------------------------------

-- 001B:037A6EBC xrGame.dll
-- 001B:037A7029 xrGame.dll
-- 001B:037F3550 xrGame.dll

-- 001B:03636EBC xrGame.dll
-- 001B:03637029 xrGame.dll
-- 001B:03683550 xrGame.dll
[error][       8]    : Недостаточно памяти для обработки команды.
---------------------------------------------------------------------------------------------------------
-- 001B:03788A20 xrGame.dll
-- 001B:03788D85 xrGame.dll
-- 001B:00412076 XR_3DA.exe, CApplication::OnEvent()
-- 001B:004BAE80 XR_3DA.exe, CEvent::Signal()
---------------------------------------------------------------------------------------------------------
--]=]--


--[=[ 	-- Таймер для замера работы скрипта. --

--> START timer >---------------------------------------------------------------------------
-- local PTimer = profile_timer()
-- log1("--Start_Profile_Timer")
-- PTimer:start()
--> ----------------------------------------------------------------------------------------


-- bla bla bla ... --


--< ----------------------------------------------------------------------------------------
-- PTimer:stop()
-- log1("--" .. string.format("Stop_Profile_Timer:  =  [%.3f] ms", PTimer:time()*0.001) )
--< STOP timer <----------------------------------------------------------------------------

--]=]


--[=[ 	-- Ищем предмет на локации и ставим на его метку. --
function search_item_on_loc()
	local search_item = false
	local obj_ID = 0
	local obj_sec = "НИЧЕГО"
	
	for i=1,65535 do
		local obj = level.object_by_id(i)
		if obj and obj:section() == "puzir_doc" then
			search_item = true
			obj_ID = obj:id()
			obj_sec = obj:section()
		end
	end

	if search_item == true then
		local news_text = "НАЙДЕН Предмет: "..(game.translate_string(ini:r_string(obj_sec, "inv_name")) or obj_sec)
		db.actor:give_game_news(news_text, "ui\\ui_iconsTotal", Frect():set(83,470,83,47), 1, 15000)
		-- Ставим метку на предмет.
		level.map_add_object_spot_ser(obj_ID, "red_location", "%c[255,238,155,23]Здесь находиться: "..(game.translate_string(ini:r_string(obj_sec, "inv_name")) or "<nil>").." ")
		-- Убираем метку.
		-- level.map_remove_object_spot(obj_ID, "red_location")
	else
		local news_text = "Предмет НЕ НАЙДЕН !!!"
		db.actor:give_game_news(news_text, "ui\\ui_iconsTotal", Frect():set(83,470,83,47), 1, 15000)
	end
end
search_item_on_loc()
--]=] ---------------------------------------------------


--[=[	-- Нет-пакет сталкера, на примере Волка. --
{
	[dynamic_out_restrictions] = {}
	[dynamic_in_restrictions] = {}
	[bones_mask] = {	[1] = 255, 
						[2] = 255, 
						[3] = 255, 
						[4] = 255, 
						[5] = 255, 
						[6] = 31, 
						[7] = 0, 
						[8] = 0, 	}
	[job_online] = 2, 
	[bbox_min] = userdata, 
	[game_vertex_id] = 57, 
	[g_team] = 4, 
	[object_flags] = -65, 
	[visual_flags] = 0, 
	[spawn_story_id] = -1, 
	[skeleton_flags] = 4, 
	[money] = 1447, 
	[bones] = {	[1] = {	[ph_rotation] = {[1] = 128, 
                                         [2] = 128, 
                                         [3] = 128, 
                                         [4] = 255, }
						[enabled] = false, 
						[ph_position] = {[1] = 128, 
                                         [2] = 128, 
                                         [3] = 128, }	}	}
	[character_profile] = esc_wolf, 
	[bbox_max] = userdata, 
	[smart_terrain_id] = 6305, 
	[bones_count] = 1, 
	[death_dropped] = 0, 
	[story_id] = 6, 
	[root_bone] = 0, 
	[source_id] = 65535, 
	[skeleton_name] = $editor, 
	[community_index] = 3, 
	[was_in_smart_terrain] = 1, 
	[upd] = {	[prev_game_vertex_id] = 57, 
				[distance_to_point] = 3.636976480484, 
				[distance_from_point] = 3.636976480484, 
				[start_dialog] = escape_lager_volk_talk, 
				[next_game_vertex_id] = 57, 
				[g_team] = 4, 
				[o_torso] = userdata, 
				[g_squad] = 1, 
				[health] = 1, 
				[position] = userdata, 
				[creature_flags] = 0, 
				[timestamp] = 87617, 
				[g_group] = 5, 
				[o_model] = -2.5811643600464, 
			}
	[killer_id] = 65535, 
	[equipment_preferences] = {	[1] = 1, 
								[2] = 0, 
								[3] = 0, 
								[4] = 2, 
								[5] = 0, 
								}
	[direct_control] = 1, 
	[main_weapon_preferences] = {	[1] = 2, 
									[2] = 2, 
									[3] = 1, 
									[4] = 2, 
									}
	[smart_terrain_task_active] = 0, 
	[base_in_restrictors] = , 
	[base_out_restrictors] = , 
	[game_death_time] = {	[1] = 0, 
							[2] = 0, 
							[3] = 0, 
							[4] = 0, 
							[5] = 0, 
							[6] = 0, 
							[7] = 0, 
							[8] = 0, }
	[reputation] = 5, 
	[distance] = 4.9000000953674, 
	[health] = 1, 
	[custom_data] = userdata, 
	[level_vertex_id] = 52330, 
	[visual_name] = actors\neytral\stalker_neytral_balon_1, 
	[trader_flags] = 1, 
	[specific_character] = esc_wolf, 
	[checked_characters] = Волк, 
	[g_squad] = 1, 
	[g_group] = 5, 
	[rank] = 463, 
}
--]=]


--[=[ 	-- Нет-пакет оружия. --

local t = {
   [upd] = {
               [num_items] = 0, 
               [ammo_type] = 1, 	-- Тип патронов. 0 - обычные, 1 - бронебойные. Номера идут, как перечислены в конфиге оружия. 
									-- Если не полностью расстрелять магазин и поменять тип патронов, upd:ammo_type изменится для всего магазина
               [weapon_state] = 0,  -- Самое интересное. Это состояние оружия:
									-- 0 - в руках, idle
									-- 1 - стрельба выстрел пулей/дробью (или удар ножом)
									-- 2 - альтернативный удар (только нож)
									-- 3 - перезарядка
									-- 4 - достается
									-- 5 - убирается (или выбрасывается)
									-- 6 - спрятано
									-- 7 - заклинило
									-- 8 - ??? выстрел из подствольника (в режиме огня "А"-автомат)
									-- 9 - включение/выключение подствольного гранатомета
               [condition] = 0, 
               [weapon_flags] = 1, 	-- 0 - оружие спрятано, 1 - оружие в руках
               [current_fire_mode] = 1, -- Текущий режим огня. Очередность как в конфиге.
               [weapon_zoom] = 0, 	-- Состояние зума оружия: 0 - обычное состояние, 1 - прицел (зажатая правая мышка).
               [ammo_elapsed] = 5, 	-- Остаток патронов в стволе
               [addon_flags] = 0, 	-- Навешанные аддоны. Бинарный флаг по сути, но распишу подробней:
									-- 0 - нету
									-- 1 - прицел
									-- 2 - гранатомет
									-- 3 - прицел+подствольный гранатомет
									-- 4 - глушитель
									-- 5 - прицел + глушитель
									-- 6 - подствольный гранатомет + глушитель
									-- 7 - все сразу
				[grenade_mode] = 0	-- есть только у стволов с возможностью крепления подствольника. Режим подствольника. 0 - выключен, 1 - включен 
			[ammo_ids] = 5			-- есть только у дробовиков и ружей.
									-- После этого параметра должны прописываться типы заряженной дроби в количестве upd:ammo_ids 
									-- можно дробовик зарядить дробью, жеканом и т. п. одновременно.
			},
  [ammo_current] = 90, 
  [story_id] = -1, 
  [condition] = 0, 
  [game_vertex_id] = 4, 
  [object_flags] = -65, 
  [visual_flags] = 0, 
  [spawn_story_id] = -1, 
  [ammo_elapsed] = 5, 
  [weapon_state] = 0, 
   [custom_data] = userdata, 
  [visual_name] = arsenal_mod\wpn_aks74u_sk2, 
  [ammo_type] = 1, 
  [level_vertex_id] = 11713, 
  [direct_control] = 1, 
  [distance] = 0.69999998807907, 
  [addon_flags] = 0, 
}
--]=]


--[=[ 	-- Нет-пакет гранаты. --
local t = {
	[level_vertex_id] = 2803, 
	[spawn_story_id] = -1, 
	[distance] = 0, 
	[condition] = 1, 
	[game_vertex_id] = 717, 
	[visual_name] = wpn_m67_world, 
	[object_flags] = -65, 
	[visual_flags] = 0, 
	[upd] = {
				[num_items] = 0, 
			}
	[story_id] = -1, 
	[custom_data] = userdata, 
	[direct_control] = 1, 
}
--]=]


--[=[ 	-- Расчитаем цены на магазины для текущего оружия. ----> Цена_магазина = (Емкость_маг x Цена_патрона) + ( 10% стоимости_оружия )
----------------------------------------------------
local sect_wpn = "wpn_m1"
----------------------------------------------------
dbg_logf("section:  "..sect_wpn)
local cost_item = mag_base.get_cost_item(sect_wpn) 			-- цена ружа.
dbg_logf("cost_item  =  "..cost_item)
local size_ammo_wpn = mag_base.get_ammo_mag_size(sect_wpn)	-- емкость магазина у этого ружа.
dbg_logf("size_ammo  =  "..size_ammo_wpn)
local tbl_ammo4wpn = mag_base.get_ammo_class(sect_wpn)		-- таблица боеприпасов для данного ружа: [1] = "секция боеприпасов"
----------------------------------------------------
mag_cost = (cost_item/10)	-- цена пустого магазина ЭТО 10% от стоимости оружия.
mag_name = ( "mag_"..tostring(size_ammo_wpn).."_ammo_XXXX_empty")
dbg_logf("--    "..mag_name.."     cost  =  "..mag_cost)
for key,ammo_sec in pairs(tbl_ammo4wpn) do 
	sect_ammo = tostring(ammo_sec)
	cost_ammo = mag_base.get_cost_item(sect_ammo) 			-- цена пачки патронов.
	size_ammo = mag_base.get_box_size(sect_ammo) 			-- размер пачки патронов.
	cost_bullet = cost_ammo/size_ammo 						-- цена одного патрона.
	cost_bullet = math.ceil(cost_bullet) 					-- округляем до целых.
	mag_cost = (size_ammo_wpn*cost_bullet)+(cost_item/10)	-- цена магазина = (емкость маг. х цена 1-го патрона) + ( 10% от стоимости оружия )
	mag_name = ( "mag_"..tostring(size_ammo_wpn).."_"..tostring(sect_ammo) )
	
	dbg_logf("--    "..mag_name.."     cost  =  "..mag_cost)
end
--]=]--------------------------------------------------


--[=[ 	-- Сообщение на экран. --

news_text = "РЕКЛАМНОЕ МЕСТО СВОБОДНО"
db.actor:give_game_news(news_text, "ui\\ui_iconsTotal", Frect():set(83,470,83,47), 1, 15000)

--]=]


--[=[ 	-- Посмотрим что у ГГ в псторе. --
local t = db.storage[db.actor:id()].pstor
print_table_in_log(t)

-- Будет, примерно следующее...
{
  [frn] = false, 
  [x_gtimer_2] = kur, 
  [gt1d] = 6002099, 
  [kur] = 28.799995422363, 
  [x_gtimer_1_delay] = 1931, 
  [dropsect] = non_exist, 
  [x_gtimer_2_params] = , 
  [x_gtimer_2_delay] = 1932, 
  [gt1] = bl1, 
  [dynw] = pasmurno, 
  [changing_level] = 0, 
  [xrs_armor_t] = 2522, 
  [dynlasthour] = -1, 
  [dropid] = -1, 
  [x_gtimer_1_params] = , 
  [gg_need_sleep] = 19, 
  [x_gtimer_1] = gg_need_sleep, 
  [gt1p] = , 
}

--]=]


--[=[ 	-- Общий вес инвентаря ГГ. --
local ves = mag_base.inventory_weight()
log1("Общий вес инвентаря  =  "..tostring(ves))
--]=]


--[=[ 	-- Убиваем всех монстров на локации. --
function kill_all_monsters_in_level()
	for i=1,65535 do
		local obj = level.object_by_id(i)
		if obj and IsMonster(obj) then
			if obj:alive() then
				local h = hit()
				h.direction = vector():set(0,0,0)
				h.impulse = 10
				h.draftsman = obj
				h.power = 1000
				h.type = hit.explosion
				obj:hit(h)
			end
		end
	end
	-- Убиваем и ворон тоже. --
	if ogsm_funcs then
		if type(ogsm_funcs.kill_crow) == 'function' then
			ogsm_funcs.kill_crow()
		end
	end
end
kill_all_monsters_in_level()
--]=]


--[=[ 	-- Убиваем всех сталкеров на локации. --
function kill_all_stalkers_in_level()
	for i=1,65535 do
		local obj = level.object_by_id(i)
		if obj and IsStalker(obj) then
			local otype = get_clsid(obj)
			if otype ~= clsid.actor and otype ~= clsid.script_trader then
				if obj:alive() then
					local h = hit()
					h.direction = vector():set(0,0,0)
					h.impulse = 10
					h.draftsman = obj
					h.power = 1000
					h.type = hit.explosion
					obj:hit(h)
				end
			end
		end
	end
end
kill_all_stalkers_in_level()
--]=]


--[=[ 	-- Какой слот как обозначается? Памятка, чтоб не забыть... --
---------------------------------------------------------------------
-- local active_slot = db.actor:active_slot()
-- active_slot == ...
-- 0 - нож/кулаки
-- 1 - пистолет
-- 2 - автомат
-- 3 - граната
-- 4 - бинокль
-- 5 - болт
-- -----------------------
-- 6 - бронекостюм
-- 7 - пда
-- 8 - детектор
-- 9 - фонарик
-- 10 - актефакт???
#define NO_ACTIVE_SLOT		0xffffffff
#define KNIFE_SLOT			0
#define PISTOL_SLOT			1
#define RIFLE_SLOT			2
#define GRENADE_SLOT		3
#define APPARATUS_SLOT		4
#define BOLT_SLOT			5
#define OUTFIT_SLOT			6
#define PDA_SLOT			7
#define DETECTOR_SLOT		8
#define TORCH_SLOT			9
#define ARTEFACT_SLOT		10
---------------------------------------------------------------------
-- bind == key_bindings.kWPN_...
-- key_bindings.kWPN_1, cmd_name_key = "wpn_1" 		-- Нож/Кулаки
-- key_bindings.kWPN_2, cmd_name_key = "wpn_2"		-- Пистолет
-- key_bindings.kWPN_3, cmd_name_key = "wpn_3"		-- Автомат
-- key_bindings.kWPN_4, cmd_name_key = "wpn_4"		-- Граната
-- key_bindings.kWPN_5, cmd_name_key = "wpn_5"		-- Бинокль
-- key_bindings.kWPN_6, cmd_name_key = "wpn_6"		-- Болт
---------------------------------------------------------------------
--]=]


--[=[ 	-- Перемотка времени. -- Кусок кода из "ogse_sleep_mgr.script" --
local start_sleep_time = game.get_game_time()
local Hours = start_sleep_time:timeToString(game.CTime.TimeToHours or 0)
log1("Hours  =  "..tostring(Hours))

local desired_sleep_time = 3
local sleep_counts = math.ceil(desired_sleep_time * 20)
local dt_ms = math.ceil(desired_sleep_time * 3600 * 1000 / sleep_counts)
for i=1,sleep_counts do
	level.advance_game_time(dt_ms)
end

awakening_time = game.get_game_time()
local real_sleep_time = awakening_time:diffSec(start_sleep_time)
local After_Hours = awakening_time:timeToString(game.CTime.TimeToHours or 0)
log1("After_Hours  =  "..tostring(After_Hours))
--]=]


--[=[ 	-- Голод ГГ. --
local satiety = db.actor.satiety
log1("satiety = "..tostring(satiety))

local str = string.format(" %1.3f",db.actor.satiety)
log1("satiety 2 =  "..math.ceil(tonumber(str)*100).."%")

-- Заметка: сытость гг уменьшается на 0.05 в час. Или на 5% от 100%-ной сытости.
--]=]


--[=[ 	-- ЧИТИНГ -- Режим бога/бесконечных боеприпасов. Добавляем денег. --

-- Добавляем деньги ГГ
-- local money = 1000000
-- db.actor:give_money(money)
-- game_stats.money_quest_update(money)

-- cmd("g_god on")
-- cmd("g_god off")

-- cmd("g_unlimitedammo on")
-- cmd("g_unlimitedammo off")

--]=]


--[=[ 	-- Спавн предметов. -- Взято из AMK mod. --
function spawn_item_in_inv(section,npc)
	local npc = (npc or db.actor)
	local sobj_abstr = alife():create(section,
			npc:position(),
			npc:level_vertex_id(),
			npc:game_vertex_id(),
			npc:id())
	if sobj_abstr then
		dbg_logf("**mag_base  >>>  spawn_item_in_inv  >>>  "..tostring(section)..",  npc:  "..tostring(npc:name()))
		return alife():object(sobj_abstr.id)
	else	
		abort("ERROR  >>>  "..sn.."  >>>  spawn_item_in_inv  >>>  "..tostring(section)..",  npc:  "..tostring(npc:name()))
		return false
	end	
end
spawn_item_in_inv("matras")
--]=]


--[=[ 	-- Хранилище Неписей. ---
function get_storage_npc()
	for id = 1,65535,1 do
		local sobj = alife():object( id )
		if sobj and (IsMonster(sobj) and not sobj:alive()) then
			local storage_npc = db.storage[id]
			if storage_npc then
				dbg_logf(" NOT_npc and storage_npc :  "..tostring(sobj:name()))
				print_table_in_log(storage_npc)
			end
		end
	end
end
get_storage_npc()
--]=]


--[=[	-- Манипуляции с оружием и аддонами для него. --
-- local wpn_in_slot = db.actor:item_in_slot(2)
-- local scope_status = ogse_wpn_utils.get_scope_status(wpn_in_slot)
-- local gl_status = ogse_wpn_utils.get_grenade_launcher_status(wpn_in_slot)
-- local silencer_status = ogse_wpn_utils.get_silencer_status(wpn_in_slot)
-- log1("scope_status  =  "..tostring(scope_status))
-- log1("gl_status  =  "..tostring(gl_status))
-- log1("silencer_status  =  "..tostring(silencer_status))


-- local addon_flags = ogse_wpn_utils.get_addon_flags(wpn_in_slot)
-- local scope_flag = ogse_wpn_utils.get_scope_flag(wpn_in_slot)
-- local grenade_launcher_flag = ogse_wpn_utils.get_grenade_launcher_flag(wpn_in_slot)
-- local silencer_flag = ogse_wpn_utils.get_silencer_flag(wpn_in_slot)
-- local grip_flag = ogse_wpn_utils.get_grip_flag(wpn_in_slot)
-- local magazine_flag = ogse_wpn_utils.get_magazine_flag(wpn_in_slot)
-- local scope_mount_flag = ogse_wpn_utils.get_scope_mount_flag(wpn_in_slot)
-- log1("scope_flag  =  "..tostring(scope_flag))
-- log1("grenade_launcher_flag  =  "..tostring(grenade_launcher_flag))
-- log1("silencer_flag  =  "..tostring(silencer_flag))
-- log1("grip_flag  =  "..tostring(grip_flag))
-- log1("magazine_flag  =  "..tostring(magazine_flag))
-- log1("scope_mount_flag  =  "..tostring(scope_mount_flag))

-- ogse_wpn_utils.add_addon_flags(wpn_in_slot, ogse_wpn_utils.addons_flags.scope)
-- ogse_wpn_utils.add_addon_flags(wpn_in_slot, ogse_wpn_utils.addons_flags.gl)
-- ogse_wpn_utils.add_addon_flags(wpn_in_slot, ogse_wpn_utils.addons_flags.silencer)
--]=]


--[=[ 	--- Command listing: start ---
_preset              (Minimum   ) --- Minimum/Low/Default/High/Extreme
ai_use_torch_dynamic_lights (on        ) --- 'on/off' or '1/0'
beclient             (          ) --- BattlEye Client commands
bemsg                (1         ) --- integer value in range [0,1]
beserver             (          ) --- BattlEye Server commands
bind                 (          ) --- no arguments
bind_console         (          ) --- no arguments
bind_list            (          ) --- no arguments
bind_sec             (          ) --- no arguments
cam_fov              (67.5      ) --- float value in range [55.000,90.000]
cam_inert            (0.        ) --- float value in range [0.000,1.000]
cam_slide_inert      (0.        ) --- float value in range [0.000,1.000]
cdkey                (          ) --- string with up to 64 characters
cfg_load             (          ) --- no arguments
cfg_save             (          ) --- no arguments
chat                 (          ) --- no arguments
check_for_updates    (          ) --- no arguments
cl_cod_pickup_mode   (1         ) --- integer value in range [0,1]
cl_dynamiccrosshair  (off       ) --- 'on/off' or '1/0'
cl_voteno            (          ) --- Vote No
cl_votestart         (          ) --- Starts Voting
cl_voteyes           (          ) --- Vote Yes
clear_log            (          ) --- no arguments
demo_play            (          ) --- no arguments
demo_record          (          ) --- no arguments
disconnect           (          ) --- no arguments
dump_open_files      (          ) --- no arguments
dump_resources       (          ) --- no arguments
flush                (          ) --- no arguments
g_always_run         (on        ) --- 'on/off' or '1/0'
g_ammunition_on_belt (off       ) --- 'on/off' or '1/0'
g_autopickup         (off       ) --- 'on/off' or '1/0'
g_backrun            (off       ) --- 'on/off' or '1/0'
g_corpsenum          (10        ) --- integer value in range [0,100]
g_eventdelay         (0         ) --- integer value in range [0,1000]
g_game_difficulty    (gd_novice ) --- game difficulty
g_god                (off       ) --- 'on/off' or '1/0'
g_kill               (          ) --- player kill
g_restart            (          ) --- restart game
g_restart_fast       (          ) --- restart game fast
g_swapteams          (          ) --- swap teams for artefacthunt game
g_unlimitedammo      (off       ) --- 'on/off' or '1/0'
get_server_address   (          ) --- List Players
help                 (          ) --- no arguments
hud_adjust_mode      (0         ) --- integer value in range [0,5]
hud_adjust_value     (0.        ) --- float value in range [0.000,1.000]
hud_crosshair        (on        ) --- 'on/off' or '1/0'
hud_crosshair_dist   (on        ) --- 'on/off' or '1/0'
hud_fov              (0.45      ) --- float value in range [0.000,1.000]
hud_info             (on        ) --- 'on/off' or '1/0'
hud_weapon           (on        ) --- 'on/off' or '1/0'
list_actions         (          ) --- no arguments
load                 (          ) --- no arguments
load_last_save       (          ) --- no arguments
main_menu            (          ) --- no arguments
mm_mm_net_srv_dedicated (off       ) --- 'on/off' or '1/0'
mm_net_con_publicserver (off       ) --- 'on/off' or '1/0'
mm_net_con_spectator (20        ) --- integer value in range [1,32]
mm_net_con_spectator_on (off       ) --- 'on/off' or '1/0'
mm_net_filter_battleye (on        ) --- 'on/off' or '1/0'
mm_net_filter_empty  (on        ) --- 'on/off' or '1/0'
mm_net_filter_full   (on        ) --- 'on/off' or '1/0'
mm_net_filter_listen (on        ) --- 'on/off' or '1/0'
mm_net_filter_pass   (on        ) --- 'on/off' or '1/0'
mm_net_filter_wo_ff  (on        ) --- 'on/off' or '1/0'
mm_net_filter_wo_pass (on        ) --- 'on/off' or '1/0'
mm_net_player_name   (          ) --- string with up to 64 characters
mm_net_srv_gamemode  (st_deathmatch) --- st_deathmatch/st_team_deathmatch/st_artefacthunt
mm_net_srv_maxplayers (32        ) --- integer value in range [2,32]
mm_net_srv_name      (ADMIN-COMP) --- string with up to 64 characters
mm_net_srv_reinforcement_type (0         ) --- integer value in range [0,2]
mm_net_use_battleye  (off       ) --- 'on/off' or '1/0'
mm_net_weather_rateofchange (1.        ) --- float value in range [0.000,100.000]
mouse_invert         (off       ) --- 'on/off' or '1/0'
mouse_sens           (0.13      ) --- float value in range [0.050,0.600]
mouse_ui_sens        (3.3       ) --- float value in range [1.000,10.000]
mouse_wheel_slot_changing (on        ) --- 'on/off' or '1/0'
name                 (          ) --- player name
net_cl_clearstats    (          ) --- clear client net statistic
net_cl_icurvesize    (0         ) --- integer value in range [0,2000]
net_cl_icurvetype    (0         ) --- integer value in range [0,2]
net_cl_interpolation (0.        ) --- float value in range [-1.000,1.000]
net_cl_log_data      (off       ) --- 'on/off' or '1/0'
net_cl_resync        (          ) --- resyncronize client
net_compressor_enabled (0         ) --- integer value in range [0,1]
net_compressor_gather_stats (0         ) --- integer value in range [0,1]
net_compressor_status (          ) --- valid arguments is [info info_full on off]
net_dbg_dump_export_obj (0         ) --- integer value in range [0,1]
net_dbg_dump_import_obj (0         ) --- integer value in range [0,1]
net_dbg_dump_update_read (0         ) --- integer value in range [0,1]
net_dbg_dump_update_write (0         ) --- integer value in range [0,1]
net_dedicated_sleep  (5         ) --- integer value in range [0,64]
net_sv_clearstats    (          ) --- clear server net statistic
net_sv_gpmode        (0         ) --- integer value in range [0,2]
net_sv_log_data      (off       ) --- 'on/off' or '1/0'
net_sv_pending_lim   (2         ) --- integer value in range [0,10]
net_sv_update_rate   (30        ) --- integer value in range [1,100]
ph_frequency         (100.00000 ) --- no arguments
ph_gravity           (19.62     ) --- float value in range [0.000,100.000]
ph_iterations        (18        ) --- integer value in range [15,50]
ph_timefactor        (1.        ) --- float value in range [0.000,10.000]
quit                 (          ) --- no arguments
r1_dlights           (on        ) --- 'on/off' or '1/0'
r1_dlights_clip      (30.       ) --- float value in range [10.000,150.000]
r1_glows_per_frame   (16        ) --- integer value in range [2,32]
r1_lmodel_lerp       (0.1       ) --- float value in range [0.000,0.333]
r1_pps_u             (0.        ) --- float value in range [-1.000,1.000]
r1_pps_v             (0.        ) --- float value in range [-1.000,1.000]
r1_ssa_lod_a         (64.       ) --- float value in range [16.000,96.000]
r1_ssa_lod_b         (48.       ) --- float value in range [16.000,64.000]
r1_tf_mipbias        (0.        ) --- float value in range [-3.000,3.000]
r2_aa                (off       ) --- 'on/off' or '1/0'
r2_aa_break          (0.800000,0.100000,0.000000) --- vector3 in range [0.000000,0.000000,0.000000]-[1.000000,1.000000,1.000000]
r2_aa_kernel         (0.5       ) --- float value in range [0.300,0.700]
r2_aa_weight         (0.250000,0.250000,0.000000) --- vector3 in range [0.000000,0.000000,0.000000]-[1.000000,1.000000,1.000000]
r2_allow_r1_lights   (off       ) --- 'on/off' or '1/0'
r2_gi                (off       ) --- 'on/off' or '1/0'
r2_gi_clip           (0.001     ) --- float value in range [0.000,0.100]
r2_gi_depth          (1         ) --- integer value in range [1,5]
r2_gi_photons        (16        ) --- integer value in range [8,256]
r2_gi_refl           (0.9       ) --- float value in range [0.001,0.990]
r2_gloss_factor      (1.        ) --- float value in range [0.000,10.000]
r2_ls_bloom_fast     (off       ) --- 'on/off' or '1/0'
r2_ls_bloom_kernel_b (0.7       ) --- float value in range [0.010,1.000]
r2_ls_bloom_kernel_g (3.3       ) --- float value in range [1.000,7.000]
r2_ls_bloom_kernel_scale (1.        ) --- float value in range [0.500,2.000]
r2_ls_bloom_speed    (10.       ) --- float value in range [0.000,100.000]
r2_ls_bloom_threshold (0.3       ) --- float value in range [0.000,1.000]
r2_ls_depth_bias     (-0.0001   ) --- float value in range [-0.500,0.500]
r2_ls_depth_scale    (1.00001   ) --- float value in range [0.500,1.500]
r2_ls_dsm_kernel     (0.7       ) --- float value in range [0.100,3.000]
r2_ls_psm_kernel     (0.7       ) --- float value in range [0.100,3.000]
r2_ls_squality       (0.75      ) --- float value in range [0.500,1.000]
r2_ls_ssm_kernel     (0.7       ) --- float value in range [0.100,3.000]
r2_mblur             (0.5       ) --- float value in range [0.000,1.000]
r2_parallax_h        (0.02      ) --- float value in range [0.000,0.500]
r2_slight_fade       (0.4       ) --- float value in range [0.020,2.000]
r2_soft_particles    (on        ) --- 'on/off' or '1/0'
r2_soft_water        (on        ) --- 'on/off' or '1/0'
r2_ssa_lod_a         (48.       ) --- float value in range [16.000,96.000]
r2_ssa_lod_b         (32.       ) --- float value in range [32.000,64.000]
r2_sun               (off       ) --- 'on/off' or '1/0'
r2_sun_depth_far_bias (0.        ) --- float value in range [-0.500,0.500]
r2_sun_depth_far_scale (1.        ) --- float value in range [0.500,1.500]
r2_sun_depth_near_bias (-0.00004  ) --- float value in range [-0.500,0.500]
r2_sun_depth_near_scale (1.00001   ) --- float value in range [0.500,1.500]
r2_sun_details       (off       ) --- 'on/off' or '1/0'
r2_sun_focus         (off       ) --- 'on/off' or '1/0'
r2_sun_lumscale      (1.        ) --- float value in range [-1.000,3.000]
r2_sun_lumscale_amb  (1.        ) --- float value in range [0.000,3.000]
r2_sun_lumscale_hemi (1.        ) --- float value in range [0.000,3.000]
r2_sun_near          (12.       ) --- float value in range [1.000,150.000]
r2_sun_near_border   (0.66      ) --- float value in range [0.500,1.000]
r2_sun_shafts        (high      ) --- off/low/medium/high
r2_sun_tsm           (off       ) --- 'on/off' or '1/0'
r2_sun_tsm_bias      (-0.05     ) --- float value in range [-0.500,0.500]
r2_sun_tsm_proj      (0.18      ) --- float value in range [0.001,0.800]
r2_tf_mipbias        (0.        ) --- float value in range [-0.500,0.500]
r2_tonemap           (off       ) --- 'on/off' or '1/0'
r2_tonemap_adaptation (5.        ) --- float value in range [0.010,10.000]
r2_tonemap_amount    (0.5       ) --- float value in range [0.000,1.000]
r2_tonemap_lowlum    (0.001     ) --- float value in range [0.000,1.000]
r2_tonemap_middlegray (0.25      ) --- float value in range [0.000,2.000]
r2_wait_sleep        (0         ) --- integer value in range [0,1]
r2_zfill             (off       ) --- 'on/off' or '1/0'
r2_zfill_depth       (0.1       ) --- float value in range [0.001,0.500]
r2em                 (0.        ) --- float value in range [0.000,4.000]
r__bloodmarks        (on        ) --- 'on/off' or '1/0'
r__detail_density    (0.4       ) --- float value in range [0.020,0.600]
r__detail_radius     (49        ) --- integer value in range [49,240]
r__geometry_lod      (0.6       ) --- float value in range [0.100,3.000]
r__supersample       (1         ) --- integer value in range [1,4]
r__tf_aniso          (1         ) --- integer value in range [1,16]
ra                   (          ) --- no arguments
renderer             (renderer_r1) --- renderer_r1/renderer_r2a/renderer_r2
rs_c_brightness      (1.        ) --- float value in range [0.500,1.500]
rs_c_contrast        (1.        ) --- float value in range [0.500,1.500]
rs_c_gamma           (1.        ) --- float value in range [0.500,1.500]
rs_fullscreen        (on        ) --- 'on/off' or '1/0'
rs_refresh_60hz      (off       ) --- 'on/off' or '1/0'
rs_stats             (off       ) --- 'on/off' or '1/0'
rs_v_sync            (off       ) --- 'on/off' or '1/0'
rs_vis_distance      (0.6       ) --- float value in range [0.400,1.500]
save                 (          ) --- no arguments
screenshot           (          ) --- no arguments
snd_acceleration     (on        ) --- 'on/off' or '1/0'
snd_cache_size       (24        ) --- integer value in range [4,32]
snd_efx              (off       ) --- 'on/off' or '1/0'
snd_restart          (          ) --- no arguments
snd_targets          (24        ) --- integer value in range [4,32]
snd_volume_eff       (0.7       ) --- float value in range [0.000,1.000]
snd_volume_music     (0.        ) --- float value in range [0.000,1.000]
start                (          ) --- no arguments
stat_memory          (          ) --- no arguments
sv_addmap            (          ) --- Adds map to map rotation list
sv_anomalies_enabled (0         ) --- integer value in range [0,1]
sv_anomalies_length  (3         ) --- integer value in range [0,180]
sv_artefact_respawn_delta (30        ) --- integer value in range [0,600]
sv_artefact_spawn_force (0         ) --- integer value in range [0,1]
sv_artefact_stay_time (3         ) --- integer value in range [0,180]
sv_artefacts_count   (10        ) --- integer value in range [1,100]
sv_auto_team_balance (0         ) --- integer value in range [0,1]
sv_auto_team_swap    (0         ) --- integer value in range [0,1]
sv_banplayer         (          ) --- Ban Player by Name
sv_banplayer_ip      (          ) --- Ban Player by IP
sv_bearercantsprint  (1         ) --- integer value in range [0,1]
sv_changegametype    (          ) --- Changing Game Type
sv_changelevel       (          ) --- Changing Game Type
sv_changelevelgametype (          ) --- Changing level and game type
sv_client_reconnect_time (0         ) --- integer value in range [0,60]
sv_console_update_rate (1         ) --- integer value in range [1,100]
sv_dedicated_server_update_rate (100       ) --- integer value in range [1,1000]
sv_dmgblockindicator (0         ) --- integer value in range [0,1]
sv_dmgblocktime      (0         ) --- integer value in range [0,600]
sv_dump_online_statistics (          ) --- Shows current server settings
sv_dump_online_statistics_period (0         ) --- integer value in range [0,60]
sv_forcerespawn      (0         ) --- integer value in range [0,3600]
sv_fraglimit         (10        ) --- integer value in range [0,100]
sv_friendly_indicators (0         ) --- integer value in range [0,1]
sv_friendly_names    (0         ) --- integer value in range [0,1]
sv_friendlyfire      (1.        ) --- float value in range [0.000,2.000]
sv_hail_to_winner_time (7         ) --- integer value in range [0,60]
sv_kick              (          ) --- Kick Player by name
sv_listmaps          (          ) --- List maps in map rotation list
sv_listplayers       (          ) --- List Players
sv_listplayers_banned (          ) --- List of Banned Players
sv_max_ping_limit    (2000      ) --- integer value in range [1,2000]
sv_nextanomalyset    (          ) --- Activating pointed Anomaly set
sv_nextmap           (          ) --- Switch to Next Map in map rotation list
sv_no_auth_check     (0         ) --- integer value in range [0,1]
sv_pda_hunt          (0         ) --- integer value in range [0,1]
sv_prevmap           (          ) --- Switch to Previous Map in map rotation list
sv_reinforcement_time (20        ) --- integer value in range [-1,3600]
sv_remove_corpse     (1         ) --- integer value in range [-1,1]
sv_remove_weapon     (1         ) --- integer value in range [-1,1]
sv_return_to_base    (          ) --- no arguments
sv_returnplayers     (1         ) --- integer value in range [0,1]
sv_rpoint_freeze_time (0         ) --- integer value in range [0,60000]
sv_setenvtime        (          ) --- no arguments
sv_setweather        (          ) --- Set new weather
sv_shieldedbases     (1         ) --- integer value in range [0,1]
sv_spectr_firsteye   (0         ) --- integer value in range [0,1]
sv_spectr_freefly    (0         ) --- integer value in range [0,1]
sv_spectr_freelook   (0         ) --- integer value in range [0,1]
sv_spectr_lookat     (0         ) --- integer value in range [0,1]
sv_spectr_teamcamera (0         ) --- integer value in range [0,1]
sv_startteammoney    (          ) --- Set Start Team Money
sv_statistic_collect (0         ) --- integer value in range [0,1]
sv_statistic_save    (          ) --- saving statistic data
sv_status            (          ) --- Shows current server settings
sv_teamkill_limit    (3         ) --- integer value in range [0,100]
sv_teamkill_punish   (1         ) --- integer value in range [0,1]
sv_timelimit         (0         ) --- integer value in range [0,180]
sv_unbanplayer_ip    (          ) --- UnBan Player by IP
sv_vote_enabled      (0         ) --- integer value in range [0,255]
sv_vote_participants (0         ) --- integer value in range [0,1]
sv_vote_quota        (0.51      ) --- float value in range [0.000,1.000]
sv_vote_time         (1.        ) --- float value in range [0.500,10.000]
sv_votestop          (          ) --- Stops Current Voting
sv_warm_up           (0         ) --- integer value in range [0,3600]
texture_lod          (3         ) --- integer value in range [0,4]
unbind               (          ) --- no arguments
unbind_console       (          ) --- no arguments
unbind_sec           (          ) --- no arguments
unbindall            (          ) --- no arguments
vid_mode             (1280x768  ) --- change screen resolution WxH
vid_restart          (          ) --- no arguments
--]=] 	--- Command listing: end ----


--[=[ 	-- Трупы монстров (оригинальной игры). --
NPC:    esc_bd__m_boar_e_0007   ID: 6315    story_ID:  NONE  
NPC:    esc_dog_weak_0002    	ID: 7067    story_ID:  NONE  
NPC:    esc_dog_weak_0006    	ID: 7069    story_ID:  NONE  
NPC:    esc_dog_weak_0007    	ID: 7071    story_ID:  NONE  
NPC:    bar_m_dog_e_0009    	ID: 12328    story_ID:  NONE  
NPC:    bar_m_dog_e_0010    	ID: 12330    story_ID:  NONE  
NPC:    bar_m_dog_e_0011    	ID: 12332    story_ID:  NONE  
NPC:    bar_m_dog_e_0012    	ID: 12334    story_ID:  NONE  
NPC:    bar_m_dog_e_0013    	ID: 12336    story_ID:  NONE  
NPC:    bar_m_dog_e_0014    	ID: 12338    story_ID:  NONE  
NPC:    bar_m_dog_e_0015    	ID: 12339    story_ID:  NONE  
NPC:    bar_m_dog_e_0016    	ID: 12340    story_ID:  NONE  
NPC:    bar_m_dog_e_0017    	ID: 12341    story_ID:  NONE  
NPC:    bar_m_dog_e_0018    	ID: 12342    story_ID:  NONE  
NPC:    bar_m_dog_e_0019    	ID: 12713    story_ID:  NONE  
NPC:    bar_m_dog_e_0020    	ID: 12715    story_ID:  NONE  
NPC:    bar_m_dog_e_0021    	ID: 12717    story_ID:  NONE  
NPC:    rostok_dog_dead_1    	ID: 13394    story_ID:  NONE  
NPC:    rostok_dog_dead_2    	ID: 13396    story_ID:  NONE  
NPC:    rostok_m_tushkano_e_0024 ID: 13410    story_ID:  NONE  
--]=]


--[=[ 	-- Вертолеты (оригинальной игры). --
--heli: helicopter  ID:  6295  	name:  esc_heli  			Story_ID:  14
--heli: helicopter  ID:  8755  	name:  agr_nii_heli  		Story_ID:  none
--heli: helicopter  ID:  9228  	name:  agr_helicopter1  	Story_ID:  none
--heli: helicopter  ID:  9232  	name:  agr_helicopter2  	Story_ID:  393
--heli: helicopter  ID:  9233  	name:  agr_helicopter4  	Story_ID:  none
--heli: helicopter  ID:  9234  	name:  agr_helicopter3  	Story_ID:  none
--heli: helicopter  ID:  10583  name:  val_chase_heli  		Story_ID:  none
--heli: helicopter  ID:  13398  name:  rostok_helicopter  	Story_ID:  none
--heli: helicopter  ID:  16037  name:  yan_helicopter_1  	Story_ID:  none
--heli: helicopter  ID:  16038  name:  yan_helicopter_2  	Story_ID:  none
--heli: helicopter  ID:  17476  name:  rad_helicopter  		Story_ID:  none
--heli: helicopter  ID:  20016  name:  pri_helicopter_24  	Story_ID:  none
--heli: helicopter  ID:  20017  name:  pri_helicopter1  	Story_ID:  800
--heli: helicopter  ID:  20018  name:  pri_helicopter2  	Story_ID:  801
--heli: helicopter  ID:  20019  name:  pri_helicopter4  	Story_ID:  803
--heli: helicopter  ID:  20021  name:  pri_helicopter_21  	Story_ID:  none
--heli: helicopter  ID:  20022  name:  pri_helicopter_22  	Story_ID:  none
--heli: helicopter  ID:  21458  name:  aes_helicopter  		Story_ID:  none
--heli: helicopter  ID:  21459  name:  aes_helicopter_0000  Story_ID:  none
--heli: helicopter  ID:  21460  name:  aes_helicopter_0001  Story_ID:  none
--heli: helicopter  ID:  21461  name:  aes_helicopter_0002  Story_ID:  none
--heli: helicopter  ID:  21617  name:  aes_helicopter_0008  Story_ID:  none
--heli: helicopter  ID:  21767  name:  aes_helicopter_0009  Story_ID:  none
--heli: helicopter  ID:  22034  name:  aes_helicopter_0007  Story_ID:  none
--heli: helicopter  ID:  22075  name:  aes_helicopter_0010  Story_ID:  none
--heli: helicopter  ID:  22464  name:  aes_helicopter_0003  Story_ID:  none
--heli: helicopter  ID:  22465  name:  aes_helicopter_0004  Story_ID:  none
--]=]


--[=[ 	-- m_netpk --
-- local sobj = alife():object(6297) -- Волк --
-- local pk = m_netpk.get(sobj)
-- if pk:isOk() then
	-- local data = pk:get()
	-- local description = pk:dumpDesc()
	-- print_table_in_log(data)	
-- end
--]=]


--[=[ 	-- Узнаем, что у НПС в инвентаре. --
function npc_inventory()
	local sobj = alife():object(6199) -- Здесь Сидор. --
	if sobj then
		log1("npc")
		local npc = level.object_by_id(sobj.id)
		if npc then
			log1("npc 2 ")
			local function __del_item(npc, item)
				local section = item:section()
				log1("section = "..tostring(section))
			end
			npc:iterate_inventory(__del_item, npc)
		end
	else
		log1("NO npc")
	end
end
npc_inventory()
--]=]


--[=[ 	-- Инфо-поршни, чтоб не забыть. --
-- db.actor:give_info_portion("opkon_red_forest") 		-- выдаем.
-- db.actor:disable_info_portion("opkon_red_forest") 	-- отключаем.

-- db.actor:has_info("opkon_red_forest") 				-- проверка: выдан?
-- db.actor:dont_has_info("opkon_red_forest") 			-- проверка: отключен?
--]=]


--[=[ 	-- Координаты, направления (position, direction) камеры и ГГ. --

-- local dev_cam_right 	= device().cam_right 	-- единичный вектор, перпендикулярный направлению камеры и направленный вправо
-- local dev_cam_top 	= device().cam_top 		-- единичный вектор, перпендикулярный направлению камеры и направленный вверх

-->> strafe-->> ЭТО НЕ ТОЧНАЯ ИНФА!!! ------------------------------
-- VTN.X = VT.X * cos( angleZ ) + VT.X * cos( angleY );
-- VTN.Y = VT.Y * sin( angleZ ) + VT.Y * sin( angleX );
-- VTN.Z = VT.Z * cos( angleX ) + VT.Z * sin( angleY );
-- Правда со знаками я не уверен, но если тебе надо только в 2д плоскости, то вот такие формулы работают
-- VTN.X = VT.X * cos( angleZ );
-- VTN.Y = VT.Y * sin( angleZ );
--<< ----------------------------------------------------------------

-- Функция возвратит угол поворота камеры по оси У
function dir_angleY()
  local dir = device().cam_dir
  return -dir:getH()
end
-- В основном нужно прописывать дирекшн по оси Y. 
-- Но аналогично и по другим осям вычисляется. 
-- Для оси Y: направление  на север 	- вторая координата в direction равна 0, 
						-- на юг 		- +3,14 или -3,14 (без разницы), 
						-- на восток 	- -1,57, 
						-- на запад 	- +1,57.
--]=]--


--[=[ 	-- Сколько используется памяти LUA. --
	-- dbg_logf(string.rep("-",95))
	-- dbg_logf("--_test_script_pcall.lua > Memory used by Lua before cleanup:  "..collectgarbage('count').."  Kb. ")
	-- collectgarbage('collect')
	-- collectgarbage('collect')
	-- dbg_logf("--_test_script_pcall.lua >> Memory used by Lua after cleanup:  "..collectgarbage('count').."  Kb. ")
	-- dbg_logf(string.rep("-",95))
--]=]--


--[=[ 	-- Код для распечатки _G --
if zander_utils then 
	zlog = zander_utils.zander_log
else
	zlog = get_console():execute()
end
function PrintG()
	local res, value 
	for k, v in pairs(_G) do
		zlog(tostring(k).." = "..tostring(v))
		if type(v)== "table" then
			zlog("РАСПЕЧАТЫВАЕМ СУБТАБЛИЦУ: "..k)
			for key, val in pairs(_G[k]) do
				res, value = pcall(tostring, val)
				if not res then
					zlog("Ошибка преобразования значения: "..value)
					value="error_value"
				end
				zlog("субтаблица: "..key.. " = " ..value)            
			end
		zlog("КОНЕЦ СУБТАБЛИЦЫ: "..k)
		end
	end 
end
clear_log()
PrintG()
--]=]