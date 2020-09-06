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
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
