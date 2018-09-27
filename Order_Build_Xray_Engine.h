	/* -------------------------------------------------- //
	// Порядок сборки движка X-Ray 1.0007rc1 [xp-dev.com] //
	// -------------------------------------------------- //
	//  Удалены: редакторы, xrGameSpy, xrD3D9-null.
	// ----------------------------------------------------------------------------------------------------------------------------- //
	// 	Бибилотеки: 			| Зависимости:
	// ----------------------------------------------------------------------------------------------------------------------------- //
	01. libogg_static 
	02. libtheora_static
	03. libvorbis_static 
	04. libvorbisfile_static 	| libvorbis_static
	05. ode
	// ----------------------------------------------------------------------------------------------------------------------------- //
	06. xrCore
	07. LuaJIT
	08. LuaBind 				| xrCore, LuaJIT.
	09. xrCDB					| xrCore.
	// ----------------------------------------------------------------------------------------------------------------------------- //
	10. xrParticles				| xrCore
	11. xrSound					| xrCore, xrCDB, libogg_static, libvorbis_static, libvorbisfile_static
	12. xrXMLParser				| xrCore.
	13. xrNetServer				| xrCore, xrSound.
	// ----------------------------------------------------------------------------------------------------------------------------- //
	14. XR_3DA					| libtheora_static, LuaBind, xrCDB, xrCore, xrNetServer, xrParticles, xrSound.
	15. xrCPU_Pipe				| LuaBind, XR_3DA, xrCore.
	16. xrRender_R1				| LuaBind, XR_3DA, xrCore, xrCDB, xrCPU_Pipe, xrParticles.
	17. xrRender_R2				| LuaBind, XR_3DA, xrCore, xrCDB, xrCPU_Pipe, xrParticles.
	18. xrGame 					| LuaBind, XR_3DA, xrCDB, xrCore, xrCPU_Pipe, xrParticles, xrNetServer, ode, xrSound, xrXMLParser.
	// ----------------------------------------------------------------------------------------------------------------------------- */


	/* -------------------------------------------------- //
		Для сборки необходимы:
		DirectX SDK (August 2007)
		DirectX SDK (June 	2010)
		Windows SDK 
		Visual Studio 2010 sp1 (Не Express Edition)
	// -------------------------------------------------- */