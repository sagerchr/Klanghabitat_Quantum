<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="19008000">
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
				<Item Name="NI_OSC.lvlib" Type="Library" URL="/&lt;vilib&gt;/NIOSC/NI_OSC.lvlib"/>
			</Item>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
