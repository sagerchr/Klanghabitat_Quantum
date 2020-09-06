<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="20008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="BootLoader" Type="Folder" URL="../BootLoader">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="diverse" Type="Folder" URL="../diverse">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="TCP_IP" Type="Folder" URL="../TCP_IP">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="UDP" Type="Folder" URL="../UDP">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="Check for Valid String Data.vi" Type="VI" URL="/&lt;vilib&gt;/NIOSC/Check for Valid String Data.vi"/>
				<Item Name="Create Argument.vi" Type="VI" URL="/&lt;vilib&gt;/NIOSC/Create Argument.vi"/>
				<Item Name="Create Message.vi" Type="VI" URL="/&lt;vilib&gt;/NIOSC/Create Message.vi"/>
				<Item Name="Create Message_Single Arg.vi" Type="VI" URL="/&lt;vilib&gt;/NIOSC/Create Message_Single Arg.vi"/>
				<Item Name="Create String Argument.vi" Type="VI" URL="/&lt;vilib&gt;/NIOSC/Create String Argument.vi"/>
				<Item Name="Generate Error.vi" Type="VI" URL="/&lt;vilib&gt;/NIOSC/Generate Error.vi"/>
				<Item Name="Multiple of 32.vi" Type="VI" URL="/&lt;vilib&gt;/NIOSC/Multiple of 32.vi"/>
				<Item Name="Pad String.vi" Type="VI" URL="/&lt;vilib&gt;/NIOSC/Pad String.vi"/>
				<Item Name="Parse Message.vi" Type="VI" URL="/&lt;vilib&gt;/NIOSC/Parse Message.vi"/>
				<Item Name="VISA Configure Serial Port" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port"/>
				<Item Name="VISA Configure Serial Port (Instr).vi" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port (Instr).vi"/>
				<Item Name="VISA Configure Serial Port (Serial Instr).vi" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port (Serial Instr).vi"/>
			</Item>
		</Item>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="Firmware Updater" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{75981232-B0F8-4153-9933-4B4AB86C0348}</Property>
				<Property Name="App_INI_GUID" Type="Str">{3BDA0E3D-D172-42EC-9765-F98D13A63544}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="App_serverType" Type="Int">0</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{32432A09-8877-4A24-9029-C07649D00F9B}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Firmware Updater</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME/Firmware Updater</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{497F449D-62B3-4C2C-A2E1-D5718E140F40}</Property>
				<Property Name="Bld_version.build" Type="Int">1</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="Destination[0].destName" Type="Str">Firmware Updater.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/NI_AB_PROJECTNAME/Firmware Updater/Firmware Updater.exe</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/NI_AB_PROJECTNAME/Firmware Updater/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{03F196F6-5AE7-4A98-AD6C-08EA5618D11F}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/BootLoader/FirmwareUpdate.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Firmware Updater</Property>
				<Property Name="TgtF_internalName" Type="Str">Firmware Updater</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2020 </Property>
				<Property Name="TgtF_productName" Type="Str">Firmware Updater</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{84207026-5FB3-4478-8600-539F08B78132}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Firmware Updater.exe</Property>
				<Property Name="TgtF_versionIndependent" Type="Bool">true</Property>
			</Item>
		</Item>
	</Item>
</Project>
