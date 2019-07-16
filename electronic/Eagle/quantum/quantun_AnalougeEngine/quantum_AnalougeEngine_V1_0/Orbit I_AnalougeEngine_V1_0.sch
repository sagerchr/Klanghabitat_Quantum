<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="8.4.1">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="56" name="wert" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="99" name="SpiceOrder" color="5" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="C_Sager_Bibliothek" urn="urn:adsk.eagle:library:560098">
<packages>
<package name="NEUTRIK_NC3FAH" urn="urn:adsk.eagle:footprint:705651/5" locally_modified="yes" library_version="57" library_locally_modified="yes">
<pad name="2" x="3.81" y="-13.335" drill="1.6" shape="square"/>
<pad name="3" x="0" y="-17.15" drill="1.2" shape="square"/>
<pad name="1" x="-3.81" y="-12.7" drill="1.6" shape="square"/>
<hole x="-3.81" y="-3.81" drill="1.6"/>
<hole x="3.81" y="-8.89" drill="1.6"/>
<wire x1="-12.5" y1="0" x2="12.5" y2="0" width="0.127" layer="21"/>
<wire x1="-12.5" y1="-20.5" x2="12.5" y2="-20.5" width="0.127" layer="21"/>
<wire x1="12.6" y1="-0.1" x2="12.6" y2="-20.6" width="0.127" layer="21"/>
<wire x1="-12.7" y1="0" x2="-12.7" y2="-20.5" width="0.127" layer="21"/>
<text x="-14.351" y="-15.113" size="1.27" layer="21" rot="R270">&gt;name</text>
</package>
<package name="351" urn="urn:adsk.eagle:footprint:823800/1" locally_modified="yes" library_version="57" library_locally_modified="yes">
<description>&lt;b&gt;RELAY&lt;/b&gt;&lt;p&gt;
2 x switch, same as G5 V-2, Omron</description>
<wire x1="-5.08" y1="-5.08" x2="10.16" y2="-5.08" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-5.08" x2="10.16" y2="5.08" width="0.1524" layer="21"/>
<wire x1="10.16" y1="5.08" x2="-5.08" y2="5.08" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="5.08" x2="-5.08" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.27" x2="-3.81" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="1.27" x2="-3.81" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.27" x2="-5.08" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-1.27" x2="-5.08" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.27" x2="-5.08" y2="-5.08" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="3.81" x2="-1.905" y2="3.81" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="3.81" x2="-1.905" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="0.635" x2="-3.175" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="0.635" x2="-3.175" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="-0.635" x2="-0.635" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="0.635" x2="-1.905" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-0.635" x2="-1.905" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-0.635" x2="-1.905" y2="-3.81" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-0.635" x2="-0.635" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-1.905" y1="-3.81" x2="-2.794" y2="-3.81" width="0.1524" layer="21"/>
<wire x1="-3.175" y1="-0.635" x2="-0.635" y2="0.635" width="0.1524" layer="21"/>
<text x="5.461" y="-7.112" size="1.778" layer="25" ratio="10">&gt;NAME</text>
<rectangle x1="-5.08" y1="-1.27" x2="-3.81" y2="1.27" layer="21"/>
<smd name="1" x="-2.623" y="-3.645" dx="1.11" dy="3" layer="1"/>
<smd name="P1" x="2.556" y="-3.645" dx="1.11" dy="3" layer="1"/>
<smd name="Q1" x="5.096" y="-3.645" dx="1.11" dy="3" layer="1"/>
<smd name="S1" x="7.636" y="-3.645" dx="1.11" dy="3" layer="1"/>
<smd name="S2" x="7.636" y="3.645" dx="1.11" dy="3" layer="1"/>
<smd name="Q2" x="5.096" y="3.645" dx="1.11" dy="3" layer="1"/>
<smd name="P2" x="2.556" y="3.645" dx="1.11" dy="3" layer="1"/>
<smd name="2" x="-2.623" y="3.645" dx="1.11" dy="3" layer="1"/>
</package>
<package name="87832-10" urn="urn:adsk.eagle:footprint:568049/6" locally_modified="yes" library_version="57" library_locally_modified="yes">
<description>&lt;b&gt;PCB Headers&lt;/b&gt;&lt;p&gt; 
2.00mm (.079") Pitch Milli-Grid Header, Vertical, Shrouded</description>
<wire x1="10" y1="4.5" x2="10" y2="-4.5" width="0.2032" layer="21"/>
<wire x1="10" y1="-4.5" x2="-10" y2="-4.5" width="0.2032" layer="21"/>
<wire x1="-10" y1="-4.5" x2="-10" y2="4.5" width="0.2032" layer="21"/>
<wire x1="-10" y1="4.5" x2="10" y2="4.5" width="0.2032" layer="21"/>
<wire x1="-8.89" y1="-2.54" x2="-7.62" y2="-2.54" width="0.127" layer="21"/>
<wire x1="-7.62" y1="-2.54" x2="-7.62" y2="-3.81" width="0.127" layer="21"/>
<smd name="1" x="-5.08" y="-3.2512" dx="0.89" dy="4.8" layer="1"/>
<smd name="3" x="-2.54" y="-3.2512" dx="0.89" dy="4.8" layer="1"/>
<smd name="5" x="0" y="-3.2512" dx="0.89" dy="4.8" layer="1"/>
<smd name="7" x="2.54" y="-3.2512" dx="0.89" dy="4.8" layer="1"/>
<smd name="9" x="5.08" y="-3.2512" dx="0.89" dy="4.8" layer="1"/>
<smd name="2" x="-5.08" y="3.2488" dx="0.89" dy="4.8" layer="1"/>
<smd name="4" x="-2.54" y="3.2488" dx="0.89" dy="4.8" layer="1"/>
<smd name="6" x="0" y="3.2488" dx="0.89" dy="4.8" layer="1" rot="R180"/>
<smd name="8" x="2.54" y="3.2488" dx="0.89" dy="4.8" layer="1"/>
<smd name="10" x="5" y="3.2488" dx="0.89" dy="4.8" layer="1"/>
<text x="-10.1821" y="-0.2921" size="1.016" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="-5.0976" y="-2.7246" size="0.6096" layer="51" ratio="10">1</text>
</package>
<package name="C0603" urn="urn:adsk.eagle:footprint:576737/1" library_version="45" library_locally_modified="yes">
<description>&lt;b&gt;CAPACITOR&lt;/b&gt;</description>
<wire x1="-1.473" y1="0.983" x2="1.473" y2="0.983" width="0.0508" layer="39"/>
<wire x1="1.473" y1="0.983" x2="1.473" y2="-0.983" width="0.0508" layer="39"/>
<wire x1="1.473" y1="-0.983" x2="-1.473" y2="-0.983" width="0.0508" layer="39"/>
<wire x1="-1.473" y1="-0.983" x2="-1.473" y2="0.983" width="0.0508" layer="39"/>
<wire x1="-0.356" y1="0.432" x2="0.356" y2="0.432" width="0.1016" layer="51"/>
<wire x1="-0.356" y1="-0.419" x2="0.356" y2="-0.419" width="0.1016" layer="51"/>
<smd name="1" x="-0.85" y="0" dx="1.1" dy="1" layer="1"/>
<smd name="2" x="0.85" y="0" dx="1.1" dy="1" layer="1"/>
<text x="-0.635" y="0.635" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.635" y="-1.905" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-0.8382" y1="-0.4699" x2="-0.3381" y2="0.4801" layer="51"/>
<rectangle x1="0.3302" y1="-0.4699" x2="0.8303" y2="0.4801" layer="51"/>
<rectangle x1="-0.1999" y1="-0.3" x2="0.1999" y2="0.3" layer="35"/>
</package>
<package name="SOD323-R" urn="urn:adsk.eagle:footprint:578209/1" library_version="45" library_locally_modified="yes">
<description>&lt;b&gt;SOD323 Reflow soldering&lt;/b&gt; Philips SC01_Mounting_1996.pdf</description>
<wire x1="-1" y1="0.7" x2="1" y2="0.7" width="0.1524" layer="21"/>
<wire x1="1" y1="0.7" x2="1" y2="-0.7" width="0.1524" layer="51"/>
<wire x1="1" y1="-0.7" x2="-1" y2="-0.7" width="0.1524" layer="21"/>
<wire x1="-1" y1="-0.7" x2="-1" y2="0.7" width="0.1524" layer="51"/>
<wire x1="-0.5" y1="0" x2="0.1" y2="0.4" width="0.1524" layer="21"/>
<wire x1="0.1" y1="0.4" x2="0.1" y2="-0.4" width="0.1524" layer="21"/>
<wire x1="0.1" y1="-0.4" x2="-0.5" y2="0" width="0.1524" layer="21"/>
<smd name="C" x="-1.1" y="0" dx="0.6" dy="0.6" layer="1"/>
<smd name="A" x="1.1" y="0" dx="0.6" dy="0.6" layer="1"/>
<text x="-1.1" y="1" size="1.27" layer="25">&gt;NAME</text>
<text x="-1.1" y="-2.3" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-0.7" y1="-0.7" x2="-0.5" y2="0.7" layer="51"/>
</package>
<package name="SOT23" urn="urn:adsk.eagle:footprint:705531/1" library_version="45" library_locally_modified="yes">
<description>&lt;b&gt;SOT-23&lt;/b&gt;</description>
<wire x1="1.4224" y1="0.6604" x2="1.4224" y2="-0.6604" width="0.1524" layer="51"/>
<wire x1="1.4224" y1="-0.6604" x2="-1.4224" y2="-0.6604" width="0.1524" layer="51"/>
<wire x1="-1.4224" y1="-0.6604" x2="-1.4224" y2="0.6604" width="0.1524" layer="51"/>
<wire x1="-1.4224" y1="0.6604" x2="1.4224" y2="0.6604" width="0.1524" layer="51"/>
<smd name="3" x="0" y="1.1" dx="1" dy="1.4" layer="1"/>
<smd name="2" x="0.95" y="-1.1" dx="1" dy="1.4" layer="1"/>
<smd name="1" x="-0.95" y="-1.1" dx="1" dy="1.4" layer="1"/>
<text x="-1.905" y="1.905" size="1.27" layer="25">&gt;NAME</text>
<text x="-1.905" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-0.2286" y1="0.7112" x2="0.2286" y2="1.2954" layer="51"/>
<rectangle x1="0.7112" y1="-1.2954" x2="1.1684" y2="-0.7112" layer="51"/>
<rectangle x1="-1.1684" y1="-1.2954" x2="-0.7112" y2="-0.7112" layer="51"/>
</package>
<package name="R0805" urn="urn:adsk.eagle:footprint:577961/1" locally_modified="yes" library_version="57" library_locally_modified="yes">
<description>&lt;b&gt;RESISTOR&lt;/b&gt;&lt;p&gt;</description>
<wire x1="-0.41" y1="0.635" x2="0.41" y2="0.635" width="0.1524" layer="51"/>
<wire x1="-0.41" y1="-0.635" x2="0.41" y2="-0.635" width="0.1524" layer="51"/>
<wire x1="-1.973" y1="0.983" x2="1.973" y2="0.983" width="0.0508" layer="39"/>
<wire x1="1.973" y1="0.983" x2="1.973" y2="-0.983" width="0.0508" layer="39"/>
<wire x1="1.973" y1="-0.983" x2="-1.973" y2="-0.983" width="0.0508" layer="39"/>
<wire x1="-1.973" y1="-0.983" x2="-1.973" y2="0.983" width="0.0508" layer="39"/>
<smd name="1" x="-0.95" y="0" dx="1.3" dy="1.5" layer="1"/>
<smd name="2" x="0.95" y="0" dx="1.3" dy="1.5" layer="1"/>
<text x="-1.905" y="0.635" size="1.27" layer="25">&gt;NAME</text>
<text x="-1.778" y="-2.413" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="0.4064" y1="-0.6985" x2="1.0564" y2="0.7015" layer="51"/>
<rectangle x1="-1.0668" y1="-0.6985" x2="-0.4168" y2="0.7015" layer="51"/>
<rectangle x1="-0.1999" y1="-0.5001" x2="0.1999" y2="0.5001" layer="35"/>
</package>
<package name="RTRIM4G/J" urn="urn:adsk.eagle:footprint:708081/1" library_version="46" library_locally_modified="yes">
<description>&lt;b&gt;Trimm resistor&lt;/b&gt; VISHAY</description>
<wire x1="-2.4" y1="2.4" x2="-2.4" y2="-2.4" width="0.254" layer="51"/>
<wire x1="-2.4" y1="-2.4" x2="2.4" y2="-2.4" width="0.254" layer="51"/>
<wire x1="2.4" y1="-2.4" x2="2.4" y2="2.4" width="0.254" layer="51"/>
<wire x1="2.4" y1="2.4" x2="-2.4" y2="2.4" width="0.254" layer="51"/>
<wire x1="-2.1" y1="-2.4" x2="-2.4" y2="-2.4" width="0.254" layer="21"/>
<wire x1="-2.4" y1="-2.4" x2="-2.4" y2="2.4" width="0.254" layer="21"/>
<wire x1="-2.4" y1="2.4" x2="-1.25" y2="2.4" width="0.254" layer="21"/>
<wire x1="2" y1="-2.4" x2="2.4" y2="-2.4" width="0.254" layer="21"/>
<wire x1="2.4" y1="-2.4" x2="2.4" y2="2.4" width="0.254" layer="21"/>
<wire x1="2.4" y1="2.4" x2="1.25" y2="2.4" width="0.254" layer="21"/>
<wire x1="-0.25" y1="-2.4" x2="0.25" y2="-2.4" width="0.254" layer="21"/>
<circle x="0" y="0" radius="1.85" width="0.1016" layer="21"/>
<smd name="3" x="-1.15" y="-2" dx="1.3" dy="1.3" layer="1"/>
<smd name="1" x="1.15" y="-2" dx="1.3" dy="1.3" layer="1"/>
<smd name="2" x="0" y="2" dx="2" dy="1.3" layer="1"/>
<text x="-2.875" y="-2.54" size="1.27" layer="25" rot="R90">&gt;NAME</text>
<text x="4.045" y="-2.54" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-1.3" y1="-0.2" x2="1.35" y2="0.2" layer="21"/>
<rectangle x1="-0.2" y1="-1.35" x2="0.2" y2="1.3" layer="21"/>
</package>
<package name="153CLV-0605" urn="urn:adsk.eagle:footprint:577969/1" library_version="45" library_locally_modified="yes">
<description>&lt;b&gt;Aluminum electrolytic capacitors&lt;/b&gt;&lt;p&gt;
SMD (Chip) Long Life Vertical 153 CLV&lt;p&gt;
http://www.bccomponents.com/</description>
<wire x1="2.4" y1="-3.3" x2="-3.3" y2="-3.3" width="0.2032" layer="21"/>
<wire x1="-3.3" y1="-3.3" x2="-3.3" y2="-1.1" width="0.2032" layer="21"/>
<wire x1="-3.3" y1="-1.1" x2="-3.3" y2="1.1" width="0.2032" layer="51"/>
<wire x1="-3.3" y1="1.1" x2="-3.3" y2="3.3" width="0.2032" layer="21"/>
<wire x1="-3.3" y1="3.3" x2="2.4" y2="3.3" width="0.2032" layer="21"/>
<wire x1="3.3" y1="2.4" x2="3.3" y2="1.1" width="0.2032" layer="21"/>
<wire x1="3.3" y1="1.1" x2="3.3" y2="-1.1" width="0.2032" layer="51"/>
<wire x1="3.3" y1="-1.1" x2="3.3" y2="-2.4" width="0.2032" layer="21"/>
<wire x1="3.3" y1="-2.4" x2="2.4" y2="-3.3" width="0.2032" layer="21"/>
<wire x1="2.4" y1="3.3" x2="3.3" y2="2.4" width="0.2032" layer="21"/>
<wire x1="-2.95" y1="-0.9" x2="2.95" y2="-0.95" width="0.2032" layer="21" curve="145.181395"/>
<wire x1="-2.95" y1="-0.9" x2="-2.95" y2="0.95" width="0.2032" layer="51" curve="-34.818605"/>
<wire x1="-2.95" y1="0.95" x2="2.95" y2="0.9" width="0.2032" layer="21" curve="-145.181395"/>
<wire x1="2.95" y1="-0.95" x2="2.95" y2="0.9" width="0.2032" layer="51" curve="34.818605"/>
<smd name="+" x="2.7" y="0" dx="3.5" dy="1.6" layer="1"/>
<smd name="-" x="-2.7" y="0" dx="3.5" dy="1.6" layer="1"/>
<text x="-3.39" y="3.63" size="1.27" layer="25">&gt;NAME</text>
<text x="-3.425" y="-4.885" size="1.27" layer="27">&gt;VALUE</text>
</package>
<package name="DIL08" urn="urn:adsk.eagle:footprint:705544/1" library_version="45" library_locally_modified="yes">
<description>&lt;b&gt;Dual In Line Package&lt;/b&gt;</description>
<wire x1="5.08" y1="2.921" x2="-5.08" y2="2.921" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-2.921" x2="5.08" y2="-2.921" width="0.1524" layer="21"/>
<wire x1="5.08" y1="2.921" x2="5.08" y2="-2.921" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="2.921" x2="-5.08" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-2.921" x2="-5.08" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.016" x2="-5.08" y2="-1.016" width="0.1524" layer="21" curve="-180"/>
<pad name="1" x="-3.81" y="-3.81" drill="0.8128" diameter="1.27" rot="R90"/>
<pad name="2" x="-1.27" y="-3.81" drill="0.8128" diameter="1.27" rot="R90"/>
<pad name="7" x="-1.27" y="3.81" drill="0.8128" diameter="1.27" rot="R90"/>
<pad name="8" x="-3.81" y="3.81" drill="0.8128" diameter="1.27" rot="R90"/>
<pad name="3" x="1.27" y="-3.81" drill="0.8128" diameter="1.27" rot="R90"/>
<pad name="4" x="3.81" y="-3.81" drill="0.8128" diameter="1.27" rot="R90"/>
<pad name="6" x="1.27" y="3.81" drill="0.8128" diameter="1.27" rot="R90"/>
<pad name="5" x="3.81" y="3.81" drill="0.8128" diameter="1.27" rot="R90"/>
<text x="-5.334" y="-2.921" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="-3.556" y="-0.635" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="SOIC8" urn="urn:adsk.eagle:footprint:705545/1" locally_modified="yes" library_version="57" library_locally_modified="yes">
<description>&lt;b&gt;SOIC-8&lt;/b&gt; CASE 751-07&lt;p&gt;
Source: http://www.onsemi.com/pub/Collateral/MC34164-D.PDF&lt;p&gt;
&lt;b&gt;D (R-PDSO-G8)&lt;/b&gt;PLATIC SMALL-OUTLINE PACKAGE&lt;br&gt;
Source: http://focus.ti.com/lit/ds/symlink/tlc27l2.pdf</description>
<wire x1="2.4" y1="1.9" x2="2.4" y2="-1.4" width="0.2032" layer="21"/>
<wire x1="2.4" y1="-1.4" x2="2.4" y2="-1.9" width="0.2032" layer="21"/>
<wire x1="2.4" y1="-1.9" x2="-2.4" y2="-1.9" width="0.2032" layer="51"/>
<wire x1="-2.4" y1="-1.9" x2="-2.4" y2="-1.4" width="0.2032" layer="21"/>
<wire x1="-2.4" y1="-1.4" x2="-2.4" y2="1.9" width="0.2032" layer="21"/>
<wire x1="-2.4" y1="1.9" x2="2.4" y2="1.9" width="0.2032" layer="51"/>
<wire x1="2.4" y1="-1.4" x2="-2.4" y2="-1.4" width="0.2032" layer="21"/>
<smd name="2" x="-0.635" y="-2.75" dx="0.6" dy="1.5" layer="1"/>
<smd name="7" x="-0.635" y="2.75" dx="0.6" dy="1.5" layer="1"/>
<smd name="1" x="-1.905" y="-2.75" dx="0.6" dy="1.5" layer="1"/>
<smd name="3" x="0.635" y="-2.75" dx="0.6" dy="1.5" layer="1"/>
<smd name="4" x="1.905" y="-2.75" dx="0.6" dy="1.5" layer="1"/>
<smd name="8" x="-1.905" y="2.75" dx="0.6" dy="1.5" layer="1"/>
<smd name="6" x="0.635" y="2.75" dx="0.6" dy="1.5" layer="1"/>
<smd name="5" x="1.905" y="2.75" dx="0.6" dy="1.5" layer="1"/>
<text x="-2.667" y="-1.905" size="1.27" layer="25" rot="R90">&gt;NAME</text>
<text x="3.937" y="-1.905" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-2.15" y1="-3.1" x2="-1.66" y2="-2" layer="51"/>
<rectangle x1="-0.88" y1="-3.1" x2="-0.39" y2="-2" layer="51"/>
<rectangle x1="0.39" y1="-3.1" x2="0.88" y2="-2" layer="51"/>
<rectangle x1="1.66" y1="-3.1" x2="2.15" y2="-2" layer="51"/>
<rectangle x1="1.66" y1="2" x2="2.15" y2="3.1" layer="51"/>
<rectangle x1="0.39" y1="2" x2="0.88" y2="3.1" layer="51"/>
<rectangle x1="-0.88" y1="2" x2="-0.39" y2="3.1" layer="51"/>
<rectangle x1="-2.15" y1="2" x2="-1.66" y2="3.1" layer="51"/>
<circle x="-1.778" y="-1.016" radius="0.254" width="0.127" layer="21"/>
</package>
<package name="TO252" urn="urn:adsk.eagle:footprint:763978/1" locally_modified="yes" library_version="57" library_locally_modified="yes">
<description>&lt;b&gt;SMALL OUTLINE TRANSISTOR&lt;/b&gt;&lt;p&gt;
TS-003</description>
<wire x1="3.2766" y1="3.8354" x2="3.277" y2="-2.159" width="0.2032" layer="21"/>
<wire x1="3.277" y1="-2.159" x2="-3.277" y2="-2.159" width="0.2032" layer="21"/>
<wire x1="-3.277" y1="-2.159" x2="-3.2766" y2="3.8354" width="0.2032" layer="21"/>
<wire x1="-3.277" y1="3.835" x2="3.2774" y2="3.8346" width="0.2032" layer="51"/>
<wire x1="-2.5654" y1="3.937" x2="-2.5654" y2="4.6482" width="0.2032" layer="51"/>
<wire x1="-2.5654" y1="4.6482" x2="-2.1082" y2="5.1054" width="0.2032" layer="51"/>
<wire x1="-2.1082" y1="5.1054" x2="2.1082" y2="5.1054" width="0.2032" layer="51"/>
<wire x1="2.1082" y1="5.1054" x2="2.5654" y2="4.6482" width="0.2032" layer="51"/>
<wire x1="2.5654" y1="4.6482" x2="2.5654" y2="3.937" width="0.2032" layer="51"/>
<wire x1="2.5654" y1="3.937" x2="-2.5654" y2="3.937" width="0.2032" layer="51"/>
<smd name="2" x="0" y="2.5" dx="5.4" dy="6.2" layer="1"/>
<smd name="1" x="-2.28" y="-4.8" dx="1" dy="1.6" layer="1"/>
<smd name="3" x="2.28" y="-4.8" dx="1" dy="1.6" layer="1"/>
<text x="-3.683" y="-0.635" size="1.27" layer="25" rot="R90">&gt;NAME</text>
<text x="1.905" y="6.985" size="1.27" layer="27" rot="R180">&gt;VALUE</text>
<rectangle x1="-2.7178" y1="-5.1562" x2="-1.8542" y2="-2.2606" layer="51"/>
<rectangle x1="1.8542" y1="-5.1562" x2="2.7178" y2="-2.2606" layer="51"/>
<rectangle x1="-0.4318" y1="-3.0226" x2="0.4318" y2="-2.2606" layer="21"/>
<polygon width="0.1998" layer="51">
<vertex x="-2.5654" y="3.937"/>
<vertex x="-2.5654" y="4.6482"/>
<vertex x="-2.1082" y="5.1054"/>
<vertex x="2.1082" y="5.1054"/>
<vertex x="2.5654" y="4.6482"/>
<vertex x="2.5654" y="3.937"/>
</polygon>
</package>
<package name="SOIC16" urn="urn:adsk.eagle:footprint:763980/1" locally_modified="yes" library_version="57" library_locally_modified="yes">
<description>&lt;b&gt;TOSHIBA PHOTOCOUPLER GaAs IRED &amp; PHOTO-TRANSISTOR&lt;/b&gt; 11-10F1&lt;/b&gt;&lt;p&gt;
Source: http://www.semicon.toshiba.co.jp/td/en/Opto/Photocoupler/en_20050928_TLP283_datasheet.pdf</description>
<wire x1="-2.0849" y1="-4.9784" x2="2.0849" y2="-4.9784" width="0.2032" layer="21"/>
<wire x1="2.0849" y1="-4.9784" x2="2.0849" y2="4.9784" width="0.2032" layer="21"/>
<wire x1="2.0849" y1="4.9784" x2="-2.0849" y2="4.9784" width="0.2032" layer="21"/>
<wire x1="-2.0849" y1="4.9784" x2="-2.0849" y2="-4.9784" width="0.2032" layer="21"/>
<circle x="-1.285" y="4.164" radius="0.3349" width="0.1016" layer="21"/>
<smd name="1" x="-3.24" y="4.445" dx="1" dy="0.5" layer="1"/>
<smd name="2" x="-3.24" y="3.175" dx="1" dy="0.5" layer="1"/>
<smd name="3" x="-3.24" y="1.905" dx="1" dy="0.5" layer="1"/>
<smd name="4" x="-3.24" y="0.635" dx="1" dy="0.5" layer="1"/>
<smd name="5" x="-3.24" y="-0.635" dx="1" dy="0.5" layer="1" rot="R180"/>
<smd name="6" x="-3.24" y="-1.905" dx="1" dy="0.5" layer="1" rot="R180"/>
<smd name="7" x="-3.24" y="-3.175" dx="1" dy="0.5" layer="1" rot="R180"/>
<smd name="8" x="-3.24" y="-4.445" dx="1" dy="0.5" layer="1" rot="R180"/>
<smd name="9" x="3.24" y="-4.445" dx="1" dy="0.5" layer="1" rot="R180"/>
<smd name="10" x="3.24" y="-3.175" dx="1" dy="0.5" layer="1" rot="R180"/>
<smd name="11" x="3.24" y="-1.905" dx="1" dy="0.5" layer="1" rot="R180"/>
<smd name="12" x="3.24" y="-0.635" dx="1" dy="0.5" layer="1" rot="R180"/>
<smd name="13" x="3.24" y="0.635" dx="1" dy="0.5" layer="1"/>
<smd name="14" x="3.24" y="1.905" dx="1" dy="0.5" layer="1"/>
<smd name="15" x="3.24" y="3.175" dx="1" dy="0.5" layer="1"/>
<smd name="16" x="3.24" y="4.445" dx="1" dy="0.5" layer="1"/>
<text x="-1.905" y="5.715" size="1.27" layer="25">&gt;NAME</text>
<rectangle x1="-3.471" y1="4.2545" x2="-2.15" y2="4.6355" layer="51"/>
<rectangle x1="-3.471" y1="2.9845" x2="-2.15" y2="3.3655" layer="51"/>
<rectangle x1="-3.471" y1="1.7145" x2="-2.15" y2="2.0955" layer="51"/>
<rectangle x1="-3.471" y1="0.4445" x2="-2.15" y2="0.8255" layer="51"/>
<rectangle x1="-3.471" y1="-0.8255" x2="-2.15" y2="-0.4445" layer="51" rot="R180"/>
<rectangle x1="-3.471" y1="-2.0955" x2="-2.15" y2="-1.7145" layer="51" rot="R180"/>
<rectangle x1="-3.471" y1="-3.3655" x2="-2.15" y2="-2.9845" layer="51" rot="R180"/>
<rectangle x1="-3.471" y1="-4.6355" x2="-2.15" y2="-4.2545" layer="51" rot="R180"/>
<rectangle x1="2.15" y1="-4.6355" x2="3.471" y2="-4.2545" layer="51" rot="R180"/>
<rectangle x1="2.15" y1="-3.3655" x2="3.471" y2="-2.9845" layer="51" rot="R180"/>
<rectangle x1="2.15" y1="-2.0955" x2="3.471" y2="-1.7145" layer="51" rot="R180"/>
<rectangle x1="2.15" y1="-0.8255" x2="3.471" y2="-0.4445" layer="51" rot="R180"/>
<rectangle x1="2.15" y1="0.4445" x2="3.471" y2="0.8255" layer="51"/>
<rectangle x1="2.15" y1="1.7145" x2="3.471" y2="2.0955" layer="51"/>
<rectangle x1="2.15" y1="2.9845" x2="3.471" y2="3.3655" layer="51"/>
<rectangle x1="2.15" y1="4.2545" x2="3.471" y2="4.6355" layer="51"/>
</package>
<package name="THT_PIN" urn="urn:adsk.eagle:footprint:817865/1" locally_modified="yes" library_version="57" library_locally_modified="yes">
<pad name="P$1" x="0" y="0" drill="1" shape="long"/>
<text x="1.651" y="-0.762" size="1.27" layer="25">&gt;name</text>
</package>
<package name="TP" urn="urn:adsk.eagle:footprint:817536/1" library_version="51" library_locally_modified="yes">
<smd name="P$1" x="0" y="0" dx="1.27" dy="1.27" layer="1" roundness="100"/>
<text x="-2.54" y="1.27" size="1.27" layer="25">&gt;name</text>
</package>
<package name="NEUTRIK_NC3MAH" urn="urn:adsk.eagle:footprint:705584/3" locally_modified="yes" library_version="57" library_locally_modified="yes">
<pad name="G" x="0" y="-12.7" drill="1.2"/>
<pad name="2" x="-3.81" y="-17.78" drill="1.6" shape="square"/>
<pad name="3" x="0" y="-17.78" drill="1.2" shape="square"/>
<pad name="1" x="3.81" y="-17.78" drill="1.6" shape="square"/>
<hole x="-3.81" y="-3.8" drill="1.6"/>
<hole x="3.81" y="-8.89" drill="1.6"/>
<wire x1="-12.5" y1="0" x2="12.5" y2="0" width="0.127" layer="21"/>
<wire x1="-12.5" y1="-20.5" x2="12.5" y2="-20.5" width="0.127" layer="21"/>
<wire x1="12.6" y1="-0.1" x2="12.6" y2="-20.6" width="0.127" layer="21"/>
<wire x1="-12.7" y1="0" x2="-12.7" y2="-20.5" width="0.127" layer="21"/>
<text x="14.478" y="-20.32" size="1.27" layer="21" rot="R90">&gt;name</text>
</package>
</packages>
<packages3d>
<package3d name="NEUTRIK_NC3FAH" urn="urn:adsk.eagle:package:705652/7" type="model" library_version="57" library_locally_modified="yes">
</package3d>
<package3d name="351" urn="urn:adsk.eagle:package:823802/2" type="model" library_version="57" library_locally_modified="yes">
<description>RELAY
2 x switch, same as G5 V-2, Omron</description>
</package3d>
<package3d name="87832-10" urn="urn:adsk.eagle:package:568050/8" type="model" library_version="45" library_locally_modified="yes">
<description>PCB Headers 
2.00mm (.079") Pitch Milli-Grid Header, Vertical, Shrouded</description>
</package3d>
<package3d name="C0603" urn="urn:adsk.eagle:package:576738/2" type="model" library_version="45" library_locally_modified="yes">
<description>CAPACITOR</description>
</package3d>
<package3d name="SOD323-R" urn="urn:adsk.eagle:package:578210/2" type="model" library_version="45" library_locally_modified="yes">
<description>SOD323 Reflow soldering Philips SC01_Mounting_1996.pdf</description>
</package3d>
<package3d name="SOT23" urn="urn:adsk.eagle:package:705533/2" type="model" library_version="45" library_locally_modified="yes">
<description>SOT-23</description>
</package3d>
<package3d name="R0805" urn="urn:adsk.eagle:package:577963/2" type="model" library_version="45" library_locally_modified="yes">
<description>RESISTOR</description>
</package3d>
<package3d name="153CLV-0605" urn="urn:adsk.eagle:package:577970/2" type="model" library_version="45" library_locally_modified="yes">
<description>Aluminum electrolytic capacitors
SMD (Chip) Long Life Vertical 153 CLV
http://www.bccomponents.com/</description>
</package3d>
<package3d name="DIL08" urn="urn:adsk.eagle:package:705547/2" type="model" library_version="45" library_locally_modified="yes">
<description>Dual In Line Package</description>
</package3d>
<package3d name="SOIC8" urn="urn:adsk.eagle:package:705548/2" type="model" library_version="45" library_locally_modified="yes">
<description>SOIC-8 CASE 751-07
Source: http://www.onsemi.com/pub/Collateral/MC34164-D.PDF
D (R-PDSO-G8)PLATIC SMALL-OUTLINE PACKAGE
Source: http://focus.ti.com/lit/ds/symlink/tlc27l2.pdf</description>
</package3d>
<package3d name="RTRIM4G/J" urn="urn:adsk.eagle:package:708082/2" type="model" library_version="57" library_locally_modified="yes">
<description>Trimm resistor VISHAY</description>
</package3d>
<package3d name="TO252" urn="urn:adsk.eagle:package:763981/2" type="model" library_version="49" library_locally_modified="yes">
<description>SMALL OUTLINE TRANSISTOR
TS-003</description>
</package3d>
<package3d name="SOIC16" urn="urn:adsk.eagle:package:763982/2" type="model" library_version="49" library_locally_modified="yes">
<description>TOSHIBA PHOTOCOUPLER GaAs IRED &amp; PHOTO-TRANSISTOR 11-10F1
Source: http://www.semicon.toshiba.co.jp/td/en/Opto/Photocoupler/en_20050928_TLP283_datasheet.pdf</description>
</package3d>
<package3d name="THT_PIN" urn="urn:adsk.eagle:package:817866/2" type="model" library_version="57" library_locally_modified="yes">
</package3d>
<package3d name="TP" urn="urn:adsk.eagle:package:817537/2" type="model" library_version="57" library_locally_modified="yes">
</package3d>
<package3d name="NEUTRIK_NC3MAH" urn="urn:adsk.eagle:package:705585/4" type="model" library_version="57" library_locally_modified="yes">
</package3d>
</packages3d>
<symbols>
<symbol name="NEUTRIK_NC3FAH" urn="urn:adsk.eagle:symbol:705650/3" library_version="49" library_locally_modified="yes">
<pin name="1" x="-7.62" y="-2.54" length="middle" rot="R90"/>
<pin name="2" x="-5.08" y="-2.54" length="middle" rot="R90"/>
<pin name="3" x="-2.54" y="-2.54" length="middle" rot="R90"/>
<wire x1="-10.16" y1="7.62" x2="-10.16" y2="0" width="0.254" layer="94"/>
<wire x1="-10.16" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="7.62" width="0.254" layer="94"/>
<wire x1="0" y1="7.62" x2="-10.16" y2="7.62" width="0.254" layer="94"/>
<text x="-7.62" y="7.62" size="1.778" layer="94">&gt;name</text>
</symbol>
<symbol name="K" urn="urn:adsk.eagle:symbol:823798/1" library_version="57" library_locally_modified="yes">
<wire x1="-3.81" y1="-1.905" x2="-1.905" y2="-1.905" width="0.254" layer="94"/>
<wire x1="3.81" y1="-1.905" x2="3.81" y2="1.905" width="0.254" layer="94"/>
<wire x1="3.81" y1="1.905" x2="1.905" y2="1.905" width="0.254" layer="94"/>
<wire x1="-3.81" y1="1.905" x2="-3.81" y2="-1.905" width="0.254" layer="94"/>
<wire x1="0" y1="-2.54" x2="0" y2="-1.905" width="0.1524" layer="94"/>
<wire x1="0" y1="-1.905" x2="3.81" y2="-1.905" width="0.254" layer="94"/>
<wire x1="0" y1="2.54" x2="0" y2="1.905" width="0.1524" layer="94"/>
<wire x1="0" y1="1.905" x2="-3.81" y2="1.905" width="0.254" layer="94"/>
<wire x1="-1.905" y1="-1.905" x2="1.905" y2="1.905" width="0.1524" layer="94"/>
<wire x1="-1.905" y1="-1.905" x2="0" y2="-1.905" width="0.254" layer="94"/>
<wire x1="1.905" y1="1.905" x2="0" y2="1.905" width="0.254" layer="94"/>
<text x="1.27" y="2.921" size="1.778" layer="96">&gt;VALUE</text>
<text x="1.27" y="5.08" size="1.778" layer="95">&gt;PART</text>
<pin name="2" x="0" y="-5.08" visible="pad" length="short" direction="pas" rot="R90"/>
<pin name="1" x="0" y="5.08" visible="pad" length="short" direction="pas" rot="R270"/>
</symbol>
<symbol name="U" urn="urn:adsk.eagle:symbol:823799/1" library_version="57" library_locally_modified="yes">
<wire x1="3.175" y1="5.08" x2="1.905" y2="5.08" width="0.254" layer="94"/>
<wire x1="-3.175" y1="5.08" x2="-1.905" y2="5.08" width="0.254" layer="94"/>
<wire x1="0" y1="1.27" x2="2.54" y2="5.715" width="0.254" layer="94"/>
<wire x1="0" y1="1.27" x2="0" y2="0" width="0.254" layer="94"/>
<circle x="0" y="1.27" radius="0.127" width="0.4064" layer="94"/>
<text x="2.54" y="0" size="1.778" layer="95">&gt;PART</text>
<pin name="O" x="5.08" y="5.08" visible="pad" length="short" direction="pas" rot="R180"/>
<pin name="S" x="-5.08" y="5.08" visible="pad" length="short" direction="pas"/>
<pin name="P" x="0" y="-2.54" visible="pad" length="short" direction="pas" rot="R90"/>
</symbol>
<symbol name="10PIN_HEADER" urn="urn:adsk.eagle:symbol:568048/3" library_version="49" library_locally_modified="yes">
<wire x1="-25.4" y1="25.4" x2="-25.4" y2="0" width="0.254" layer="94"/>
<wire x1="-25.4" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="25.4" width="0.254" layer="94"/>
<wire x1="0" y1="25.4" x2="-25.4" y2="25.4" width="0.254" layer="94"/>
<pin name="P$1" x="-22.86" y="0" length="middle" rot="R90"/>
<pin name="P$2" x="-22.86" y="25.4" length="middle" rot="R270"/>
<pin name="P$3" x="-17.78" y="0" length="middle" rot="R90"/>
<pin name="P$4" x="-17.78" y="25.4" length="middle" rot="R270"/>
<pin name="P$5" x="-12.7" y="0" length="middle" rot="R90"/>
<pin name="P$6" x="-12.7" y="25.4" length="middle" rot="R270"/>
<pin name="P$7" x="-7.62" y="0" length="middle" rot="R90"/>
<pin name="P$8" x="-7.62" y="25.4" length="middle" rot="R270"/>
<pin name="P$9" x="-2.54" y="0" length="middle" rot="R90"/>
<pin name="P$10" x="-2.54" y="25.4" length="middle" rot="R270"/>
<text x="-27.94" y="10.16" size="1.778" layer="94" rot="R90">&gt;name</text>
</symbol>
<symbol name="C-EU" urn="urn:adsk.eagle:symbol:576736/1" library_version="45" library_locally_modified="yes">
<wire x1="0" y1="0" x2="0" y2="-0.508" width="0.1524" layer="94"/>
<wire x1="0" y1="-2.54" x2="0" y2="-2.032" width="0.1524" layer="94"/>
<text x="1.524" y="0.381" size="1.778" layer="95">&gt;NAME</text>
<text x="1.524" y="-4.699" size="1.778" layer="96">&gt;VALUE</text>
<rectangle x1="-2.032" y1="-2.032" x2="2.032" y2="-1.524" layer="94"/>
<rectangle x1="-2.032" y1="-1.016" x2="2.032" y2="-0.508" layer="94"/>
<pin name="1" x="0" y="2.54" visible="off" length="short" direction="pas" swaplevel="1" rot="R270"/>
<pin name="2" x="0" y="-5.08" visible="off" length="short" direction="pas" swaplevel="1" rot="R90"/>
</symbol>
<symbol name="DIODE" urn="urn:adsk.eagle:symbol:578208/1" library_version="45" library_locally_modified="yes">
<wire x1="-1.27" y1="-1.905" x2="1.27" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="-1.27" y2="1.905" width="0.254" layer="94"/>
<wire x1="-1.27" y1="1.905" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<wire x1="1.397" y1="1.905" x2="1.397" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.3114" y="2.6416" size="1.778" layer="95">&gt;NAME</text>
<text x="-2.5654" y="-4.4958" size="1.778" layer="96">&gt;VALUE</text>
<pin name="A" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
<pin name="C" x="2.54" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
<symbol name="NPN" urn="urn:adsk.eagle:symbol:705530/1" library_version="45" library_locally_modified="yes">
<wire x1="2.54" y1="2.54" x2="0.508" y2="1.524" width="0.1524" layer="94"/>
<wire x1="1.778" y1="-1.524" x2="2.54" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="1.27" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="1.778" y2="-1.524" width="0.1524" layer="94"/>
<wire x1="1.54" y1="-2.04" x2="0.308" y2="-1.424" width="0.1524" layer="94"/>
<wire x1="1.524" y1="-2.413" x2="2.286" y2="-2.413" width="0.254" layer="94"/>
<wire x1="2.286" y1="-2.413" x2="1.778" y2="-1.778" width="0.254" layer="94"/>
<wire x1="1.778" y1="-1.778" x2="1.524" y2="-2.286" width="0.254" layer="94"/>
<wire x1="1.524" y1="-2.286" x2="1.905" y2="-2.286" width="0.254" layer="94"/>
<wire x1="1.905" y1="-2.286" x2="1.778" y2="-2.032" width="0.254" layer="94"/>
<text x="-10.16" y="7.62" size="1.778" layer="95">&gt;NAME</text>
<text x="-10.16" y="5.08" size="1.778" layer="96">&gt;VALUE</text>
<rectangle x1="-0.254" y1="-2.54" x2="0.508" y2="2.54" layer="94"/>
<pin name="B" x="-2.54" y="0" visible="off" length="short" direction="pas" swaplevel="1"/>
<pin name="E" x="2.54" y="-5.08" visible="off" length="short" direction="pas" swaplevel="3" rot="R90"/>
<pin name="C" x="2.54" y="5.08" visible="off" length="short" direction="pas" swaplevel="2" rot="R270"/>
</symbol>
<symbol name="R-EU" urn="urn:adsk.eagle:symbol:577966/2" library_version="45" library_locally_modified="yes">
<wire x1="-2.54" y1="-0.889" x2="2.54" y2="-0.889" width="0.254" layer="94"/>
<wire x1="2.54" y1="0.889" x2="-2.54" y2="0.889" width="0.254" layer="94"/>
<wire x1="2.54" y1="-0.889" x2="2.54" y2="0.889" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-0.889" x2="-2.54" y2="0.889" width="0.254" layer="94"/>
<text x="-3.81" y="1.4986" size="1.778" layer="95">&gt;NAME</text>
<text x="-3.81" y="-3.302" size="1.778" layer="96">&gt;VALUE</text>
<pin name="2" x="5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1" rot="R180"/>
<pin name="1" x="-5.08" y="0" visible="off" length="short" direction="pas" swaplevel="1"/>
</symbol>
<symbol name="R-TRIM" urn="urn:adsk.eagle:symbol:708080/1" library_version="46" library_locally_modified="yes">
<wire x1="0.762" y1="2.54" x2="0" y2="2.54" width="0.254" layer="94"/>
<wire x1="-0.762" y1="2.54" x2="-0.762" y2="-2.54" width="0.254" layer="94"/>
<wire x1="0.762" y1="-2.54" x2="0.762" y2="2.54" width="0.254" layer="94"/>
<wire x1="2.54" y1="0" x2="1.651" y2="0" width="0.1524" layer="94"/>
<wire x1="1.651" y1="0" x2="-1.8796" y2="1.7526" width="0.1524" layer="94"/>
<wire x1="0" y1="2.54" x2="0" y2="5.08" width="0.1524" layer="94"/>
<wire x1="0" y1="2.54" x2="-0.762" y2="2.54" width="0.254" layer="94"/>
<wire x1="-0.762" y1="-2.54" x2="0.762" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-2.286" y1="1.27" x2="-1.651" y2="2.413" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-2.54" x2="-2.54" y2="-0.508" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="-0.508" x2="-3.048" y2="-1.524" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="-0.508" x2="-2.032" y2="-1.524" width="0.1524" layer="94"/>
<text x="-5.969" y="-3.81" size="1.778" layer="95" rot="R90">&gt;NAME</text>
<text x="-3.81" y="-3.81" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<text x="-3.302" y="-3.81" size="1.27" layer="94">cw</text>
<pin name="1" x="0" y="-5.08" visible="pad" length="short" direction="pas" rot="R90"/>
<pin name="3" x="0" y="5.08" visible="pad" length="short" direction="pas" rot="R270"/>
<pin name="2" x="5.08" y="0" visible="pad" length="short" direction="pas" rot="R180"/>
</symbol>
<symbol name="CPOL" urn="urn:adsk.eagle:symbol:577968/1" library_version="45" library_locally_modified="yes">
<wire x1="-1.524" y1="-0.889" x2="1.524" y2="-0.889" width="0.254" layer="94"/>
<wire x1="1.524" y1="-0.889" x2="1.524" y2="0" width="0.254" layer="94"/>
<wire x1="-1.524" y1="0" x2="-1.524" y2="-0.889" width="0.254" layer="94"/>
<wire x1="-1.524" y1="0" x2="1.524" y2="0" width="0.254" layer="94"/>
<text x="1.143" y="0.4826" size="1.778" layer="95">&gt;NAME</text>
<text x="-0.5842" y="0.4064" size="1.27" layer="94" rot="R90">+</text>
<text x="1.143" y="-4.5974" size="1.778" layer="96">&gt;VALUE</text>
<rectangle x1="-1.651" y1="-2.54" x2="1.651" y2="-1.651" layer="94"/>
<pin name="-" x="0" y="-5.08" visible="off" length="short" direction="pas" rot="R90"/>
<pin name="+" x="0" y="2.54" visible="off" length="short" direction="pas" rot="R270"/>
</symbol>
<symbol name="OPAMP" urn="urn:adsk.eagle:symbol:705542/1" library_version="45" library_locally_modified="yes">
<wire x1="-5.08" y1="5.08" x2="-5.08" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="-5.08" y1="-5.08" x2="5.08" y2="0" width="0.4064" layer="94"/>
<wire x1="5.08" y1="0" x2="-5.08" y2="5.08" width="0.4064" layer="94"/>
<wire x1="-3.81" y1="3.175" x2="-3.81" y2="1.905" width="0.1524" layer="94"/>
<wire x1="-4.445" y1="2.54" x2="-3.175" y2="2.54" width="0.1524" layer="94"/>
<wire x1="-4.445" y1="-2.54" x2="-3.175" y2="-2.54" width="0.1524" layer="94"/>
<text x="2.54" y="3.175" size="1.778" layer="95">&gt;NAME</text>
<text x="2.54" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<pin name="-IN" x="-7.62" y="-2.54" visible="pad" length="short" direction="in"/>
<pin name="+IN" x="-7.62" y="2.54" visible="pad" length="short" direction="in"/>
<pin name="OUT" x="7.62" y="0" visible="pad" length="short" direction="out" rot="R180"/>
</symbol>
<symbol name="PWR+-" urn="urn:adsk.eagle:symbol:705543/1" locally_modified="yes" library_version="57" library_locally_modified="yes">
<text x="1.27" y="3.175" size="0.8128" layer="93" rot="R90">V+</text>
<text x="1.27" y="-4.445" size="0.8128" layer="93" rot="R90">V-</text>
<pin name="V+" x="0" y="7.62" visible="pad" length="middle" direction="pwr" rot="R270"/>
<pin name="V-" x="0" y="-7.62" visible="pad" length="middle" direction="pwr" rot="R90"/>
<text x="2.54" y="0" size="1.778" layer="95">&gt;name</text>
</symbol>
<symbol name="78XX" urn="urn:adsk.eagle:symbol:763977/1" library_version="49" library_locally_modified="yes">
<wire x1="-7.62" y1="-5.08" x2="7.62" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="7.62" y1="-5.08" x2="7.62" y2="2.54" width="0.4064" layer="94"/>
<wire x1="7.62" y1="2.54" x2="-7.62" y2="2.54" width="0.4064" layer="94"/>
<wire x1="-7.62" y1="2.54" x2="-7.62" y2="-5.08" width="0.4064" layer="94"/>
<text x="-7.62" y="5.715" size="1.778" layer="95">&gt;NAME</text>
<text x="-7.62" y="3.175" size="1.778" layer="96">&gt;VALUE</text>
<text x="-2.032" y="-4.318" size="1.524" layer="95">GND</text>
<pin name="VI" x="-10.16" y="0" length="short" direction="in"/>
<pin name="GND" x="0" y="-7.62" visible="pad" length="short" direction="pas" rot="R90"/>
<pin name="VO" x="10.16" y="0" length="short" direction="pas" rot="R180"/>
</symbol>
<symbol name="OPTOKOPPLER(4X)" urn="urn:adsk.eagle:symbol:763979/1" library_version="49" library_locally_modified="yes">
<wire x1="-2.413" y1="-1.143" x2="-1.016" y2="0.254" width="0.1524" layer="94"/>
<wire x1="-1.016" y1="0.254" x2="-1.905" y2="-0.127" width="0.1524" layer="94"/>
<wire x1="-1.905" y1="-0.127" x2="-1.397" y2="-0.635" width="0.1524" layer="94"/>
<wire x1="-1.397" y1="-0.635" x2="-1.016" y2="0.254" width="0.1524" layer="94"/>
<wire x1="-1.143" y1="1.397" x2="-2.032" y2="1.016" width="0.1524" layer="94"/>
<wire x1="-2.032" y1="1.016" x2="-1.524" y2="0.508" width="0.1524" layer="94"/>
<wire x1="-1.524" y1="0.508" x2="-1.143" y2="1.397" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="0" x2="-1.143" y2="1.397" width="0.1524" layer="94"/>
<wire x1="-3.175" y1="1.27" x2="-4.445" y2="-1.27" width="0.254" layer="94"/>
<wire x1="-4.445" y1="-1.27" x2="-5.715" y2="1.27" width="0.254" layer="94"/>
<wire x1="-3.175" y1="-1.27" x2="-4.445" y2="-1.27" width="0.254" layer="94"/>
<wire x1="-4.445" y1="-1.27" x2="-5.715" y2="-1.27" width="0.254" layer="94"/>
<wire x1="-3.175" y1="1.27" x2="-4.445" y2="1.27" width="0.254" layer="94"/>
<wire x1="-4.445" y1="1.27" x2="-4.445" y2="-1.27" width="0.254" layer="94"/>
<wire x1="-4.445" y1="1.27" x2="-5.715" y2="1.27" width="0.254" layer="94"/>
<wire x1="-6.985" y1="5.08" x2="4.445" y2="5.08" width="0.4064" layer="94"/>
<wire x1="-6.985" y1="-5.08" x2="4.445" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="-4.445" y1="2.54" x2="-4.445" y2="1.27" width="0.1524" layer="94"/>
<wire x1="-6.985" y1="5.08" x2="-6.985" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="-4.445" y1="-1.27" x2="-4.445" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="4.445" y1="5.08" x2="4.445" y2="-5.08" width="0.4064" layer="94"/>
<wire x1="-4.445" y1="2.54" x2="-7.62" y2="2.54" width="0.1524" layer="94"/>
<wire x1="-4.445" y1="-2.54" x2="-7.62" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="2.54" y1="2.54" x2="0" y2="0" width="0.1524" layer="94"/>
<wire x1="0" y1="0" x2="2.286" y2="-2.286" width="0.1524" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="5.08" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="2.54" y1="2.54" x2="5.08" y2="2.54" width="0.1524" layer="94"/>
<wire x1="1.778" y1="-1.016" x2="2.286" y2="-2.286" width="0.1524" layer="94"/>
<wire x1="2.286" y1="-2.286" x2="2.54" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="2.286" y1="-2.286" x2="1.016" y2="-1.778" width="0.1524" layer="94"/>
<wire x1="1.016" y1="-1.778" x2="1.778" y2="-1.016" width="0.1524" layer="94"/>
<text x="-6.985" y="5.715" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.985" y="-7.62" size="1.778" layer="96">&gt;VALUE</text>
<rectangle x1="-0.381" y1="-2.54" x2="0.381" y2="2.54" layer="94"/>
<pin name="A" x="-10.16" y="2.54" visible="pad" length="short" direction="pas"/>
<pin name="C" x="-10.16" y="-2.54" visible="pad" length="short" direction="pas"/>
<pin name="EMIT" x="7.62" y="-2.54" visible="pad" length="short" direction="pas" rot="R180"/>
<pin name="COL" x="7.62" y="2.54" visible="pad" length="short" direction="pas" rot="R180"/>
</symbol>
<symbol name="TP" urn="urn:adsk.eagle:symbol:817535/1" library_version="51" library_locally_modified="yes">
<wire x1="-0.762" y1="-0.762" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="0.762" y2="-0.762" width="0.254" layer="94"/>
<wire x1="0.762" y1="-0.762" x2="0" y2="-1.524" width="0.254" layer="94"/>
<wire x1="0" y1="-1.524" x2="-0.762" y2="-0.762" width="0.254" layer="94"/>
<text x="-1.27" y="1.27" size="1.778" layer="95">&gt;NAME</text>
<pin name="TP" x="0" y="-2.54" visible="off" length="short" direction="in" rot="R90"/>
</symbol>
<symbol name="NEUTRIK_NC3MAH" urn="urn:adsk.eagle:symbol:705583/3" library_version="57" library_locally_modified="yes">
<pin name="1" x="-7.62" y="0" length="middle" rot="R90"/>
<pin name="2" x="-5.08" y="0" length="middle" rot="R90"/>
<pin name="3" x="-2.54" y="0" length="middle" rot="R90"/>
<pin name="G" x="0" y="0" length="middle" rot="R90"/>
<wire x1="-10.16" y1="10.16" x2="-10.16" y2="2.54" width="0.254" layer="94"/>
<wire x1="-10.16" y1="2.54" x2="2.54" y2="2.54" width="0.254" layer="94"/>
<wire x1="2.54" y1="2.54" x2="2.54" y2="10.16" width="0.254" layer="94"/>
<wire x1="2.54" y1="10.16" x2="-10.16" y2="10.16" width="0.254" layer="94"/>
<text x="-5.08" y="10.16" size="1.778" layer="94">&gt;name</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="NEUTRIK_NC3FAH" urn="urn:adsk.eagle:component:705653/14" locally_modified="yes" library_version="57" library_locally_modified="yes">
<gates>
<gate name="G$1" symbol="NEUTRIK_NC3FAH" x="0" y="0"/>
</gates>
<devices>
<device name="" package="NEUTRIK_NC3FAH">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:705652/7"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="RELAY_EE2-5NU" urn="urn:adsk.eagle:component:823803/3" locally_modified="yes" prefix="K" library_version="57" library_locally_modified="yes">
<description>&lt;b&gt;RELAY&lt;/b&gt;&lt;p&gt;
SPST</description>
<gates>
<gate name="1" symbol="K" x="0" y="0" addlevel="must"/>
<gate name="2" symbol="U" x="17.78" y="-2.54" addlevel="always" swaplevel="1"/>
<gate name="3" symbol="U" x="17.78" y="-17.78" addlevel="always" swaplevel="1"/>
</gates>
<devices>
<device name="" package="351">
<connects>
<connect gate="1" pin="1" pad="1"/>
<connect gate="1" pin="2" pad="2"/>
<connect gate="2" pin="O" pad="Q1"/>
<connect gate="2" pin="P" pad="P1"/>
<connect gate="2" pin="S" pad="S1"/>
<connect gate="3" pin="O" pad="Q2"/>
<connect gate="3" pin="P" pad="P2"/>
<connect gate="3" pin="S" pad="S2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:823802/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="10PIN_HEADER_SMD" urn="urn:adsk.eagle:component:568051/34" locally_modified="yes" library_version="57" library_locally_modified="yes">
<description>10 Pin Header (Flachbandkabel)</description>
<gates>
<gate name="G$1" symbol="10PIN_HEADER" x="35.56" y="-12.7"/>
</gates>
<devices>
<device name="" package="87832-10">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$10" pad="10"/>
<connect gate="G$1" pin="P$2" pad="2"/>
<connect gate="G$1" pin="P$3" pad="3"/>
<connect gate="G$1" pin="P$4" pad="4"/>
<connect gate="G$1" pin="P$5" pad="5"/>
<connect gate="G$1" pin="P$6" pad="6"/>
<connect gate="G$1" pin="P$7" pad="7"/>
<connect gate="G$1" pin="P$8" pad="8"/>
<connect gate="G$1" pin="P$9" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:568050/8"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="KONDENSATOR_0603" urn="urn:adsk.eagle:component:576739/25" uservalue="yes" library_version="57" library_locally_modified="yes">
<description>Kondensator Standard 0603</description>
<gates>
<gate name="G$1" symbol="C-EU" x="0" y="0"/>
</gates>
<devices>
<device name="" package="C0603">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:576738/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="4148_SOD323" urn="urn:adsk.eagle:component:578211/17" library_version="57" library_locally_modified="yes">
<description>Standard 4148 Diode SOD323 Format</description>
<gates>
<gate name="G$1" symbol="DIODE" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SOD323-R">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="C"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:578210/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="BC847" urn="urn:adsk.eagle:component:705535/14" prefix="T" library_version="57" library_locally_modified="yes">
<description>&lt;b&gt;NPN TRANSISTOR&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="NPN" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SOT23">
<connects>
<connect gate="G$1" pin="B" pad="1"/>
<connect gate="G$1" pin="C" pad="3"/>
<connect gate="G$1" pin="E" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:705533/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="WIDERSTAND_0805" urn="urn:adsk.eagle:component:577964/21" locally_modified="yes" prefix="R" uservalue="yes" library_version="57" library_locally_modified="yes">
<description>&lt;B&gt;RESISTOR&lt;/B&gt;, European symbol</description>
<gates>
<gate name="G$1" symbol="R-EU" x="0" y="0"/>
</gates>
<devices>
<device name="R0805" package="R0805">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:577963/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="R_TRIMMER_SMD" urn="urn:adsk.eagle:component:708083/10" library_version="57" library_locally_modified="yes">
<gates>
<gate name="G$1" symbol="R-TRIM" x="2.54" y="0"/>
</gates>
<devices>
<device name="" package="RTRIM4G/J">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:708082/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="SMD_ELCTROLYTIC" urn="urn:adsk.eagle:component:577971/18" library_version="57" library_locally_modified="yes">
<description>SMD Elektrolyt Kondensator 153CLV-0605</description>
<gates>
<gate name="G$1" symbol="CPOL" x="0" y="0"/>
</gates>
<devices>
<device name="" package="153CLV-0605">
<connects>
<connect gate="G$1" pin="+" pad="+"/>
<connect gate="G$1" pin="-" pad="-"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:577970/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="OP275" urn="urn:adsk.eagle:component:705549/14" locally_modified="yes" prefix="IC" library_version="57" library_locally_modified="yes">
<description>&lt;b&gt;Dual Very Low Noise Precision Operational Amplifier&lt;/b&gt;&lt;p&gt;
Source: http://www.analog.com/static/imported-files/data_sheets/OP270.pdf</description>
<gates>
<gate name="A" symbol="OPAMP" x="-7.62" y="7.62" swaplevel="1"/>
<gate name="B" symbol="OPAMP" x="-7.62" y="-7.62" swaplevel="1"/>
<gate name="P" symbol="PWR+-" x="7.62" y="0"/>
</gates>
<devices>
<device name="P" package="DIL08">
<connects>
<connect gate="A" pin="+IN" pad="3"/>
<connect gate="A" pin="-IN" pad="2"/>
<connect gate="A" pin="OUT" pad="1"/>
<connect gate="B" pin="+IN" pad="5"/>
<connect gate="B" pin="-IN" pad="6"/>
<connect gate="B" pin="OUT" pad="7"/>
<connect gate="P" pin="V+" pad="8"/>
<connect gate="P" pin="V-" pad="4"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:705547/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="" package="SOIC8">
<connects>
<connect gate="A" pin="+IN" pad="3"/>
<connect gate="A" pin="-IN" pad="2"/>
<connect gate="A" pin="OUT" pad="1"/>
<connect gate="B" pin="+IN" pad="5"/>
<connect gate="B" pin="-IN" pad="6"/>
<connect gate="B" pin="OUT" pad="7"/>
<connect gate="P" pin="V+" pad="8"/>
<connect gate="P" pin="V-" pad="4"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:705548/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="78**" urn="urn:adsk.eagle:component:763984/8" locally_modified="yes" library_version="57" library_locally_modified="yes">
<gates>
<gate name="G$1" symbol="78XX" x="-7.62" y="5.08"/>
</gates>
<devices>
<device name="" package="TO252">
<connects>
<connect gate="G$1" pin="GND" pad="2"/>
<connect gate="G$1" pin="VI" pad="1"/>
<connect gate="G$1" pin="VO" pad="3"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:763981/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="OPTOKOPPLER(4X)" urn="urn:adsk.eagle:component:763983/8" locally_modified="yes" prefix="OK" library_version="57" library_locally_modified="yes">
<description>Optokoppler (4x) 
digikey: TLP291-4(GBE)-ND</description>
<gates>
<gate name="A" symbol="OPTOKOPPLER(4X)" x="0" y="27.94"/>
<gate name="B" symbol="OPTOKOPPLER(4X)" x="0" y="10.16"/>
<gate name="C" symbol="OPTOKOPPLER(4X)" x="0" y="-7.62"/>
<gate name="D" symbol="OPTOKOPPLER(4X)" x="0" y="-25.4"/>
</gates>
<devices>
<device name="" package="SOIC16">
<connects>
<connect gate="A" pin="A" pad="1"/>
<connect gate="A" pin="C" pad="2"/>
<connect gate="A" pin="COL" pad="16"/>
<connect gate="A" pin="EMIT" pad="15"/>
<connect gate="B" pin="A" pad="3"/>
<connect gate="B" pin="C" pad="4"/>
<connect gate="B" pin="COL" pad="14"/>
<connect gate="B" pin="EMIT" pad="13"/>
<connect gate="C" pin="A" pad="5"/>
<connect gate="C" pin="C" pad="6"/>
<connect gate="C" pin="COL" pad="12"/>
<connect gate="C" pin="EMIT" pad="11"/>
<connect gate="D" pin="A" pad="7"/>
<connect gate="D" pin="C" pad="8"/>
<connect gate="D" pin="COL" pad="10"/>
<connect gate="D" pin="EMIT" pad="9"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:763982/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="TP" urn="urn:adsk.eagle:component:817538/7" locally_modified="yes" library_version="57" library_locally_modified="yes">
<gates>
<gate name="G$1" symbol="TP" x="0" y="5.08"/>
</gates>
<devices>
<device name="SMD" package="TP">
<connects>
<connect gate="G$1" pin="TP" pad="P$1"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:817537/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="THT" package="THT_PIN">
<connects>
<connect gate="G$1" pin="TP" pad="P$1"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:817866/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="TL072" urn="urn:adsk.eagle:component:823801/1" locally_modified="yes" library_version="57" library_locally_modified="yes">
<gates>
<gate name="A" symbol="OPAMP" x="-7.62" y="7.62"/>
<gate name="B" symbol="OPAMP" x="17.78" y="7.62"/>
<gate name="P" symbol="PWR+-" x="38.1" y="7.62"/>
</gates>
<devices>
<device name="" package="SOIC8">
<connects>
<connect gate="A" pin="+IN" pad="3"/>
<connect gate="A" pin="-IN" pad="2"/>
<connect gate="A" pin="OUT" pad="1"/>
<connect gate="B" pin="+IN" pad="5"/>
<connect gate="B" pin="-IN" pad="6"/>
<connect gate="B" pin="OUT" pad="7"/>
<connect gate="P" pin="V+" pad="8"/>
<connect gate="P" pin="V-" pad="4"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:705548/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="NEUTRIK_NC3MAH" urn="urn:adsk.eagle:component:705586/12" locally_modified="yes" library_version="57" library_locally_modified="yes">
<gates>
<gate name="G$1" symbol="NEUTRIK_NC3MAH" x="-2.54" y="-2.54"/>
</gates>
<devices>
<device name="" package="NEUTRIK_NC3MAH">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="G" pad="G"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:705585/4"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="THAT_Library" urn="urn:adsk.eagle:library:704460">
<packages>
<package name="SO08" urn="urn:adsk.eagle:footprint:704558/1" locally_modified="yes" library_version="12" library_locally_modified="yes">
<description>&lt;b&gt;SMALL OUTLINE INTEGRATED CIRCUIT&lt;/b&gt;&lt;p&gt;
body 3.9 mm/JEDEC MS-012AA</description>
<wire x1="-2.9" y1="3.9" x2="2.9" y2="3.9" width="0.1998" layer="39"/>
<wire x1="2.9" y1="3.9" x2="2.9" y2="-3.9" width="0.1998" layer="39"/>
<wire x1="2.9" y1="-3.9" x2="-2.9" y2="-3.9" width="0.1998" layer="39"/>
<wire x1="-2.9" y1="-3.9" x2="-2.9" y2="3.9" width="0.1998" layer="39"/>
<wire x1="2.667" y1="1.905" x2="2.667" y2="-1.905" width="0.2032" layer="51"/>
<wire x1="2.667" y1="-1.905" x2="-2.667" y2="-1.905" width="0.2032" layer="51"/>
<wire x1="-2.667" y1="-1.905" x2="-2.667" y2="1.905" width="0.2032" layer="51"/>
<wire x1="-2.667" y1="1.905" x2="2.667" y2="1.905" width="0.2032" layer="51"/>
<wire x1="-2.667" y1="1.27" x2="2.667" y2="1.27" width="0.2032" layer="21"/>
<wire x1="2.667" y1="1.27" x2="2.667" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="2.667" y1="-1.27" x2="-2.667" y2="-1.27" width="0.2032" layer="21"/>
<wire x1="-2.667" y1="-1.27" x2="-2.667" y2="1.27" width="0.2032" layer="21"/>
<circle x="-1.905" y="-0.635" radius="0.3175" width="0" layer="21"/>
<smd name="2" x="-0.635" y="-2.6" dx="0.6" dy="2.2" layer="1"/>
<smd name="7" x="-0.635" y="2.6" dx="0.6" dy="2.2" layer="1"/>
<smd name="1" x="-1.905" y="-2.6" dx="0.6" dy="2.2" layer="1"/>
<smd name="3" x="0.635" y="-2.6" dx="0.6" dy="2.2" layer="1"/>
<smd name="4" x="1.905" y="-2.6" dx="0.6" dy="2.2" layer="1"/>
<smd name="8" x="-1.905" y="2.6" dx="0.6" dy="2.2" layer="1"/>
<smd name="6" x="0.635" y="2.6" dx="0.6" dy="2.2" layer="1"/>
<smd name="5" x="1.905" y="2.6" dx="0.6" dy="2.2" layer="1"/>
<text x="-4.064" y="2.54" size="1.016" layer="25" ratio="18" rot="R270">&gt;NAME</text>
<text x="-2.3495" y="-5.1435" size="0.8128" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="-2.1501" y1="-3.1001" x2="-1.6599" y2="-2" layer="51"/>
<rectangle x1="-0.8801" y1="-3.1001" x2="-0.3899" y2="-2" layer="51"/>
<rectangle x1="0.3899" y1="-3.1001" x2="0.8801" y2="-2" layer="51"/>
<rectangle x1="1.6599" y1="-3.1001" x2="2.1501" y2="-2" layer="51"/>
<rectangle x1="1.6599" y1="2" x2="2.1501" y2="3.1001" layer="51"/>
<rectangle x1="0.3899" y1="2" x2="0.8801" y2="3.1001" layer="51"/>
<rectangle x1="-0.8801" y1="2" x2="-0.3899" y2="3.1001" layer="51"/>
<rectangle x1="-2.1501" y1="2" x2="-1.6599" y2="3.1001" layer="51"/>
</package>
<package name="DIL08" urn="urn:adsk.eagle:footprint:704559/1" library_version="11">
<description>&lt;b&gt;Dual In Line Package&lt;/b&gt;</description>
<wire x1="5.08" y1="1.905" x2="-5.08" y2="1.905" width="0.2032" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="5.08" y2="-1.905" width="0.2032" layer="21"/>
<wire x1="5.08" y1="1.905" x2="5.08" y2="-1.905" width="0.2032" layer="21"/>
<wire x1="-5.08" y1="1.905" x2="-5.08" y2="0.6985" width="0.2032" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-5.08" y2="-0.6985" width="0.2032" layer="21"/>
<wire x1="-5.08" y1="0.6985" x2="-5.08" y2="-0.6985" width="0.2032" layer="21" curve="-180"/>
<pad name="1" x="-3.81" y="-3.81" drill="0.8128" shape="long" rot="R90" first="yes"/>
<pad name="2" x="-1.27" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="7" x="-1.27" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="8" x="-3.81" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="3" x="1.27" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="4" x="3.81" y="-3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="6" x="1.27" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<pad name="5" x="3.81" y="3.81" drill="0.8128" shape="long" rot="R90"/>
<text x="-5.715" y="-2.54" size="1.016" layer="25" ratio="18" rot="R90">&gt;NAME</text>
<text x="-3.4925" y="-0.635" size="0.8128" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="SIP8" urn="urn:adsk.eagle:footprint:704630/1" library_version="11">
<description>&lt;b&gt;SIP-9&lt;/b&gt;&lt;p&gt;
9 Pin SIP IC</description>
<wire x1="-11.43" y1="-1.905" x2="-8.89" y2="-1.905" width="0.2032" layer="21"/>
<wire x1="-8.89" y1="-1.905" x2="8.89" y2="-1.905" width="0.2032" layer="21"/>
<wire x1="8.89" y1="-1.905" x2="8.89" y2="1.905" width="0.2032" layer="21"/>
<wire x1="8.89" y1="1.905" x2="-8.89" y2="1.905" width="0.2032" layer="21"/>
<wire x1="-8.89" y1="1.905" x2="-11.43" y2="1.905" width="0.2032" layer="21"/>
<wire x1="-11.43" y1="1.905" x2="-11.43" y2="-1.905" width="0.2032" layer="21"/>
<wire x1="-8.89" y1="-1.905" x2="-8.89" y2="1.905" width="0.2032" layer="21"/>
<pad name="1" x="-10.16" y="0" drill="0.8128" shape="long" rot="R90" first="yes"/>
<pad name="2" x="-7.62" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="3" x="-5.08" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="4" x="-2.54" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="5" x="0" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="6" x="2.54" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="7" x="5.08" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="8" x="7.62" y="0" drill="0.8128" shape="long" rot="R90"/>
<text x="-11.1125" y="-3.4925" size="1.016" layer="25" ratio="18">&gt;NAME</text>
<text x="4.7625" y="-3.4925" size="0.8128" layer="27" ratio="10">&gt;VALUE</text>
<text x="-10.795" y="-1.27" size="1.016" layer="51" ratio="12">1</text>
</package>
</packages>
<packages3d>
<package3d name="SO08" urn="urn:adsk.eagle:package:704562/2" type="model" library_version="11">
<description>SMALL OUTLINE INTEGRATED CIRCUIT
body 3.9 mm/JEDEC MS-012AA</description>
</package3d>
<package3d name="DIL08" urn="urn:adsk.eagle:package:704564/2" type="model" library_version="11">
<description>Dual In Line Package</description>
</package3d>
<package3d name="SIP8" urn="urn:adsk.eagle:package:704631/1" type="box" library_version="11">
<description>SIP-9
9 Pin SIP IC</description>
</package3d>
</packages3d>
<symbols>
<symbol name="THAT1240" urn="urn:adsk.eagle:symbol:704557/1" library_version="11">
<wire x1="-10.16" y1="12.7" x2="-10.16" y2="-12.7" width="0.4064" layer="94"/>
<wire x1="-10.16" y1="-12.7" x2="15.24" y2="0" width="0.4064" layer="94"/>
<wire x1="15.24" y1="0" x2="-10.16" y2="12.7" width="0.4064" layer="94"/>
<text x="-0.635" y="4.445" size="1.524" layer="95">V+</text>
<text x="-0.635" y="-5.715" size="1.524" layer="95">V-</text>
<text x="3.81" y="-3.175" size="1.524" layer="95">REF</text>
<text x="10.16" y="6.35" size="1.778" layer="95">&gt;NAME</text>
<text x="10.16" y="3.81" size="1.778" layer="96">&gt;VALUE</text>
<text x="3.81" y="1.27" size="1.524" layer="95">SEN</text>
<pin name="IN-" x="-15.24" y="7.62" length="middle" direction="in"/>
<pin name="IN+" x="-15.24" y="-7.62" length="middle" direction="in"/>
<pin name="V+" x="0" y="12.7" visible="pad" length="middle" direction="pwr" rot="R270"/>
<pin name="V-" x="0" y="-12.7" visible="pad" length="middle" direction="pwr" rot="R90"/>
<pin name="REF" x="5.08" y="-10.16" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="OUT" x="20.32" y="0" visible="pad" length="middle" direction="out" rot="R180"/>
<pin name="SEN" x="5.08" y="10.16" visible="pad" length="middle" direction="out" rot="R270"/>
</symbol>
<symbol name="THAT2181" urn="urn:adsk.eagle:symbol:704629/1" library_version="11">
<wire x1="-10.16" y1="12.7" x2="-10.16" y2="-12.7" width="0.4064" layer="94"/>
<wire x1="-10.16" y1="-12.7" x2="15.24" y2="0" width="0.4064" layer="94"/>
<wire x1="15.24" y1="0" x2="-10.16" y2="12.7" width="0.4064" layer="94"/>
<text x="-5.715" y="6.35" size="1.524" layer="95">V+</text>
<text x="-5.715" y="-8.255" size="1.524" layer="95">V-</text>
<text x="-1.905" y="-5.715" size="1.524" layer="95">GND</text>
<text x="10.16" y="-5.08" size="1.778" layer="95">&gt;NAME</text>
<text x="10.16" y="-7.62" size="1.778" layer="96">&gt;VALUE</text>
<text x="3.81" y="-3.175" size="1.524" layer="95">Ec-</text>
<text x="-1.905" y="3.81" size="1.524" layer="95">SYM</text>
<text x="3.81" y="1.27" size="1.524" layer="95">Ec+</text>
<text x="-5.08" y="-1.27" size="2.54" layer="94" ratio="10">VCA</text>
<pin name="IN" x="-15.24" y="0" visible="pad" length="middle" direction="in"/>
<pin name="V+" x="-5.08" y="15.24" visible="pad" length="middle" direction="pwr" rot="R270"/>
<pin name="V-" x="-5.08" y="-15.24" visible="pad" length="middle" direction="pwr" rot="R90"/>
<pin name="GND" x="0" y="-12.7" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="OUT" x="20.32" y="0" visible="pad" length="middle" direction="out" rot="R180"/>
<pin name="EC-" x="5.08" y="-10.16" visible="pad" length="middle" direction="out" rot="R90"/>
<pin name="EC+" x="5.08" y="10.16" visible="pad" length="middle" direction="pas" rot="R270"/>
<pin name="SYM" x="0" y="12.7" visible="pad" length="middle" direction="pas" rot="R270"/>
</symbol>
<symbol name="THAT1646" urn="urn:adsk.eagle:symbol:704560/1" library_version="11">
<wire x1="-10.16" y1="12.7" x2="-10.16" y2="-12.7" width="0.4064" layer="94"/>
<wire x1="-10.16" y1="-12.7" x2="10.16" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="10.16" y1="-2.54" x2="15.24" y2="0" width="0.4064" layer="94"/>
<wire x1="15.24" y1="0" x2="10.16" y2="2.54" width="0.4064" layer="94"/>
<wire x1="10.16" y1="2.54" x2="-10.16" y2="12.7" width="0.4064" layer="94"/>
<wire x1="15.24" y1="5.08" x2="12.7" y2="5.08" width="0.1524" layer="94"/>
<wire x1="12.7" y1="5.08" x2="10.16" y2="2.54" width="0.1524" layer="94"/>
<wire x1="15.24" y1="-5.08" x2="12.7" y2="-5.08" width="0.1524" layer="94"/>
<wire x1="12.7" y1="-5.08" x2="10.16" y2="-2.54" width="0.1524" layer="94"/>
<text x="-5.715" y="6.985" size="1.524" layer="95">V+</text>
<text x="-5.715" y="-8.255" size="1.524" layer="95">V-</text>
<text x="-1.905" y="-5.715" size="1.524" layer="95">SEN-</text>
<text x="5.08" y="11.43" size="1.778" layer="95">&gt;NAME</text>
<text x="5.08" y="8.89" size="1.778" layer="96">&gt;VALUE</text>
<text x="-1.905" y="3.81" size="1.524" layer="95">SEN+</text>
<text x="3.81" y="0.635" size="1.524" layer="95">OUT+</text>
<text x="3.81" y="-2.2225" size="1.524" layer="95">OUT-</text>
<pin name="IN" x="-15.24" y="2.54" length="middle" direction="in"/>
<pin name="GND" x="-15.24" y="-2.54" length="middle" direction="in"/>
<pin name="V+" x="-5.08" y="15.24" visible="pad" length="middle" direction="pwr" rot="R270"/>
<pin name="V-" x="-5.08" y="-15.24" visible="pad" length="middle" direction="pwr" rot="R90"/>
<pin name="SEN-" x="0" y="-12.7" visible="pad" length="middle" direction="pas" rot="R90"/>
<pin name="OUT+" x="20.32" y="5.08" visible="pad" length="middle" direction="out" rot="R180"/>
<pin name="SEN+" x="0" y="12.7" visible="pad" length="middle" direction="out" rot="R270"/>
<pin name="OUT-" x="20.32" y="-5.08" visible="pad" length="middle" direction="out" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="THAT1240" urn="urn:adsk.eagle:component:704565/7" locally_modified="yes" prefix="U" library_version="12" library_locally_modified="yes">
<description>Balanced Line Receiver&lt;p&gt;
THAT1240, THAT1243, THAT1246</description>
<gates>
<gate name="G$1" symbol="THAT1240" x="0" y="0"/>
</gates>
<devices>
<device name="SO8-U" package="SO08">
<connects>
<connect gate="G$1" pin="IN+" pad="3"/>
<connect gate="G$1" pin="IN-" pad="2"/>
<connect gate="G$1" pin="OUT" pad="6"/>
<connect gate="G$1" pin="REF" pad="1"/>
<connect gate="G$1" pin="SEN" pad="5"/>
<connect gate="G$1" pin="V+" pad="7"/>
<connect gate="G$1" pin="V-" pad="4"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:704562/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="PO8-U" package="DIL08">
<connects>
<connect gate="G$1" pin="IN+" pad="3"/>
<connect gate="G$1" pin="IN-" pad="2"/>
<connect gate="G$1" pin="OUT" pad="6"/>
<connect gate="G$1" pin="REF" pad="1"/>
<connect gate="G$1" pin="SEN" pad="5"/>
<connect gate="G$1" pin="V+" pad="7"/>
<connect gate="G$1" pin="V-" pad="4"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:704564/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="THAT2181" urn="urn:adsk.eagle:component:704632/1" locally_modified="yes" prefix="U" library_version="12" library_locally_modified="yes">
<description>VCA Trimmable IC</description>
<gates>
<gate name="G$1" symbol="THAT2181" x="0" y="0"/>
</gates>
<devices>
<device name="S" package="SO08">
<connects>
<connect gate="G$1" pin="EC+" pad="2"/>
<connect gate="G$1" pin="EC-" pad="3"/>
<connect gate="G$1" pin="GND" pad="6"/>
<connect gate="G$1" pin="IN" pad="1"/>
<connect gate="G$1" pin="OUT" pad="8"/>
<connect gate="G$1" pin="SYM" pad="4"/>
<connect gate="G$1" pin="V+" pad="7"/>
<connect gate="G$1" pin="V-" pad="5"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:704562/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="L" package="SIP8">
<connects>
<connect gate="G$1" pin="EC+" pad="2"/>
<connect gate="G$1" pin="EC-" pad="3"/>
<connect gate="G$1" pin="GND" pad="6"/>
<connect gate="G$1" pin="IN" pad="1"/>
<connect gate="G$1" pin="OUT" pad="8"/>
<connect gate="G$1" pin="SYM" pad="4"/>
<connect gate="G$1" pin="V+" pad="7"/>
<connect gate="G$1" pin="V-" pad="5"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:704631/1"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="THAT1646" urn="urn:adsk.eagle:component:704566/8" locally_modified="yes" prefix="U" library_version="12" library_locally_modified="yes">
<description>Outsmarts Balanced Line Driver</description>
<gates>
<gate name="G$1" symbol="THAT1646" x="0" y="0"/>
</gates>
<devices>
<device name="SO8-U" package="SO08">
<connects>
<connect gate="G$1" pin="GND" pad="3"/>
<connect gate="G$1" pin="IN" pad="4"/>
<connect gate="G$1" pin="OUT+" pad="8"/>
<connect gate="G$1" pin="OUT-" pad="1"/>
<connect gate="G$1" pin="SEN+" pad="7"/>
<connect gate="G$1" pin="SEN-" pad="2"/>
<connect gate="G$1" pin="V+" pad="6"/>
<connect gate="G$1" pin="V-" pad="5"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:704562/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="PO8-U" package="DIL08">
<connects>
<connect gate="G$1" pin="GND" pad="3"/>
<connect gate="G$1" pin="IN" pad="4"/>
<connect gate="G$1" pin="OUT+" pad="8"/>
<connect gate="G$1" pin="OUT-" pad="1"/>
<connect gate="G$1" pin="SEN+" pad="7"/>
<connect gate="G$1" pin="SEN-" pad="2"/>
<connect gate="G$1" pin="V+" pad="6"/>
<connect gate="G$1" pin="V-" pad="5"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:704564/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1" urn="urn:adsk.eagle:library:371">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="V+" urn="urn:adsk.eagle:symbol:26939/1" library_version="1">
<wire x1="0.889" y1="-1.27" x2="0" y2="0.127" width="0.254" layer="94"/>
<wire x1="0" y1="0.127" x2="-0.889" y2="-1.27" width="0.254" layer="94"/>
<wire x1="-0.889" y1="-1.27" x2="0.889" y2="-1.27" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="V+" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="V-" urn="urn:adsk.eagle:symbol:26940/1" library_version="1">
<wire x1="-0.889" y1="1.27" x2="0" y2="-0.127" width="0.254" layer="94"/>
<wire x1="0" y1="-0.127" x2="0.889" y2="1.27" width="0.254" layer="94"/>
<wire x1="-0.889" y1="1.27" x2="0.889" y2="1.27" width="0.254" layer="94"/>
<text x="-5.08" y="2.54" size="1.778" layer="96" rot="R270">&gt;VALUE</text>
<pin name="V-" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
<symbol name="AGND" urn="urn:adsk.eagle:symbol:26949/1" library_version="1">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<wire x1="-1.0922" y1="-0.508" x2="1.0922" y2="-0.508" width="0.254" layer="94"/>
<text x="-2.54" y="-5.08" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="AGND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="V+" urn="urn:adsk.eagle:component:26966/1" prefix="P+" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="V+" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="V-" urn="urn:adsk.eagle:component:26971/1" prefix="P-" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="V-" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="AGND" urn="urn:adsk.eagle:component:26977/1" prefix="AGND" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="VR1" symbol="AGND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply2" urn="urn:adsk.eagle:library:372">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
Please keep in mind, that these devices are necessary for the
automatic wiring of the supply signals.&lt;p&gt;
The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="DGND" urn="urn:adsk.eagle:symbol:27019/1" library_version="2">
<wire x1="-1.27" y1="0" x2="1.27" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="0" y2="-1.27" width="0.254" layer="94"/>
<wire x1="0" y1="-1.27" x2="-1.27" y2="0" width="0.254" layer="94"/>
<text x="-2.667" y="-3.175" size="1.778" layer="96">&gt;VALUE</text>
<pin name="DGND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
<symbol name="+05V" urn="urn:adsk.eagle:symbol:26987/1" library_version="2">
<wire x1="-0.635" y1="1.27" x2="0.635" y2="1.27" width="0.1524" layer="94"/>
<wire x1="0" y1="0.635" x2="0" y2="1.905" width="0.1524" layer="94"/>
<circle x="0" y="1.27" radius="1.27" width="0.254" layer="94"/>
<text x="-1.905" y="3.175" size="1.778" layer="96">&gt;VALUE</text>
<pin name="+5V" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="DGND" urn="urn:adsk.eagle:component:27076/1" prefix="SUPPLY" library_version="2">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="DGND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="+5V" urn="urn:adsk.eagle:component:27032/1" prefix="SUPPLY" library_version="2">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="+5V" symbol="+05V" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="SPI" urn="urn:adsk.eagle:library:750815">
<packages>
<package name="SOIC16" urn="urn:adsk.eagle:footprint:810209/1" library_version="2">
<description>&lt;b&gt;SMALL OUTLINE INTEGRATED CIRCUIT&lt;/b&gt;&lt;p&gt;
16-Pin (150-Mil) SOIC&lt;br&gt;
Source: http://www.cypress.com .. 38-12025_0P_V.pdf</description>
<wire x1="3.8" y1="-1.795" x2="-4.79" y2="-1.795" width="0.2032" layer="51"/>
<wire x1="-4.79" y1="-1.795" x2="-4.79" y2="1.795" width="0.2032" layer="51"/>
<wire x1="-4.79" y1="1.795" x2="3.8" y2="1.795" width="0.2032" layer="51"/>
<wire x1="3.8" y1="1.795" x2="3.8" y2="-1.795" width="0.2032" layer="51"/>
<circle x="-4.05" y="-0.995" radius="0.3256" width="0.2032" layer="21"/>
<smd name="2" x="-3.175" y="-2.695" dx="0.635" dy="1.524" layer="1"/>
<smd name="11" x="-0.635" y="2.695" dx="0.635" dy="1.524" layer="1"/>
<smd name="1" x="-4.445" y="-2.695" dx="0.635" dy="1.524" layer="1"/>
<smd name="3" x="-1.905" y="-2.695" dx="0.635" dy="1.524" layer="1"/>
<smd name="4" x="-0.635" y="-2.695" dx="0.635" dy="1.524" layer="1"/>
<smd name="12" x="-1.905" y="2.695" dx="0.635" dy="1.524" layer="1"/>
<smd name="10" x="0.635" y="2.695" dx="0.635" dy="1.524" layer="1"/>
<smd name="9" x="1.905" y="2.695" dx="0.635" dy="1.524" layer="1"/>
<smd name="6" x="1.905" y="-2.695" dx="0.635" dy="1.524" layer="1"/>
<smd name="5" x="0.635" y="-2.695" dx="0.635" dy="1.524" layer="1"/>
<smd name="7" x="3.175" y="-2.695" dx="0.635" dy="1.524" layer="1"/>
<smd name="8" x="3.175" y="2.695" dx="0.635" dy="1.524" layer="1"/>
<smd name="13" x="-3.175" y="2.695" dx="0.635" dy="1.524" layer="1"/>
<smd name="14" x="-4.445" y="2.695" dx="0.635" dy="1.524" layer="1"/>
<text x="-5.08" y="-2.54" size="1.27" layer="25" rot="R90">&gt;NAME</text>
<text x="-3.175" y="-0.635" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-4.6901" y1="-2.921" x2="-4.1999" y2="-1.8951" layer="51"/>
<rectangle x1="-3.4201" y1="-2.921" x2="-2.9299" y2="-1.8951" layer="51"/>
<rectangle x1="-2.1501" y1="-2.921" x2="-1.6599" y2="-1.8951" layer="51"/>
<rectangle x1="-0.8801" y1="-2.921" x2="-0.3899" y2="-1.8951" layer="51"/>
<rectangle x1="0.3899" y1="-2.921" x2="0.8801" y2="-1.8951" layer="51"/>
<rectangle x1="1.6599" y1="-2.921" x2="2.1501" y2="-1.8951" layer="51"/>
<rectangle x1="2.9299" y1="-2.921" x2="3.4201" y2="-1.8951" layer="51"/>
<rectangle x1="2.9299" y1="1.8951" x2="3.4201" y2="2.921" layer="51"/>
<rectangle x1="1.6599" y1="1.8951" x2="2.1501" y2="2.921" layer="51"/>
<rectangle x1="0.3899" y1="1.8951" x2="0.8801" y2="2.921" layer="51"/>
<rectangle x1="-0.8801" y1="1.8951" x2="-0.3899" y2="2.921" layer="51"/>
<rectangle x1="-2.1501" y1="1.8951" x2="-1.6599" y2="2.921" layer="51"/>
<rectangle x1="-3.4201" y1="1.8951" x2="-2.9299" y2="2.921" layer="51"/>
<rectangle x1="-4.6901" y1="1.8951" x2="-4.1999" y2="2.921" layer="51"/>
</package>
</packages>
<packages3d>
<package3d name="SOIC16" urn="urn:adsk.eagle:package:810210/2" type="model" library_version="3">
<description>SMALL OUTLINE INTEGRATED CIRCUIT
16-Pin (150-Mil) SOIC
Source: http://www.cypress.com .. 38-12025_0P_V.pdf</description>
</package3d>
</packages3d>
<symbols>
<symbol name="MCP4922" urn="urn:adsk.eagle:symbol:810208/1" library_version="2">
<wire x1="-22.86" y1="27.94" x2="-22.86" y2="12.7" width="0.254" layer="94"/>
<wire x1="-22.86" y1="12.7" x2="-22.86" y2="0" width="0.254" layer="94"/>
<wire x1="-22.86" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="27.94" width="0.254" layer="94"/>
<wire x1="0" y1="27.94" x2="-10.16" y2="27.94" width="0.254" layer="94"/>
<wire x1="-10.16" y1="27.94" x2="-22.86" y2="27.94" width="0.254" layer="94"/>
<wire x1="-10.16" y1="27.94" x2="-10.16" y2="12.7" width="0.254" layer="94"/>
<wire x1="-10.16" y1="12.7" x2="-22.86" y2="12.7" width="0.254" layer="94"/>
<pin name="SDI" x="-22.86" y="25.4" length="short" direction="in"/>
<pin name="SCK" x="-22.86" y="22.86" length="short" direction="in"/>
<pin name="CS" x="-22.86" y="20.32" length="short" direction="in"/>
<pin name="LDAC" x="-22.86" y="17.78" length="short" direction="in"/>
<pin name="VDD" x="-7.62" y="27.94" length="short" direction="in" rot="R270"/>
<pin name="V_REF_A" x="-5.08" y="27.94" length="short" direction="in" rot="R270"/>
<pin name="V_REF_B" x="-2.54" y="27.94" length="short" direction="in" rot="R270"/>
<pin name="V_OUT_A" x="0" y="10.16" length="short" direction="in" rot="R180"/>
<pin name="V_OUT_B" x="0" y="5.08" length="short" direction="in" rot="R180"/>
<pin name="VSS" x="-17.78" y="0" length="short" direction="in" rot="R90"/>
<pin name="SHDN" x="-22.86" y="15.24" length="short" direction="in"/>
<text x="-17.78" y="30.48" size="1.27" layer="95" align="center-right">&gt;name</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="MCP4922" urn="urn:adsk.eagle:component:810211/2" library_version="3">
<description>MCP4922 Digital Analog Converter</description>
<gates>
<gate name="G$1" symbol="MCP4922" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SOIC16">
<connects>
<connect gate="G$1" pin="CS" pad="3"/>
<connect gate="G$1" pin="LDAC" pad="8"/>
<connect gate="G$1" pin="SCK" pad="4"/>
<connect gate="G$1" pin="SDI" pad="5"/>
<connect gate="G$1" pin="SHDN" pad="9"/>
<connect gate="G$1" pin="VDD" pad="1"/>
<connect gate="G$1" pin="VSS" pad="12"/>
<connect gate="G$1" pin="V_OUT_A" pad="14"/>
<connect gate="G$1" pin="V_OUT_B" pad="10"/>
<connect gate="G$1" pin="V_REF_A" pad="13"/>
<connect gate="G$1" pin="V_REF_B" pad="11"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:810210/2"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="IN" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="NEUTRIK_NC3FAH" device="" package3d_urn="urn:adsk.eagle:package:705652/7"/>
<part name="U2" library="THAT_Library" library_urn="urn:adsk.eagle:library:704460" deviceset="THAT1240" device="SO8-U" package3d_urn="urn:adsk.eagle:package:704562/2" value="1240"/>
<part name="K1" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="RELAY_EE2-5NU" device="" package3d_urn="urn:adsk.eagle:package:823802/2"/>
<part name="CONTROL" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="10PIN_HEADER_SMD" device="" package3d_urn="urn:adsk.eagle:package:568050/8"/>
<part name="P+1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V+" device="" value="+15V"/>
<part name="P-1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V-" device="" value="-15V"/>
<part name="AGND1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="C3" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="KONDENSATOR_0603" device="" package3d_urn="urn:adsk.eagle:package:576738/2" value="100nF"/>
<part name="C4" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="KONDENSATOR_0603" device="" package3d_urn="urn:adsk.eagle:package:576738/2" value="100nF"/>
<part name="AGND5" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="AGND6" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="D1" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="4148_SOD323" device="" package3d_urn="urn:adsk.eagle:package:578210/2" value="4148"/>
<part name="T1" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="BC847" device="" package3d_urn="urn:adsk.eagle:package:705533/2"/>
<part name="R1" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="10k"/>
<part name="SUPPLY1" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="DGND" device=""/>
<part name="R3" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="10k"/>
<part name="SUPPLY4" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="+5V" device=""/>
<part name="U5" library="THAT_Library" library_urn="urn:adsk.eagle:library:704460" deviceset="THAT2181" device="S" package3d_urn="urn:adsk.eagle:package:704562/2" value="2181"/>
<part name="P+10" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V+" device="" value="+15V"/>
<part name="AGND23" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="C15" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="KONDENSATOR_0603" device="" package3d_urn="urn:adsk.eagle:package:576738/2" value="100nF"/>
<part name="P-8" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V-" device="" value="-15V"/>
<part name="C16" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="KONDENSATOR_0603" device="" package3d_urn="urn:adsk.eagle:package:576738/2" value="100nF"/>
<part name="AGND24" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="R17" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="5k1"/>
<part name="R18" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="680k"/>
<part name="SYM_TRIM" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="R_TRIMMER_SMD" device="" package3d_urn="urn:adsk.eagle:package:708082/2" value="50k"/>
<part name="P+11" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V+" device="" value="+15V"/>
<part name="P-9" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V-" device="" value="-15V"/>
<part name="C17" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="SMD_ELCTROLYTIC" device="" package3d_urn="urn:adsk.eagle:package:577970/2" value="10uF"/>
<part name="R19" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="20k"/>
<part name="IC3" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="OP275" device="" package3d_urn="urn:adsk.eagle:package:705548/2"/>
<part name="R20" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="20k"/>
<part name="C18" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="KONDENSATOR_0603" device="" package3d_urn="urn:adsk.eagle:package:576738/2" value="100nF"/>
<part name="AGND25" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="P+12" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V+" device="" value="+15V"/>
<part name="P-10" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V-" device="" value="-15V"/>
<part name="C19" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="KONDENSATOR_0603" device="" package3d_urn="urn:adsk.eagle:package:576738/2" value="100nF"/>
<part name="AGND26" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="AGND27" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="C20" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="KONDENSATOR_0603" device="" package3d_urn="urn:adsk.eagle:package:576738/2" value="100nF"/>
<part name="U6" library="THAT_Library" library_urn="urn:adsk.eagle:library:704460" deviceset="THAT1646" device="SO8-U" package3d_urn="urn:adsk.eagle:package:704562/2" value="1646"/>
<part name="AGND28" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="C21" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="KONDENSATOR_0603" device="" package3d_urn="urn:adsk.eagle:package:576738/2" value="100nF"/>
<part name="C22" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="KONDENSATOR_0603" device="" package3d_urn="urn:adsk.eagle:package:576738/2" value="100nF"/>
<part name="AGND29" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="AGND30" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="P+13" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V+" device="" value="+15V"/>
<part name="P-11" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V-" device="" value="-15V"/>
<part name="AGND31" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="C23" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="KONDENSATOR_0603" device="" package3d_urn="urn:adsk.eagle:package:576738/2" value="100nF"/>
<part name="AGND32" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="P+14" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V+" device="" value="+15V"/>
<part name="P-12" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V-" device="" value="-15V"/>
<part name="C24" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="KONDENSATOR_0603" device="" package3d_urn="urn:adsk.eagle:package:576738/2" value="100nF"/>
<part name="AGND33" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="R21" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="100k"/>
<part name="R22" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="5k1"/>
<part name="AGND34" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="R23" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="20k"/>
<part name="R24" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="20k"/>
<part name="R25" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="20k"/>
<part name="R26" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="20k"/>
<part name="AGND36" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="EC+_TRIM" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="R_TRIMMER_SMD" device="" package3d_urn="urn:adsk.eagle:package:708082/2" value="2k"/>
<part name="P+15" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V+" device="" value="+15V"/>
<part name="MCP1" library="SPI" library_urn="urn:adsk.eagle:library:750815" deviceset="MCP4922" device="" package3d_urn="urn:adsk.eagle:package:810210/2"/>
<part name="AGND37" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="P+16" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V+" device="" value="+15V"/>
<part name="R27" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="100k"/>
<part name="R28" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="15k"/>
<part name="AGND38" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="U1" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="78**" device="" package3d_urn="urn:adsk.eagle:package:763981/2" value="7805"/>
<part name="AGND7" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="P+3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V+" device="" value="+15V"/>
<part name="C5" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="KONDENSATOR_0603" device="" package3d_urn="urn:adsk.eagle:package:576738/2" value="0.33uF"/>
<part name="C7" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="KONDENSATOR_0603" device="" package3d_urn="urn:adsk.eagle:package:576738/2" value="100nF"/>
<part name="C8" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="KONDENSATOR_0603" device="" package3d_urn="urn:adsk.eagle:package:576738/2" value="100nF"/>
<part name="AGND8" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="C9" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="KONDENSATOR_0603" device="" package3d_urn="urn:adsk.eagle:package:576738/2" value="100nF"/>
<part name="OK1" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="OPTOKOPPLER(4X)" device="" package3d_urn="urn:adsk.eagle:package:763982/2"/>
<part name="R6" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="100k"/>
<part name="R7" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="100k"/>
<part name="R8" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="100k"/>
<part name="AGND9" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="SUPPLY5" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="DGND" device=""/>
<part name="R9" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="220"/>
<part name="R10" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="220"/>
<part name="R11" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="220"/>
<part name="5V_INTERNAL" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="TP" device="THT" package3d_urn="urn:adsk.eagle:package:817866/2"/>
<part name="DIVIDER_VCA" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="TP" device="THT" package3d_urn="urn:adsk.eagle:package:817866/2"/>
<part name="EC+" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="TP" device="THT" package3d_urn="urn:adsk.eagle:package:817866/2"/>
<part name="VREF" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="TP" device="THT" package3d_urn="urn:adsk.eagle:package:817866/2"/>
<part name="V_OUT_A" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="TP" device="THT" package3d_urn="urn:adsk.eagle:package:817866/2"/>
<part name="V_OUT_B" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="TP" device="THT" package3d_urn="urn:adsk.eagle:package:817866/2"/>
<part name="SYM_1" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="TP" device="THT" package3d_urn="urn:adsk.eagle:package:817866/2"/>
<part name="P+4" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V+" device="" value="+15V"/>
<part name="P-3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V-" device="" value="-15V"/>
<part name="C6" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="KONDENSATOR_0603" device="" package3d_urn="urn:adsk.eagle:package:576738/2" value="100nF"/>
<part name="C10" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="KONDENSATOR_0603" device="" package3d_urn="urn:adsk.eagle:package:576738/2" value="100nF"/>
<part name="AGND10" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="AGND11" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="IC2" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="TL072" device="" package3d_urn="urn:adsk.eagle:package:705548/2"/>
<part name="IC1" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="TL072" device="" package3d_urn="urn:adsk.eagle:package:705548/2"/>
<part name="R2" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="160k"/>
<part name="P-2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V-" device="" value="-15V"/>
<part name="R4" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="27k"/>
<part name="OUT" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="NEUTRIK_NC3MAH" device="" package3d_urn="urn:adsk.eagle:package:705585/4"/>
<part name="D2" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="4148_SOD323" device="" package3d_urn="urn:adsk.eagle:package:578210/2" value="4148"/>
<part name="T2" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="BC847" device="" package3d_urn="urn:adsk.eagle:package:705533/2"/>
<part name="R13" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="10k"/>
<part name="SUPPLY2" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="DGND" device=""/>
<part name="R14" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="WIDERSTAND_0805" device="R0805" package3d_urn="urn:adsk.eagle:package:577963/2" value="10k"/>
<part name="SUPPLY3" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="+5V" device=""/>
<part name="K2" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="RELAY_EE2-5NU" device="" package3d_urn="urn:adsk.eagle:package:823802/2"/>
<part name="AGND2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="AGND3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="ANALOG_PCB" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="10PIN_HEADER_SMD" device="" package3d_urn="urn:adsk.eagle:package:568050/8"/>
<part name="P+2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V+" device="" value="+15V"/>
<part name="P-4" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V-" device="" value="-15V"/>
<part name="AGND4" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="SUPPLY6" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="+5V" device=""/>
<part name="SUPPLY7" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="DGND" device=""/>
<part name="P+5" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V+" device="" value="+15V"/>
<part name="P-5" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="V-" device="" value="-15V"/>
<part name="AGND12" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="AGND" device=""/>
<part name="AFTER_VCA" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="TP" device="THT" package3d_urn="urn:adsk.eagle:package:817866/2"/>
<part name="FROM_ANALOG" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="TP" device="THT" package3d_urn="urn:adsk.eagle:package:817866/2"/>
<part name="TO_ANALOG" library="C_Sager_Bibliothek" library_urn="urn:adsk.eagle:library:560098" deviceset="TP" device="THT" package3d_urn="urn:adsk.eagle:package:817866/2"/>
</parts>
<sheets>
<sheet>
<description>Input Section</description>
<plain>
</plain>
<instances>
<instance part="IN" gate="G$1" x="-185.42" y="35.56" rot="R90"/>
<instance part="U2" gate="G$1" x="-111.76" y="33.02"/>
<instance part="K1" gate="1" x="-71.12" y="-2.54"/>
<instance part="K1" gate="2" x="-157.48" y="33.02" rot="R270"/>
<instance part="K1" gate="3" x="-157.48" y="12.7" rot="R270"/>
<instance part="CONTROL" gate="G$1" x="-200.66" y="-15.24" rot="R90"/>
<instance part="P+1" gate="1" x="-111.76" y="50.8"/>
<instance part="P-1" gate="1" x="-111.76" y="15.24"/>
<instance part="AGND1" gate="VR1" x="-106.68" y="15.24"/>
<instance part="C3" gate="G$1" x="-88.9" y="25.4"/>
<instance part="C4" gate="G$1" x="-127" y="12.7"/>
<instance part="AGND5" gate="VR1" x="-88.9" y="15.24"/>
<instance part="AGND6" gate="VR1" x="-127" y="2.54"/>
<instance part="D1" gate="G$1" x="-81.28" y="-2.54" rot="R90"/>
<instance part="T1" gate="G$1" x="-73.66" y="-20.32"/>
<instance part="R1" gate="G$1" x="-81.28" y="-27.94" rot="R90"/>
<instance part="SUPPLY1" gate="G$1" x="-71.12" y="-38.1"/>
<instance part="R3" gate="G$1" x="-91.44" y="-20.32"/>
<instance part="SUPPLY4" gate="+5V" x="-71.12" y="10.16"/>
<instance part="OUT" gate="G$1" x="-129.54" y="-15.24" rot="R270"/>
<instance part="D2" gate="G$1" x="-40.64" y="-2.54" rot="R90"/>
<instance part="T2" gate="G$1" x="-33.02" y="-20.32"/>
<instance part="R13" gate="G$1" x="-40.64" y="-27.94" rot="R90"/>
<instance part="SUPPLY2" gate="G$1" x="-30.48" y="-38.1"/>
<instance part="R14" gate="G$1" x="-50.8" y="-20.32"/>
<instance part="SUPPLY3" gate="+5V" x="-30.48" y="10.16"/>
<instance part="K2" gate="1" x="-30.48" y="-2.54"/>
<instance part="K2" gate="2" x="-139.7" y="-12.7" rot="R90"/>
<instance part="K2" gate="3" x="-139.7" y="-38.1" rot="R90"/>
<instance part="AGND2" gate="VR1" x="-177.8" y="12.7"/>
<instance part="AGND3" gate="VR1" x="-134.62" y="-22.86"/>
<instance part="P+2" gate="1" x="-177.8" y="-27.94"/>
<instance part="P-4" gate="1" x="-231.14" y="-45.72"/>
<instance part="AGND4" gate="VR1" x="-177.8" y="-43.18"/>
<instance part="SUPPLY6" gate="+5V" x="-231.14" y="-7.62"/>
<instance part="SUPPLY7" gate="G$1" x="-172.72" y="-43.18"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="U2" gate="G$1" pin="IN-"/>
<pinref part="K1" gate="2" pin="S"/>
<wire x1="-127" y1="40.64" x2="-152.4" y2="40.64" width="0.1524" layer="91"/>
<wire x1="-152.4" y1="40.64" x2="-152.4" y2="38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="K1" gate="3" pin="S"/>
<wire x1="-152.4" y1="17.78" x2="-152.4" y2="20.32" width="0.1524" layer="91"/>
<wire x1="-152.4" y1="20.32" x2="-132.08" y2="20.32" width="0.1524" layer="91"/>
<wire x1="-132.08" y1="20.32" x2="-132.08" y2="25.4" width="0.1524" layer="91"/>
<pinref part="U2" gate="G$1" pin="IN+"/>
<wire x1="-132.08" y1="25.4" x2="-127" y2="25.4" width="0.1524" layer="91"/>
</segment>
</net>
<net name="TO_ANALOG_PCB" class="0">
<segment>
<pinref part="U2" gate="G$1" pin="OUT"/>
<wire x1="-91.44" y1="33.02" x2="-78.74" y2="33.02" width="0.1524" layer="91"/>
<label x="-71.12" y="33.02" size="1.778" layer="95"/>
<pinref part="U2" gate="G$1" pin="SEN"/>
<wire x1="-78.74" y1="33.02" x2="-71.12" y2="33.02" width="0.1524" layer="91"/>
<wire x1="-106.68" y1="43.18" x2="-106.68" y2="45.72" width="0.1524" layer="91"/>
<wire x1="-106.68" y1="45.72" x2="-78.74" y2="45.72" width="0.1524" layer="91"/>
<wire x1="-78.74" y1="45.72" x2="-78.74" y2="33.02" width="0.1524" layer="91"/>
<junction x="-78.74" y="33.02"/>
</segment>
</net>
<net name="V-" class="0">
<segment>
<pinref part="U2" gate="G$1" pin="V-"/>
<pinref part="P-1" gate="1" pin="V-"/>
<wire x1="-111.76" y1="20.32" x2="-111.76" y2="17.78" width="0.1524" layer="91"/>
<pinref part="C4" gate="G$1" pin="1"/>
<wire x1="-127" y1="15.24" x2="-127" y2="20.32" width="0.1524" layer="91"/>
<wire x1="-127" y1="20.32" x2="-111.76" y2="20.32" width="0.1524" layer="91"/>
<junction x="-111.76" y="20.32"/>
</segment>
<segment>
<pinref part="P-4" gate="1" pin="V-"/>
<wire x1="-231.14" y1="-43.18" x2="-231.14" y2="-38.1" width="0.1524" layer="91"/>
<pinref part="CONTROL" gate="G$1" pin="P$2"/>
<wire x1="-231.14" y1="-38.1" x2="-226.06" y2="-38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="AGND" class="0">
<segment>
<pinref part="U2" gate="G$1" pin="REF"/>
<pinref part="AGND1" gate="VR1" pin="AGND"/>
<wire x1="-106.68" y1="22.86" x2="-106.68" y2="17.78" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="AGND6" gate="VR1" pin="AGND"/>
<pinref part="C4" gate="G$1" pin="2"/>
<wire x1="-127" y1="5.08" x2="-127" y2="7.62" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="C3" gate="G$1" pin="2"/>
<pinref part="AGND5" gate="VR1" pin="AGND"/>
<wire x1="-88.9" y1="20.32" x2="-88.9" y2="17.78" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IN" gate="G$1" pin="1"/>
<pinref part="AGND2" gate="VR1" pin="AGND"/>
<wire x1="-182.88" y1="27.94" x2="-177.8" y2="27.94" width="0.1524" layer="91"/>
<wire x1="-177.8" y1="27.94" x2="-177.8" y2="15.24" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="OUT" gate="G$1" pin="1"/>
<wire x1="-129.54" y1="-7.62" x2="-134.62" y2="-7.62" width="0.1524" layer="91"/>
<pinref part="AGND3" gate="VR1" pin="AGND"/>
<wire x1="-134.62" y1="-7.62" x2="-134.62" y2="-20.32" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="AGND4" gate="VR1" pin="AGND"/>
<wire x1="-177.8" y1="-40.64" x2="-177.8" y2="-38.1" width="0.1524" layer="91"/>
<pinref part="CONTROL" gate="G$1" pin="P$1"/>
<wire x1="-177.8" y1="-38.1" x2="-195.58" y2="-38.1" width="0.1524" layer="91"/>
<wire x1="-195.58" y1="-38.1" x2="-200.66" y2="-38.1" width="0.1524" layer="91"/>
<wire x1="-195.58" y1="-38.1" x2="-195.58" y2="-48.26" width="0.1524" layer="91"/>
<wire x1="-195.58" y1="-48.26" x2="-228.6" y2="-48.26" width="0.1524" layer="91"/>
<junction x="-195.58" y="-38.1"/>
<pinref part="CONTROL" gate="G$1" pin="P$4"/>
<wire x1="-228.6" y1="-48.26" x2="-228.6" y2="-33.02" width="0.1524" layer="91"/>
<wire x1="-228.6" y1="-33.02" x2="-226.06" y2="-33.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="V+" class="0">
<segment>
<pinref part="P+1" gate="1" pin="V+"/>
<pinref part="U2" gate="G$1" pin="V+"/>
<wire x1="-111.76" y1="48.26" x2="-111.76" y2="45.72" width="0.1524" layer="91"/>
<pinref part="C3" gate="G$1" pin="1"/>
<wire x1="-88.9" y1="27.94" x2="-88.9" y2="48.26" width="0.1524" layer="91"/>
<wire x1="-88.9" y1="48.26" x2="-111.76" y2="48.26" width="0.1524" layer="91"/>
<junction x="-111.76" y="48.26"/>
</segment>
<segment>
<pinref part="P+2" gate="1" pin="V+"/>
<wire x1="-177.8" y1="-30.48" x2="-177.8" y2="-33.02" width="0.1524" layer="91"/>
<pinref part="CONTROL" gate="G$1" pin="P$3"/>
<wire x1="-177.8" y1="-33.02" x2="-200.66" y2="-33.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="K1" gate="1" pin="2"/>
<wire x1="-71.12" y1="-7.62" x2="-71.12" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="-71.12" y1="-10.16" x2="-81.28" y2="-10.16" width="0.1524" layer="91"/>
<pinref part="D1" gate="G$1" pin="A"/>
<wire x1="-81.28" y1="-10.16" x2="-81.28" y2="-5.08" width="0.1524" layer="91"/>
<pinref part="T1" gate="G$1" pin="C"/>
<wire x1="-71.12" y1="-10.16" x2="-71.12" y2="-15.24" width="0.1524" layer="91"/>
<junction x="-71.12" y="-10.16"/>
</segment>
</net>
<net name="DGND" class="0">
<segment>
<pinref part="T1" gate="G$1" pin="E"/>
<pinref part="SUPPLY1" gate="G$1" pin="DGND"/>
<wire x1="-71.12" y1="-25.4" x2="-71.12" y2="-35.56" width="0.1524" layer="91"/>
<pinref part="R1" gate="G$1" pin="1"/>
<wire x1="-81.28" y1="-33.02" x2="-81.28" y2="-35.56" width="0.1524" layer="91"/>
<wire x1="-81.28" y1="-35.56" x2="-71.12" y2="-35.56" width="0.1524" layer="91"/>
<junction x="-71.12" y="-35.56"/>
</segment>
<segment>
<pinref part="T2" gate="G$1" pin="E"/>
<pinref part="SUPPLY2" gate="G$1" pin="DGND"/>
<wire x1="-30.48" y1="-25.4" x2="-30.48" y2="-35.56" width="0.1524" layer="91"/>
<pinref part="R13" gate="G$1" pin="1"/>
<wire x1="-40.64" y1="-33.02" x2="-40.64" y2="-35.56" width="0.1524" layer="91"/>
<wire x1="-40.64" y1="-35.56" x2="-30.48" y2="-35.56" width="0.1524" layer="91"/>
<junction x="-30.48" y="-35.56"/>
</segment>
<segment>
<pinref part="SUPPLY7" gate="G$1" pin="DGND"/>
<pinref part="CONTROL" gate="G$1" pin="P$9"/>
<wire x1="-172.72" y1="-40.64" x2="-172.72" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="-172.72" y1="-17.78" x2="-200.66" y2="-17.78" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="R1" gate="G$1" pin="2"/>
<wire x1="-81.28" y1="-22.86" x2="-81.28" y2="-20.32" width="0.1524" layer="91"/>
<pinref part="T1" gate="G$1" pin="B"/>
<wire x1="-81.28" y1="-20.32" x2="-76.2" y2="-20.32" width="0.1524" layer="91"/>
<pinref part="R3" gate="G$1" pin="2"/>
<wire x1="-86.36" y1="-20.32" x2="-81.28" y2="-20.32" width="0.1524" layer="91"/>
<junction x="-81.28" y="-20.32"/>
</segment>
</net>
<net name="+5V" class="0">
<segment>
<pinref part="D1" gate="G$1" pin="C"/>
<wire x1="-81.28" y1="0" x2="-81.28" y2="5.08" width="0.1524" layer="91"/>
<wire x1="-81.28" y1="5.08" x2="-71.12" y2="5.08" width="0.1524" layer="91"/>
<pinref part="K1" gate="1" pin="1"/>
<wire x1="-71.12" y1="5.08" x2="-71.12" y2="2.54" width="0.1524" layer="91"/>
<pinref part="SUPPLY4" gate="+5V" pin="+5V"/>
<wire x1="-71.12" y1="7.62" x2="-71.12" y2="5.08" width="0.1524" layer="91"/>
<junction x="-71.12" y="5.08"/>
</segment>
<segment>
<pinref part="D2" gate="G$1" pin="C"/>
<wire x1="-40.64" y1="0" x2="-40.64" y2="5.08" width="0.1524" layer="91"/>
<wire x1="-40.64" y1="5.08" x2="-30.48" y2="5.08" width="0.1524" layer="91"/>
<wire x1="-30.48" y1="5.08" x2="-30.48" y2="2.54" width="0.1524" layer="91"/>
<pinref part="SUPPLY3" gate="+5V" pin="+5V"/>
<wire x1="-30.48" y1="7.62" x2="-30.48" y2="5.08" width="0.1524" layer="91"/>
<junction x="-30.48" y="5.08"/>
<pinref part="K2" gate="1" pin="1"/>
</segment>
<segment>
<pinref part="CONTROL" gate="G$1" pin="P$10"/>
<wire x1="-226.06" y1="-17.78" x2="-231.14" y2="-17.78" width="0.1524" layer="91"/>
<pinref part="SUPPLY6" gate="+5V" pin="+5V"/>
<wire x1="-231.14" y1="-17.78" x2="-231.14" y2="-10.16" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<wire x1="-30.48" y1="-7.62" x2="-30.48" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="-30.48" y1="-10.16" x2="-40.64" y2="-10.16" width="0.1524" layer="91"/>
<pinref part="D2" gate="G$1" pin="A"/>
<wire x1="-40.64" y1="-10.16" x2="-40.64" y2="-5.08" width="0.1524" layer="91"/>
<pinref part="T2" gate="G$1" pin="C"/>
<wire x1="-30.48" y1="-10.16" x2="-30.48" y2="-15.24" width="0.1524" layer="91"/>
<junction x="-30.48" y="-10.16"/>
<pinref part="K2" gate="1" pin="2"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="R13" gate="G$1" pin="2"/>
<wire x1="-40.64" y1="-22.86" x2="-40.64" y2="-20.32" width="0.1524" layer="91"/>
<pinref part="T2" gate="G$1" pin="B"/>
<wire x1="-40.64" y1="-20.32" x2="-35.56" y2="-20.32" width="0.1524" layer="91"/>
<pinref part="R14" gate="G$1" pin="2"/>
<wire x1="-45.72" y1="-20.32" x2="-40.64" y2="-20.32" width="0.1524" layer="91"/>
<junction x="-40.64" y="-20.32"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="K1" gate="2" pin="O"/>
<wire x1="-152.4" y1="27.94" x2="-152.4" y2="25.4" width="0.1524" layer="91"/>
<wire x1="-152.4" y1="25.4" x2="-144.78" y2="25.4" width="0.1524" layer="91"/>
<pinref part="K2" gate="2" pin="O"/>
<wire x1="-144.78" y1="25.4" x2="-144.78" y2="-7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="K1" gate="3" pin="O"/>
<wire x1="-152.4" y1="7.62" x2="-152.4" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="-152.4" y1="-27.94" x2="-144.78" y2="-27.94" width="0.1524" layer="91"/>
<pinref part="K2" gate="3" pin="O"/>
<wire x1="-144.78" y1="-27.94" x2="-144.78" y2="-33.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="OUT-" class="0">
<segment>
<pinref part="K2" gate="3" pin="S"/>
<wire x1="-144.78" y1="-43.18" x2="-144.78" y2="-48.26" width="0.1524" layer="91"/>
<wire x1="-144.78" y1="-48.26" x2="-160.02" y2="-48.26" width="0.1524" layer="91"/>
<label x="-162.56" y="-48.26" size="1.778" layer="95"/>
</segment>
</net>
<net name="OUT+" class="0">
<segment>
<pinref part="K2" gate="2" pin="S"/>
<wire x1="-144.78" y1="-17.78" x2="-144.78" y2="-20.32" width="0.1524" layer="91"/>
<wire x1="-144.78" y1="-20.32" x2="-160.02" y2="-20.32" width="0.1524" layer="91"/>
<label x="-162.56" y="-20.32" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$21" class="0">
<segment>
<pinref part="K1" gate="3" pin="P"/>
<wire x1="-160.02" y1="12.7" x2="-172.72" y2="12.7" width="0.1524" layer="91"/>
<wire x1="-172.72" y1="12.7" x2="-172.72" y2="30.48" width="0.1524" layer="91"/>
<pinref part="IN" gate="G$1" pin="2"/>
<wire x1="-172.72" y1="30.48" x2="-182.88" y2="30.48" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$22" class="0">
<segment>
<pinref part="IN" gate="G$1" pin="3"/>
<pinref part="K1" gate="2" pin="P"/>
<wire x1="-182.88" y1="33.02" x2="-160.02" y2="33.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$23" class="0">
<segment>
<pinref part="OUT" gate="G$1" pin="2"/>
<wire x1="-129.54" y1="-10.16" x2="-132.08" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="-132.08" y1="-10.16" x2="-132.08" y2="-38.1" width="0.1524" layer="91"/>
<pinref part="K2" gate="3" pin="P"/>
<wire x1="-132.08" y1="-38.1" x2="-137.16" y2="-38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$24" class="0">
<segment>
<pinref part="OUT" gate="G$1" pin="3"/>
<wire x1="-129.54" y1="-12.7" x2="-137.16" y2="-12.7" width="0.1524" layer="91"/>
<pinref part="K2" gate="2" pin="P"/>
</segment>
</net>
<net name="BYPASS" class="0">
<segment>
<pinref part="R3" gate="G$1" pin="1"/>
<wire x1="-96.52" y1="-20.32" x2="-101.6" y2="-20.32" width="0.1524" layer="91"/>
<label x="-109.22" y="-20.32" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="R14" gate="G$1" pin="1"/>
<wire x1="-55.88" y1="-20.32" x2="-60.96" y2="-20.32" width="0.1524" layer="91"/>
<label x="-68.58" y="-20.32" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="CONTROL" gate="G$1" pin="P$7"/>
<wire x1="-200.66" y1="-22.86" x2="-190.5" y2="-22.86" width="0.1524" layer="91"/>
<label x="-198.12" y="-22.86" size="1.778" layer="95"/>
</segment>
</net>
<net name="CS" class="0">
<segment>
<pinref part="CONTROL" gate="G$1" pin="P$5"/>
<wire x1="-200.66" y1="-27.94" x2="-190.5" y2="-27.94" width="0.1524" layer="91"/>
<label x="-198.12" y="-27.94" size="1.778" layer="95"/>
</segment>
</net>
<net name="SDI" class="0">
<segment>
<pinref part="CONTROL" gate="G$1" pin="P$8"/>
<wire x1="-226.06" y1="-22.86" x2="-236.22" y2="-22.86" width="0.1524" layer="91"/>
<label x="-236.22" y="-22.86" size="1.778" layer="95"/>
</segment>
</net>
<net name="SCK" class="0">
<segment>
<pinref part="CONTROL" gate="G$1" pin="P$6"/>
<wire x1="-226.06" y1="-27.94" x2="-236.22" y2="-27.94" width="0.1524" layer="91"/>
<label x="-236.22" y="-27.94" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
<sheet>
<description>Output Section</description>
<plain>
<text x="-40.64" y="30.48" size="1.778" layer="91">THAT2181A</text>
<text x="-107.188" y="64.262" size="1.4224" layer="97">0.7 ... 1 V</text>
<text x="-100.584" y="-28.448" size="1.778" layer="97" rot="R180">1.96 V</text>
<wire x1="-185.42" y1="17.78" x2="-185.42" y2="-68.58" width="0.1524" layer="97" style="dashdot"/>
<wire x1="-185.42" y1="-68.58" x2="-203.2" y2="-83.82" width="0.1524" layer="97" style="dashdot"/>
<wire x1="-185.42" y1="17.78" x2="-203.2" y2="35.56" width="0.1524" layer="97" style="dashdot"/>
<text x="-220.98" y="15.24" size="2.54" layer="97">DIGITAL DOMAIN</text>
<wire x1="-198.12" y1="7.62" x2="-218.44" y2="7.62" width="0.1524" layer="97" style="dashdot"/>
<wire x1="-218.44" y1="7.62" x2="-215.9" y2="10.16" width="0.1524" layer="97" style="dashdot"/>
<wire x1="-215.9" y1="10.16" x2="-213.36" y2="10.16" width="0.1524" layer="97" style="dashdot"/>
<wire x1="-218.44" y1="7.62" x2="-215.9" y2="5.08" width="0.1524" layer="97" style="dashdot"/>
<wire x1="-215.9" y1="5.08" x2="-213.36" y2="5.08" width="0.1524" layer="97" style="dashdot"/>
<wire x1="-203.2" y1="35.56" x2="-213.36" y2="35.56" width="0.1524" layer="97" style="dashdot"/>
<wire x1="-213.36" y1="35.56" x2="-226.06" y2="22.86" width="0.1524" layer="97" style="dashdot"/>
<wire x1="-203.2" y1="-83.82" x2="-213.36" y2="-83.82" width="0.1524" layer="97" style="dashdot"/>
<wire x1="-213.36" y1="-83.82" x2="-223.52" y2="-73.66" width="0.1524" layer="97" style="dashdot"/>
<wire x1="-60.96" y1="-76.2" x2="-60.96" y2="-119.38" width="0.1524" layer="97"/>
<wire x1="-60.96" y1="-119.38" x2="25.4" y2="-119.38" width="0.1524" layer="97"/>
<wire x1="25.4" y1="-119.38" x2="25.4" y2="-76.2" width="0.1524" layer="97"/>
<wire x1="25.4" y1="-76.2" x2="-60.96" y2="-76.2" width="0.1524" layer="97"/>
<text x="-10.16" y="-81.28" size="1.778" layer="97">Symwtrie Varianten</text>
<text x="-10.16" y="-86.36" size="1.778" layer="97">Trimmer:</text>
<text x="5.08" y="-86.36" size="1.778" layer="97">R_TRIM + R18</text>
<text x="-10.16" y="-91.44" size="1.778" layer="97">DA Wandler:</text>
<text x="5.08" y="-91.44" size="1.778" layer="97">R4 + R2</text>
</plain>
<instances>
<instance part="U5" gate="G$1" x="-15.24" y="20.32"/>
<instance part="P+10" gate="1" x="-20.32" y="48.26"/>
<instance part="AGND23" gate="VR1" x="-7.62" y="-15.24"/>
<instance part="C15" gate="G$1" x="-7.62" y="-2.54"/>
<instance part="P-8" gate="1" x="-20.32" y="-15.24"/>
<instance part="C16" gate="G$1" x="2.54" y="38.1"/>
<instance part="AGND24" gate="VR1" x="2.54" y="27.94"/>
<instance part="R17" gate="G$1" x="-20.32" y="-5.08" rot="R90"/>
<instance part="R18" gate="G$1" x="-38.1" y="-96.52"/>
<instance part="SYM_TRIM" gate="G$1" x="-25.4" y="-96.52" rot="R180"/>
<instance part="P+11" gate="1" x="-25.4" y="-86.36"/>
<instance part="P-9" gate="1" x="-25.4" y="-109.22"/>
<instance part="C17" gate="G$1" x="-55.88" y="20.32" rot="MR270"/>
<instance part="R19" gate="G$1" x="-40.64" y="20.32"/>
<instance part="IC3" gate="A" x="53.34" y="58.42"/>
<instance part="IC3" gate="B" x="30.48" y="22.86"/>
<instance part="IC3" gate="P" x="38.1" y="-60.96"/>
<instance part="R20" gate="G$1" x="30.48" y="12.7"/>
<instance part="C18" gate="G$1" x="30.48" y="5.08" rot="R270"/>
<instance part="AGND25" gate="VR1" x="15.24" y="15.24"/>
<instance part="P+12" gate="1" x="38.1" y="-43.18"/>
<instance part="P-10" gate="1" x="38.1" y="-78.74"/>
<instance part="C19" gate="G$1" x="45.72" y="-76.2"/>
<instance part="AGND26" gate="VR1" x="45.72" y="-86.36"/>
<instance part="AGND27" gate="VR1" x="45.72" y="-63.5"/>
<instance part="C20" gate="G$1" x="45.72" y="-53.34"/>
<instance part="U6" gate="G$1" x="81.28" y="20.32"/>
<instance part="AGND28" gate="VR1" x="63.5" y="12.7"/>
<instance part="C21" gate="G$1" x="66.04" y="40.64"/>
<instance part="C22" gate="G$1" x="66.04" y="-2.54"/>
<instance part="AGND29" gate="VR1" x="66.04" y="-12.7"/>
<instance part="AGND30" gate="VR1" x="66.04" y="30.48"/>
<instance part="P+13" gate="1" x="76.2" y="50.8"/>
<instance part="P-11" gate="1" x="76.2" y="-12.7"/>
<instance part="AGND31" gate="VR1" x="5.08" y="-15.24"/>
<instance part="C23" gate="G$1" x="66.04" y="-53.34"/>
<instance part="AGND32" gate="VR1" x="66.04" y="-63.5"/>
<instance part="P+14" gate="1" x="58.42" y="-43.18"/>
<instance part="P-12" gate="1" x="58.42" y="-76.2"/>
<instance part="C24" gate="G$1" x="66.04" y="-76.2"/>
<instance part="AGND33" gate="VR1" x="66.04" y="-86.36"/>
<instance part="R21" gate="G$1" x="-109.22" y="71.12" rot="R90"/>
<instance part="R22" gate="G$1" x="-109.22" y="38.1" rot="R90"/>
<instance part="AGND34" gate="VR1" x="-109.22" y="27.94"/>
<instance part="R23" gate="G$1" x="-68.58" y="60.96"/>
<instance part="R24" gate="G$1" x="-50.8" y="71.12"/>
<instance part="R25" gate="G$1" x="-68.58" y="50.8"/>
<instance part="R26" gate="G$1" x="-60.96" y="43.18" rot="R90"/>
<instance part="AGND36" gate="VR1" x="-60.96" y="33.02"/>
<instance part="EC+_TRIM" gate="G$1" x="-109.22" y="53.34" rot="R180"/>
<instance part="P+15" gate="1" x="-109.22" y="81.28"/>
<instance part="MCP1" gate="G$1" x="-101.6" y="-81.28"/>
<instance part="AGND37" gate="VR1" x="-119.38" y="-91.44"/>
<instance part="P+16" gate="1" x="-93.98" y="-12.7"/>
<instance part="R27" gate="G$1" x="-93.98" y="-22.86" rot="R90"/>
<instance part="R28" gate="G$1" x="-93.98" y="-38.1" rot="R90"/>
<instance part="AGND38" gate="VR1" x="-93.98" y="-50.8"/>
<instance part="U1" gate="G$1" x="-137.16" y="-27.94"/>
<instance part="AGND7" gate="VR1" x="-137.16" y="-45.72"/>
<instance part="P+3" gate="1" x="-154.94" y="-22.86"/>
<instance part="C5" gate="G$1" x="-154.94" y="-33.02"/>
<instance part="C7" gate="G$1" x="-121.92" y="-33.02"/>
<instance part="C8" gate="G$1" x="-35.56" y="50.8"/>
<instance part="AGND8" gate="VR1" x="-35.56" y="40.64"/>
<instance part="C9" gate="G$1" x="-86.36" y="-38.1"/>
<instance part="OK1" gate="A" x="-185.42" y="-40.64"/>
<instance part="OK1" gate="B" x="-185.42" y="-25.4"/>
<instance part="OK1" gate="C" x="-185.42" y="-55.88"/>
<instance part="OK1" gate="D" x="-185.42" y="-10.16"/>
<instance part="R6" gate="G$1" x="-170.18" y="-73.66" rot="R90"/>
<instance part="R7" gate="G$1" x="-162.56" y="-73.66" rot="R90"/>
<instance part="R8" gate="G$1" x="-154.94" y="-73.66" rot="R90"/>
<instance part="AGND9" gate="VR1" x="-170.18" y="-93.98"/>
<instance part="SUPPLY5" gate="G$1" x="-198.12" y="-68.58"/>
<instance part="R9" gate="G$1" x="-208.28" y="-7.62"/>
<instance part="R10" gate="G$1" x="-208.28" y="-22.86"/>
<instance part="R11" gate="G$1" x="-208.28" y="-38.1"/>
<instance part="5V_INTERNAL" gate="G$1" x="-109.22" y="0"/>
<instance part="DIVIDER_VCA" gate="G$1" x="-96.52" y="68.58"/>
<instance part="EC+" gate="G$1" x="-27.94" y="66.04"/>
<instance part="VREF" gate="G$1" x="-86.36" y="-25.4"/>
<instance part="V_OUT_A" gate="G$1" x="-93.98" y="-66.04"/>
<instance part="V_OUT_B" gate="G$1" x="-93.98" y="-81.28" rot="R180"/>
<instance part="SYM_1" gate="G$1" x="-45.72" y="-86.36"/>
<instance part="P+4" gate="1" x="78.74" y="-43.18"/>
<instance part="P-3" gate="1" x="78.74" y="-76.2"/>
<instance part="C6" gate="G$1" x="86.36" y="-76.2"/>
<instance part="C10" gate="G$1" x="86.36" y="-53.34"/>
<instance part="AGND10" gate="VR1" x="86.36" y="-86.36"/>
<instance part="AGND11" gate="VR1" x="86.36" y="-63.5"/>
<instance part="IC2" gate="A" x="-86.36" y="60.96"/>
<instance part="IC2" gate="B" x="-48.26" y="58.42"/>
<instance part="IC2" gate="P" x="58.42" y="-60.96"/>
<instance part="IC1" gate="A" x="-35.56" y="-38.1"/>
<instance part="IC1" gate="B" x="-35.56" y="-60.96"/>
<instance part="IC1" gate="P" x="78.74" y="-60.96"/>
<instance part="R2" gate="G$1" x="-45.72" y="-104.14" rot="R90"/>
<instance part="P-2" gate="1" x="-45.72" y="-114.3"/>
<instance part="R4" gate="G$1" x="-53.34" y="-96.52"/>
<instance part="ANALOG_PCB" gate="G$1" x="137.16" y="-15.24" rot="R90"/>
<instance part="P+5" gate="1" x="144.78" y="-5.08"/>
<instance part="P-5" gate="1" x="104.14" y="-45.72"/>
<instance part="AGND12" gate="VR1" x="142.24" y="-48.26"/>
<instance part="AFTER_VCA" gate="G$1" x="111.76" y="63.5"/>
<instance part="FROM_ANALOG" gate="G$1" x="0" y="-27.94"/>
<instance part="TO_ANALOG" gate="G$1" x="0" y="-50.8"/>
</instances>
<busses>
</busses>
<nets>
<net name="V-" class="0">
<segment>
<pinref part="R17" gate="G$1" pin="1"/>
<pinref part="P-8" gate="1" pin="V-"/>
<wire x1="-20.32" y1="-10.16" x2="-20.32" y2="-12.7" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IC3" gate="P" pin="V-"/>
<pinref part="P-10" gate="1" pin="V-"/>
<wire x1="38.1" y1="-68.58" x2="38.1" y2="-71.12" width="0.1524" layer="91"/>
<pinref part="C19" gate="G$1" pin="1"/>
<wire x1="38.1" y1="-71.12" x2="38.1" y2="-76.2" width="0.1524" layer="91"/>
<wire x1="38.1" y1="-71.12" x2="45.72" y2="-71.12" width="0.1524" layer="91"/>
<wire x1="45.72" y1="-71.12" x2="45.72" y2="-73.66" width="0.1524" layer="91"/>
<junction x="38.1" y="-71.12"/>
</segment>
<segment>
<pinref part="P-11" gate="1" pin="V-"/>
<pinref part="U6" gate="G$1" pin="V-"/>
<wire x1="76.2" y1="-10.16" x2="76.2" y2="2.54" width="0.1524" layer="91"/>
<pinref part="C22" gate="G$1" pin="1"/>
<wire x1="76.2" y1="2.54" x2="76.2" y2="5.08" width="0.1524" layer="91"/>
<wire x1="66.04" y1="0" x2="66.04" y2="2.54" width="0.1524" layer="91"/>
<wire x1="66.04" y1="2.54" x2="76.2" y2="2.54" width="0.1524" layer="91"/>
<junction x="76.2" y="2.54"/>
</segment>
<segment>
<pinref part="P-12" gate="1" pin="V-"/>
<wire x1="58.42" y1="-68.58" x2="58.42" y2="-71.12" width="0.1524" layer="91"/>
<pinref part="C24" gate="G$1" pin="1"/>
<wire x1="58.42" y1="-71.12" x2="58.42" y2="-73.66" width="0.1524" layer="91"/>
<wire x1="66.04" y1="-73.66" x2="66.04" y2="-71.12" width="0.1524" layer="91"/>
<wire x1="66.04" y1="-71.12" x2="58.42" y2="-71.12" width="0.1524" layer="91"/>
<junction x="58.42" y="-71.12"/>
<pinref part="IC2" gate="P" pin="V-"/>
</segment>
<segment>
<pinref part="SYM_TRIM" gate="G$1" pin="3"/>
<pinref part="P-9" gate="1" pin="V-"/>
<wire x1="-25.4" y1="-106.68" x2="-25.4" y2="-101.6" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P-3" gate="1" pin="V-"/>
<wire x1="78.74" y1="-68.58" x2="78.74" y2="-71.12" width="0.1524" layer="91"/>
<pinref part="C6" gate="G$1" pin="1"/>
<wire x1="78.74" y1="-71.12" x2="78.74" y2="-73.66" width="0.1524" layer="91"/>
<wire x1="86.36" y1="-73.66" x2="86.36" y2="-71.12" width="0.1524" layer="91"/>
<wire x1="86.36" y1="-71.12" x2="78.74" y2="-71.12" width="0.1524" layer="91"/>
<junction x="78.74" y="-71.12"/>
<pinref part="IC1" gate="P" pin="V-"/>
</segment>
<segment>
<pinref part="R2" gate="G$1" pin="1"/>
<pinref part="P-2" gate="1" pin="V-"/>
<wire x1="-45.72" y1="-109.22" x2="-45.72" y2="-111.76" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="ANALOG_PCB" gate="G$1" pin="P$2"/>
<wire x1="111.76" y1="-38.1" x2="104.14" y2="-38.1" width="0.1524" layer="91"/>
<pinref part="P-5" gate="1" pin="V-"/>
<wire x1="104.14" y1="-38.1" x2="104.14" y2="-43.18" width="0.1524" layer="91"/>
</segment>
</net>
<net name="AGND" class="0">
<segment>
<pinref part="AGND23" gate="VR1" pin="AGND"/>
<pinref part="C15" gate="G$1" pin="2"/>
<wire x1="-7.62" y1="-12.7" x2="-7.62" y2="-10.16" width="0.1524" layer="91"/>
<pinref part="U5" gate="G$1" pin="GND"/>
<wire x1="-7.62" y1="-10.16" x2="-7.62" y2="-7.62" width="0.1524" layer="91"/>
<wire x1="-15.24" y1="7.62" x2="-15.24" y2="-10.16" width="0.1524" layer="91"/>
<wire x1="-15.24" y1="-10.16" x2="-7.62" y2="-10.16" width="0.1524" layer="91"/>
<junction x="-7.62" y="-10.16"/>
</segment>
<segment>
<pinref part="AGND24" gate="VR1" pin="AGND"/>
<pinref part="C16" gate="G$1" pin="2"/>
<wire x1="2.54" y1="30.48" x2="2.54" y2="33.02" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="AGND25" gate="VR1" pin="AGND"/>
<wire x1="15.24" y1="17.78" x2="15.24" y2="25.4" width="0.1524" layer="91"/>
<pinref part="IC3" gate="B" pin="+IN"/>
<wire x1="15.24" y1="25.4" x2="22.86" y2="25.4" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="C20" gate="G$1" pin="2"/>
<pinref part="AGND27" gate="VR1" pin="AGND"/>
<wire x1="45.72" y1="-58.42" x2="45.72" y2="-60.96" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="C19" gate="G$1" pin="2"/>
<pinref part="AGND26" gate="VR1" pin="AGND"/>
<wire x1="45.72" y1="-81.28" x2="45.72" y2="-83.82" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U6" gate="G$1" pin="GND"/>
<wire x1="66.04" y1="17.78" x2="63.5" y2="17.78" width="0.1524" layer="91"/>
<pinref part="AGND28" gate="VR1" pin="AGND"/>
<wire x1="63.5" y1="17.78" x2="63.5" y2="15.24" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="C21" gate="G$1" pin="2"/>
<pinref part="AGND30" gate="VR1" pin="AGND"/>
<wire x1="66.04" y1="35.56" x2="66.04" y2="33.02" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="AGND29" gate="VR1" pin="AGND"/>
<pinref part="C22" gate="G$1" pin="2"/>
<wire x1="66.04" y1="-10.16" x2="66.04" y2="-7.62" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U5" gate="G$1" pin="EC-"/>
<wire x1="-10.16" y1="10.16" x2="-10.16" y2="7.62" width="0.1524" layer="91"/>
<pinref part="AGND31" gate="VR1" pin="AGND"/>
<wire x1="-10.16" y1="7.62" x2="5.08" y2="7.62" width="0.1524" layer="91"/>
<wire x1="5.08" y1="7.62" x2="5.08" y2="-12.7" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="AGND32" gate="VR1" pin="AGND"/>
<pinref part="C23" gate="G$1" pin="2"/>
<wire x1="66.04" y1="-60.96" x2="66.04" y2="-58.42" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="AGND33" gate="VR1" pin="AGND"/>
<pinref part="C24" gate="G$1" pin="2"/>
<wire x1="66.04" y1="-83.82" x2="66.04" y2="-81.28" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="R22" gate="G$1" pin="1"/>
<pinref part="AGND34" gate="VR1" pin="AGND"/>
<wire x1="-109.22" y1="33.02" x2="-109.22" y2="30.48" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="AGND36" gate="VR1" pin="AGND"/>
<pinref part="R26" gate="G$1" pin="1"/>
<wire x1="-60.96" y1="35.56" x2="-60.96" y2="38.1" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="MCP1" gate="G$1" pin="VSS"/>
<pinref part="AGND37" gate="VR1" pin="AGND"/>
<wire x1="-119.38" y1="-81.28" x2="-119.38" y2="-83.82" width="0.1524" layer="91"/>
<pinref part="MCP1" gate="G$1" pin="LDAC"/>
<wire x1="-119.38" y1="-83.82" x2="-119.38" y2="-88.9" width="0.1524" layer="91"/>
<wire x1="-124.46" y1="-63.5" x2="-129.54" y2="-63.5" width="0.1524" layer="91"/>
<wire x1="-129.54" y1="-63.5" x2="-129.54" y2="-83.82" width="0.1524" layer="91"/>
<wire x1="-129.54" y1="-83.82" x2="-119.38" y2="-83.82" width="0.1524" layer="91"/>
<junction x="-119.38" y="-83.82"/>
</segment>
<segment>
<pinref part="AGND38" gate="VR1" pin="AGND"/>
<pinref part="R28" gate="G$1" pin="1"/>
<wire x1="-93.98" y1="-48.26" x2="-93.98" y2="-45.72" width="0.1524" layer="91"/>
<pinref part="C9" gate="G$1" pin="2"/>
<wire x1="-93.98" y1="-45.72" x2="-93.98" y2="-43.18" width="0.1524" layer="91"/>
<wire x1="-86.36" y1="-43.18" x2="-86.36" y2="-45.72" width="0.1524" layer="91"/>
<wire x1="-86.36" y1="-45.72" x2="-93.98" y2="-45.72" width="0.1524" layer="91"/>
<junction x="-93.98" y="-45.72"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="GND"/>
<pinref part="AGND7" gate="VR1" pin="AGND"/>
<wire x1="-137.16" y1="-35.56" x2="-137.16" y2="-40.64" width="0.1524" layer="91"/>
<wire x1="-137.16" y1="-40.64" x2="-137.16" y2="-43.18" width="0.1524" layer="91"/>
<junction x="-137.16" y="-40.64"/>
<pinref part="C5" gate="G$1" pin="2"/>
<wire x1="-154.94" y1="-38.1" x2="-154.94" y2="-40.64" width="0.1524" layer="91"/>
<wire x1="-154.94" y1="-40.64" x2="-137.16" y2="-40.64" width="0.1524" layer="91"/>
<pinref part="C7" gate="G$1" pin="2"/>
<wire x1="-121.92" y1="-38.1" x2="-121.92" y2="-40.64" width="0.1524" layer="91"/>
<wire x1="-121.92" y1="-40.64" x2="-137.16" y2="-40.64" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="AGND8" gate="VR1" pin="AGND"/>
<pinref part="C8" gate="G$1" pin="2"/>
<wire x1="-35.56" y1="43.18" x2="-35.56" y2="45.72" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="AGND9" gate="VR1" pin="AGND"/>
<wire x1="-170.18" y1="-91.44" x2="-170.18" y2="-81.28" width="0.1524" layer="91"/>
<pinref part="R6" gate="G$1" pin="1"/>
<wire x1="-170.18" y1="-78.74" x2="-170.18" y2="-81.28" width="0.1524" layer="91"/>
<pinref part="R7" gate="G$1" pin="1"/>
<wire x1="-162.56" y1="-78.74" x2="-162.56" y2="-81.28" width="0.1524" layer="91"/>
<wire x1="-162.56" y1="-81.28" x2="-170.18" y2="-81.28" width="0.1524" layer="91"/>
<junction x="-170.18" y="-81.28"/>
<pinref part="R8" gate="G$1" pin="1"/>
<wire x1="-154.94" y1="-78.74" x2="-154.94" y2="-81.28" width="0.1524" layer="91"/>
<wire x1="-154.94" y1="-81.28" x2="-162.56" y2="-81.28" width="0.1524" layer="91"/>
<junction x="-162.56" y="-81.28"/>
</segment>
<segment>
<pinref part="C6" gate="G$1" pin="2"/>
<pinref part="AGND10" gate="VR1" pin="AGND"/>
<wire x1="86.36" y1="-81.28" x2="86.36" y2="-83.82" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="AGND11" gate="VR1" pin="AGND"/>
<pinref part="C10" gate="G$1" pin="2"/>
<wire x1="86.36" y1="-60.96" x2="86.36" y2="-58.42" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="ANALOG_PCB" gate="G$1" pin="P$1"/>
<wire x1="137.16" y1="-38.1" x2="142.24" y2="-38.1" width="0.1524" layer="91"/>
<pinref part="AGND12" gate="VR1" pin="AGND"/>
<wire x1="142.24" y1="-38.1" x2="142.24" y2="-45.72" width="0.1524" layer="91"/>
<pinref part="ANALOG_PCB" gate="G$1" pin="P$5"/>
<wire x1="137.16" y1="-27.94" x2="142.24" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="142.24" y1="-27.94" x2="142.24" y2="-38.1" width="0.1524" layer="91"/>
<junction x="142.24" y="-38.1"/>
<pinref part="ANALOG_PCB" gate="G$1" pin="P$7"/>
<wire x1="137.16" y1="-22.86" x2="142.24" y2="-22.86" width="0.1524" layer="91"/>
<wire x1="142.24" y1="-22.86" x2="142.24" y2="-27.94" width="0.1524" layer="91"/>
<junction x="142.24" y="-27.94"/>
<pinref part="ANALOG_PCB" gate="G$1" pin="P$9"/>
<wire x1="137.16" y1="-17.78" x2="142.24" y2="-17.78" width="0.1524" layer="91"/>
<wire x1="142.24" y1="-17.78" x2="142.24" y2="-22.86" width="0.1524" layer="91"/>
<junction x="142.24" y="-22.86"/>
</segment>
</net>
<net name="V+" class="0">
<segment>
<pinref part="P+10" gate="1" pin="V+"/>
<pinref part="U5" gate="G$1" pin="V+"/>
<wire x1="-20.32" y1="45.72" x2="-20.32" y2="43.18" width="0.1524" layer="91"/>
<pinref part="C16" gate="G$1" pin="1"/>
<wire x1="-20.32" y1="43.18" x2="-20.32" y2="35.56" width="0.1524" layer="91"/>
<wire x1="2.54" y1="40.64" x2="2.54" y2="43.18" width="0.1524" layer="91"/>
<wire x1="2.54" y1="43.18" x2="-20.32" y2="43.18" width="0.1524" layer="91"/>
<junction x="-20.32" y="43.18"/>
</segment>
<segment>
<pinref part="P+12" gate="1" pin="V+"/>
<pinref part="IC3" gate="P" pin="V+"/>
<wire x1="38.1" y1="-45.72" x2="38.1" y2="-48.26" width="0.1524" layer="91"/>
<pinref part="C20" gate="G$1" pin="1"/>
<wire x1="38.1" y1="-48.26" x2="38.1" y2="-53.34" width="0.1524" layer="91"/>
<wire x1="45.72" y1="-50.8" x2="45.72" y2="-48.26" width="0.1524" layer="91"/>
<wire x1="45.72" y1="-48.26" x2="38.1" y2="-48.26" width="0.1524" layer="91"/>
<junction x="38.1" y="-48.26"/>
</segment>
<segment>
<pinref part="P+13" gate="1" pin="V+"/>
<pinref part="U6" gate="G$1" pin="V+"/>
<wire x1="76.2" y1="48.26" x2="76.2" y2="45.72" width="0.1524" layer="91"/>
<pinref part="C21" gate="G$1" pin="1"/>
<wire x1="76.2" y1="45.72" x2="76.2" y2="35.56" width="0.1524" layer="91"/>
<wire x1="66.04" y1="43.18" x2="66.04" y2="45.72" width="0.1524" layer="91"/>
<wire x1="66.04" y1="45.72" x2="76.2" y2="45.72" width="0.1524" layer="91"/>
<junction x="76.2" y="45.72"/>
</segment>
<segment>
<pinref part="P+14" gate="1" pin="V+"/>
<wire x1="58.42" y1="-45.72" x2="58.42" y2="-48.26" width="0.1524" layer="91"/>
<pinref part="C23" gate="G$1" pin="1"/>
<wire x1="58.42" y1="-48.26" x2="58.42" y2="-53.34" width="0.1524" layer="91"/>
<wire x1="66.04" y1="-50.8" x2="66.04" y2="-48.26" width="0.1524" layer="91"/>
<wire x1="66.04" y1="-48.26" x2="58.42" y2="-48.26" width="0.1524" layer="91"/>
<junction x="58.42" y="-48.26"/>
<pinref part="IC2" gate="P" pin="V+"/>
</segment>
<segment>
<pinref part="P+15" gate="1" pin="V+"/>
<pinref part="R21" gate="G$1" pin="2"/>
<wire x1="-109.22" y1="78.74" x2="-109.22" y2="76.2" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="R27" gate="G$1" pin="2"/>
<pinref part="P+16" gate="1" pin="V+"/>
<wire x1="-93.98" y1="-17.78" x2="-93.98" y2="-15.24" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="SYM_TRIM" gate="G$1" pin="1"/>
<pinref part="P+11" gate="1" pin="V+"/>
<wire x1="-25.4" y1="-91.44" x2="-25.4" y2="-88.9" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P+3" gate="1" pin="V+"/>
<wire x1="-154.94" y1="-25.4" x2="-154.94" y2="-27.94" width="0.1524" layer="91"/>
<pinref part="U1" gate="G$1" pin="VI"/>
<wire x1="-154.94" y1="-27.94" x2="-147.32" y2="-27.94" width="0.1524" layer="91"/>
<pinref part="C5" gate="G$1" pin="1"/>
<wire x1="-154.94" y1="-30.48" x2="-154.94" y2="-27.94" width="0.1524" layer="91"/>
<junction x="-154.94" y="-27.94"/>
</segment>
<segment>
<pinref part="P+4" gate="1" pin="V+"/>
<wire x1="78.74" y1="-45.72" x2="78.74" y2="-48.26" width="0.1524" layer="91"/>
<pinref part="C10" gate="G$1" pin="1"/>
<wire x1="78.74" y1="-48.26" x2="78.74" y2="-53.34" width="0.1524" layer="91"/>
<wire x1="86.36" y1="-50.8" x2="86.36" y2="-48.26" width="0.1524" layer="91"/>
<wire x1="86.36" y1="-48.26" x2="78.74" y2="-48.26" width="0.1524" layer="91"/>
<junction x="78.74" y="-48.26"/>
<pinref part="IC1" gate="P" pin="V+"/>
</segment>
<segment>
<pinref part="ANALOG_PCB" gate="G$1" pin="P$3"/>
<wire x1="137.16" y1="-33.02" x2="144.78" y2="-33.02" width="0.1524" layer="91"/>
<pinref part="P+5" gate="1" pin="V+"/>
<wire x1="144.78" y1="-33.02" x2="144.78" y2="-7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$26" class="0">
<segment>
<pinref part="C15" gate="G$1" pin="1"/>
<wire x1="-7.62" y1="0" x2="-7.62" y2="2.54" width="0.1524" layer="91"/>
<wire x1="-7.62" y1="2.54" x2="-20.32" y2="2.54" width="0.1524" layer="91"/>
<pinref part="U5" gate="G$1" pin="V-"/>
<wire x1="-20.32" y1="2.54" x2="-20.32" y2="5.08" width="0.1524" layer="91"/>
<pinref part="R17" gate="G$1" pin="2"/>
<wire x1="-20.32" y1="0" x2="-20.32" y2="2.54" width="0.1524" layer="91"/>
<junction x="-20.32" y="2.54"/>
</segment>
</net>
<net name="N$29" class="0">
<segment>
<pinref part="U5" gate="G$1" pin="OUT"/>
<pinref part="IC3" gate="B" pin="-IN"/>
<wire x1="5.08" y1="20.32" x2="17.78" y2="20.32" width="0.1524" layer="91"/>
<pinref part="R20" gate="G$1" pin="1"/>
<wire x1="17.78" y1="20.32" x2="22.86" y2="20.32" width="0.1524" layer="91"/>
<wire x1="25.4" y1="12.7" x2="17.78" y2="12.7" width="0.1524" layer="91"/>
<wire x1="17.78" y1="12.7" x2="17.78" y2="20.32" width="0.1524" layer="91"/>
<junction x="17.78" y="20.32"/>
<pinref part="C18" gate="G$1" pin="2"/>
<wire x1="25.4" y1="5.08" x2="17.78" y2="5.08" width="0.1524" layer="91"/>
<wire x1="17.78" y1="5.08" x2="17.78" y2="12.7" width="0.1524" layer="91"/>
<junction x="17.78" y="12.7"/>
</segment>
</net>
<net name="N$30" class="0">
<segment>
<pinref part="IC3" gate="B" pin="OUT"/>
<wire x1="38.1" y1="22.86" x2="40.64" y2="22.86" width="0.1524" layer="91"/>
<wire x1="40.64" y1="22.86" x2="40.64" y2="12.7" width="0.1524" layer="91"/>
<pinref part="R20" gate="G$1" pin="2"/>
<wire x1="40.64" y1="12.7" x2="35.56" y2="12.7" width="0.1524" layer="91"/>
<pinref part="C18" gate="G$1" pin="1"/>
<wire x1="33.02" y1="5.08" x2="40.64" y2="5.08" width="0.1524" layer="91"/>
<wire x1="40.64" y1="5.08" x2="40.64" y2="12.7" width="0.1524" layer="91"/>
<junction x="40.64" y="12.7"/>
<pinref part="U6" gate="G$1" pin="IN"/>
<wire x1="66.04" y1="22.86" x2="40.64" y2="22.86" width="0.1524" layer="91"/>
<junction x="40.64" y="22.86"/>
<pinref part="IC3" gate="A" pin="+IN"/>
<wire x1="45.72" y1="60.96" x2="40.64" y2="60.96" width="0.1524" layer="91"/>
<wire x1="40.64" y1="60.96" x2="40.64" y2="22.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="OUT+" class="0">
<segment>
<pinref part="U6" gate="G$1" pin="OUT+"/>
<wire x1="101.6" y1="25.4" x2="109.22" y2="25.4" width="0.1524" layer="91"/>
<pinref part="U6" gate="G$1" pin="SEN+"/>
<wire x1="109.22" y1="25.4" x2="124.46" y2="25.4" width="0.1524" layer="91"/>
<wire x1="81.28" y1="33.02" x2="81.28" y2="35.56" width="0.1524" layer="91"/>
<wire x1="81.28" y1="35.56" x2="109.22" y2="35.56" width="0.1524" layer="91"/>
<wire x1="109.22" y1="35.56" x2="109.22" y2="25.4" width="0.1524" layer="91"/>
<junction x="109.22" y="25.4"/>
<label x="116.84" y="25.4" size="1.778" layer="95"/>
</segment>
</net>
<net name="OUT-" class="0">
<segment>
<pinref part="U6" gate="G$1" pin="OUT-"/>
<wire x1="101.6" y1="15.24" x2="109.22" y2="15.24" width="0.1524" layer="91"/>
<wire x1="109.22" y1="15.24" x2="124.46" y2="15.24" width="0.1524" layer="91"/>
<pinref part="U6" gate="G$1" pin="SEN-"/>
<wire x1="81.28" y1="7.62" x2="81.28" y2="5.08" width="0.1524" layer="91"/>
<wire x1="81.28" y1="5.08" x2="109.22" y2="5.08" width="0.1524" layer="91"/>
<wire x1="109.22" y1="5.08" x2="109.22" y2="15.24" width="0.1524" layer="91"/>
<junction x="109.22" y="15.24"/>
<label x="116.84" y="15.24" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$34" class="0">
<segment>
<pinref part="R19" gate="G$1" pin="2"/>
<pinref part="U5" gate="G$1" pin="IN"/>
<wire x1="-35.56" y1="20.32" x2="-30.48" y2="20.32" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$35" class="0">
<segment>
<pinref part="R21" gate="G$1" pin="1"/>
<wire x1="-109.22" y1="66.04" x2="-109.22" y2="63.5" width="0.1524" layer="91"/>
<wire x1="-93.98" y1="63.5" x2="-96.52" y2="63.5" width="0.1524" layer="91"/>
<pinref part="EC+_TRIM" gate="G$1" pin="1"/>
<wire x1="-96.52" y1="63.5" x2="-109.22" y2="63.5" width="0.1524" layer="91"/>
<wire x1="-109.22" y1="58.42" x2="-109.22" y2="63.5" width="0.1524" layer="91"/>
<junction x="-109.22" y="63.5"/>
<pinref part="DIVIDER_VCA" gate="G$1" pin="TP"/>
<wire x1="-96.52" y1="66.04" x2="-96.52" y2="63.5" width="0.1524" layer="91"/>
<junction x="-96.52" y="63.5"/>
<pinref part="IC2" gate="A" pin="+IN"/>
</segment>
</net>
<net name="N$36" class="0">
<segment>
<wire x1="-93.98" y1="58.42" x2="-96.52" y2="58.42" width="0.1524" layer="91"/>
<wire x1="-96.52" y1="58.42" x2="-96.52" y2="53.34" width="0.1524" layer="91"/>
<wire x1="-96.52" y1="53.34" x2="-76.2" y2="53.34" width="0.1524" layer="91"/>
<wire x1="-76.2" y1="53.34" x2="-76.2" y2="60.96" width="0.1524" layer="91"/>
<wire x1="-76.2" y1="60.96" x2="-78.74" y2="60.96" width="0.1524" layer="91"/>
<pinref part="R23" gate="G$1" pin="1"/>
<wire x1="-76.2" y1="60.96" x2="-73.66" y2="60.96" width="0.1524" layer="91"/>
<junction x="-76.2" y="60.96"/>
<pinref part="IC2" gate="A" pin="-IN"/>
<pinref part="IC2" gate="A" pin="OUT"/>
</segment>
</net>
<net name="N$37" class="0">
<segment>
<pinref part="R23" gate="G$1" pin="2"/>
<wire x1="-63.5" y1="60.96" x2="-60.96" y2="60.96" width="0.1524" layer="91"/>
<pinref part="R24" gate="G$1" pin="1"/>
<wire x1="-60.96" y1="60.96" x2="-55.88" y2="60.96" width="0.1524" layer="91"/>
<wire x1="-55.88" y1="71.12" x2="-60.96" y2="71.12" width="0.1524" layer="91"/>
<wire x1="-60.96" y1="71.12" x2="-60.96" y2="60.96" width="0.1524" layer="91"/>
<junction x="-60.96" y="60.96"/>
<pinref part="IC2" gate="B" pin="+IN"/>
</segment>
</net>
<net name="N$38" class="0">
<segment>
<wire x1="-40.64" y1="58.42" x2="-35.56" y2="58.42" width="0.1524" layer="91"/>
<pinref part="R24" gate="G$1" pin="2"/>
<wire x1="-45.72" y1="71.12" x2="-35.56" y2="71.12" width="0.1524" layer="91"/>
<wire x1="-35.56" y1="71.12" x2="-35.56" y2="58.42" width="0.1524" layer="91"/>
<pinref part="U5" gate="G$1" pin="EC+"/>
<wire x1="-10.16" y1="30.48" x2="-10.16" y2="58.42" width="0.1524" layer="91"/>
<wire x1="-10.16" y1="58.42" x2="-27.94" y2="58.42" width="0.1524" layer="91"/>
<junction x="-35.56" y="58.42"/>
<pinref part="C8" gate="G$1" pin="1"/>
<wire x1="-27.94" y1="58.42" x2="-35.56" y2="58.42" width="0.1524" layer="91"/>
<wire x1="-35.56" y1="53.34" x2="-35.56" y2="58.42" width="0.1524" layer="91"/>
<pinref part="EC+" gate="G$1" pin="TP"/>
<wire x1="-27.94" y1="63.5" x2="-27.94" y2="58.42" width="0.1524" layer="91"/>
<junction x="-27.94" y="58.42"/>
<pinref part="IC2" gate="B" pin="OUT"/>
</segment>
</net>
<net name="N$39" class="0">
<segment>
<pinref part="R25" gate="G$1" pin="2"/>
<wire x1="-63.5" y1="50.8" x2="-60.96" y2="50.8" width="0.1524" layer="91"/>
<wire x1="-60.96" y1="50.8" x2="-60.96" y2="55.88" width="0.1524" layer="91"/>
<wire x1="-60.96" y1="55.88" x2="-55.88" y2="55.88" width="0.1524" layer="91"/>
<pinref part="R26" gate="G$1" pin="2"/>
<wire x1="-60.96" y1="48.26" x2="-60.96" y2="50.8" width="0.1524" layer="91"/>
<junction x="-60.96" y="50.8"/>
<pinref part="IC2" gate="B" pin="-IN"/>
</segment>
</net>
<net name="N$40" class="0">
<segment>
<pinref part="R22" gate="G$1" pin="2"/>
<pinref part="EC+_TRIM" gate="G$1" pin="3"/>
<wire x1="-109.22" y1="43.18" x2="-109.22" y2="45.72" width="0.1524" layer="91"/>
<wire x1="-109.22" y1="45.72" x2="-109.22" y2="48.26" width="0.1524" layer="91"/>
<wire x1="-109.22" y1="45.72" x2="-116.84" y2="45.72" width="0.1524" layer="91"/>
<junction x="-109.22" y="45.72"/>
<pinref part="EC+_TRIM" gate="G$1" pin="2"/>
<wire x1="-116.84" y1="45.72" x2="-116.84" y2="53.34" width="0.1524" layer="91"/>
<wire x1="-116.84" y1="53.34" x2="-114.3" y2="53.34" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$41" class="0">
<segment>
<pinref part="MCP1" gate="G$1" pin="V_OUT_A"/>
<wire x1="-101.6" y1="-71.12" x2="-93.98" y2="-71.12" width="0.1524" layer="91"/>
<wire x1="-93.98" y1="-71.12" x2="-76.2" y2="-71.12" width="0.1524" layer="91"/>
<wire x1="-76.2" y1="-71.12" x2="-76.2" y2="50.8" width="0.1524" layer="91"/>
<pinref part="R25" gate="G$1" pin="1"/>
<wire x1="-76.2" y1="50.8" x2="-73.66" y2="50.8" width="0.1524" layer="91"/>
<pinref part="V_OUT_A" gate="G$1" pin="TP"/>
<wire x1="-93.98" y1="-68.58" x2="-93.98" y2="-71.12" width="0.1524" layer="91"/>
<junction x="-93.98" y="-71.12"/>
</segment>
</net>
<net name="N$42" class="0">
<segment>
<pinref part="R27" gate="G$1" pin="1"/>
<wire x1="-106.68" y1="-30.48" x2="-104.14" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="-104.14" y1="-30.48" x2="-93.98" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="-93.98" y1="-30.48" x2="-93.98" y2="-27.94" width="0.1524" layer="91"/>
<pinref part="R28" gate="G$1" pin="2"/>
<wire x1="-93.98" y1="-30.48" x2="-93.98" y2="-33.02" width="0.1524" layer="91"/>
<junction x="-93.98" y="-30.48"/>
<pinref part="MCP1" gate="G$1" pin="V_REF_A"/>
<wire x1="-106.68" y1="-53.34" x2="-106.68" y2="-30.48" width="0.1524" layer="91"/>
<pinref part="MCP1" gate="G$1" pin="V_REF_B"/>
<wire x1="-104.14" y1="-53.34" x2="-104.14" y2="-30.48" width="0.1524" layer="91"/>
<junction x="-104.14" y="-30.48"/>
<pinref part="C9" gate="G$1" pin="1"/>
<wire x1="-93.98" y1="-30.48" x2="-86.36" y2="-30.48" width="0.1524" layer="91"/>
<wire x1="-86.36" y1="-30.48" x2="-86.36" y2="-35.56" width="0.1524" layer="91"/>
<pinref part="VREF" gate="G$1" pin="TP"/>
<wire x1="-86.36" y1="-27.94" x2="-86.36" y2="-30.48" width="0.1524" layer="91"/>
<junction x="-86.36" y="-30.48"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="C17" gate="G$1" pin="-"/>
<pinref part="R19" gate="G$1" pin="1"/>
<wire x1="-50.8" y1="20.32" x2="-45.72" y2="20.32" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="OK1" gate="B" pin="EMIT"/>
<wire x1="-177.8" y1="-27.94" x2="-167.64" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="-167.64" y1="-27.94" x2="-167.64" y2="-58.42" width="0.1524" layer="91"/>
<pinref part="MCP1" gate="G$1" pin="SCK"/>
<wire x1="-167.64" y1="-58.42" x2="-162.56" y2="-58.42" width="0.1524" layer="91"/>
<pinref part="R7" gate="G$1" pin="2"/>
<wire x1="-162.56" y1="-58.42" x2="-124.46" y2="-58.42" width="0.1524" layer="91"/>
<wire x1="-162.56" y1="-68.58" x2="-162.56" y2="-58.42" width="0.1524" layer="91"/>
<junction x="-162.56" y="-58.42"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<pinref part="OK1" gate="D" pin="EMIT"/>
<wire x1="-177.8" y1="-12.7" x2="-165.1" y2="-12.7" width="0.1524" layer="91"/>
<wire x1="-165.1" y1="-12.7" x2="-165.1" y2="-55.88" width="0.1524" layer="91"/>
<pinref part="MCP1" gate="G$1" pin="SDI"/>
<wire x1="-165.1" y1="-55.88" x2="-154.94" y2="-55.88" width="0.1524" layer="91"/>
<pinref part="R8" gate="G$1" pin="2"/>
<wire x1="-154.94" y1="-55.88" x2="-124.46" y2="-55.88" width="0.1524" layer="91"/>
<wire x1="-154.94" y1="-68.58" x2="-154.94" y2="-55.88" width="0.1524" layer="91"/>
<junction x="-154.94" y="-55.88"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="OK1" gate="A" pin="EMIT"/>
<wire x1="-177.8" y1="-43.18" x2="-170.18" y2="-43.18" width="0.1524" layer="91"/>
<wire x1="-170.18" y1="-43.18" x2="-170.18" y2="-60.96" width="0.1524" layer="91"/>
<pinref part="MCP1" gate="G$1" pin="CS"/>
<pinref part="R6" gate="G$1" pin="2"/>
<wire x1="-170.18" y1="-60.96" x2="-124.46" y2="-60.96" width="0.1524" layer="91"/>
<wire x1="-170.18" y1="-68.58" x2="-170.18" y2="-60.96" width="0.1524" layer="91"/>
<junction x="-170.18" y="-60.96"/>
</segment>
</net>
<net name="5VREG." class="0">
<segment>
<pinref part="OK1" gate="D" pin="COL"/>
<wire x1="-177.8" y1="-7.62" x2="-172.72" y2="-7.62" width="0.1524" layer="91"/>
<wire x1="-172.72" y1="-7.62" x2="-172.72" y2="-22.86" width="0.1524" layer="91"/>
<pinref part="OK1" gate="B" pin="COL"/>
<wire x1="-172.72" y1="-22.86" x2="-177.8" y2="-22.86" width="0.1524" layer="91"/>
<wire x1="-172.72" y1="-22.86" x2="-172.72" y2="-38.1" width="0.1524" layer="91"/>
<junction x="-172.72" y="-22.86"/>
<pinref part="OK1" gate="A" pin="COL"/>
<wire x1="-177.8" y1="-38.1" x2="-172.72" y2="-38.1" width="0.1524" layer="91"/>
<junction x="-172.72" y="-7.62"/>
<pinref part="MCP1" gate="G$1" pin="VDD"/>
<wire x1="-109.22" y1="-7.62" x2="-109.22" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="-109.22" y1="-27.94" x2="-109.22" y2="-48.26" width="0.1524" layer="91"/>
<wire x1="-109.22" y1="-48.26" x2="-109.22" y2="-53.34" width="0.1524" layer="91"/>
<wire x1="-172.72" y1="-7.62" x2="-109.22" y2="-7.62" width="0.1524" layer="91"/>
<junction x="-109.22" y="-7.62"/>
<pinref part="5V_INTERNAL" gate="G$1" pin="TP"/>
<wire x1="-109.22" y1="-2.54" x2="-109.22" y2="-7.62" width="0.1524" layer="91"/>
<junction x="-109.22" y="-7.62"/>
<pinref part="U1" gate="G$1" pin="VO"/>
<wire x1="-127" y1="-27.94" x2="-121.92" y2="-27.94" width="0.1524" layer="91"/>
<pinref part="C7" gate="G$1" pin="1"/>
<wire x1="-121.92" y1="-30.48" x2="-121.92" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="-109.22" y1="-27.94" x2="-121.92" y2="-27.94" width="0.1524" layer="91"/>
<junction x="-109.22" y="-27.94"/>
<junction x="-121.92" y="-27.94"/>
<pinref part="MCP1" gate="G$1" pin="SHDN"/>
<wire x1="-124.46" y1="-66.04" x2="-127" y2="-66.04" width="0.1524" layer="91"/>
<wire x1="-127" y1="-66.04" x2="-127" y2="-48.26" width="0.1524" layer="91"/>
<wire x1="-127" y1="-48.26" x2="-109.22" y2="-48.26" width="0.1524" layer="91"/>
<junction x="-109.22" y="-48.26"/>
<label x="-127" y="-27.94" size="1.778" layer="95"/>
</segment>
</net>
<net name="DGND" class="0">
<segment>
<pinref part="SUPPLY5" gate="G$1" pin="DGND"/>
<pinref part="OK1" gate="A" pin="C"/>
<wire x1="-195.58" y1="-43.18" x2="-198.12" y2="-43.18" width="0.1524" layer="91"/>
<wire x1="-198.12" y1="-43.18" x2="-198.12" y2="-66.04" width="0.1524" layer="91"/>
<pinref part="OK1" gate="B" pin="C"/>
<wire x1="-195.58" y1="-27.94" x2="-198.12" y2="-27.94" width="0.1524" layer="91"/>
<wire x1="-198.12" y1="-27.94" x2="-198.12" y2="-43.18" width="0.1524" layer="91"/>
<junction x="-198.12" y="-43.18"/>
<pinref part="OK1" gate="D" pin="C"/>
<wire x1="-195.58" y1="-12.7" x2="-198.12" y2="-12.7" width="0.1524" layer="91"/>
<wire x1="-198.12" y1="-12.7" x2="-198.12" y2="-27.94" width="0.1524" layer="91"/>
<junction x="-198.12" y="-27.94"/>
</segment>
</net>
<net name="N$15" class="0">
<segment>
<pinref part="R9" gate="G$1" pin="2"/>
<pinref part="OK1" gate="D" pin="A"/>
<wire x1="-203.2" y1="-7.62" x2="-195.58" y2="-7.62" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$16" class="0">
<segment>
<pinref part="OK1" gate="B" pin="A"/>
<pinref part="R10" gate="G$1" pin="2"/>
<wire x1="-195.58" y1="-22.86" x2="-203.2" y2="-22.86" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<pinref part="R11" gate="G$1" pin="2"/>
<pinref part="OK1" gate="A" pin="A"/>
<wire x1="-203.2" y1="-38.1" x2="-195.58" y2="-38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="FROM_ANALOG_PCB" class="0">
<segment>
<pinref part="C17" gate="G$1" pin="+"/>
<wire x1="-58.42" y1="20.32" x2="-68.58" y2="20.32" width="0.1524" layer="91"/>
<wire x1="-68.58" y1="20.32" x2="-68.58" y2="-35.56" width="0.1524" layer="91"/>
<wire x1="-68.58" y1="-35.56" x2="-68.58" y2="-104.14" width="0.1524" layer="91"/>
<wire x1="-68.58" y1="-104.14" x2="-160.02" y2="-104.14" width="0.1524" layer="91"/>
<label x="-162.56" y="-104.14" size="1.778" layer="95"/>
<wire x1="-43.18" y1="-35.56" x2="-68.58" y2="-35.56" width="0.1524" layer="91"/>
<junction x="-68.58" y="-35.56"/>
<pinref part="IC1" gate="A" pin="+IN"/>
</segment>
<segment>
<pinref part="ANALOG_PCB" gate="G$1" pin="P$8"/>
<wire x1="111.76" y1="-22.86" x2="96.52" y2="-22.86" width="0.1524" layer="91"/>
<label x="83.82" y="-22.86" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$20" class="0">
<segment>
<pinref part="R18" gate="G$1" pin="2"/>
<pinref part="SYM_TRIM" gate="G$1" pin="2"/>
<wire x1="-33.02" y1="-96.52" x2="-30.48" y2="-96.52" width="0.1524" layer="91"/>
</segment>
</net>
<net name="SDI" class="0">
<segment>
<pinref part="R9" gate="G$1" pin="1"/>
<wire x1="-213.36" y1="-7.62" x2="-218.44" y2="-7.62" width="0.1524" layer="91"/>
<label x="-223.52" y="-7.62" size="1.778" layer="95"/>
</segment>
</net>
<net name="SCK" class="0">
<segment>
<pinref part="R10" gate="G$1" pin="1"/>
<wire x1="-213.36" y1="-22.86" x2="-218.44" y2="-22.86" width="0.1524" layer="91"/>
<label x="-223.52" y="-22.86" size="1.778" layer="95"/>
</segment>
</net>
<net name="CS" class="0">
<segment>
<pinref part="R11" gate="G$1" pin="1"/>
<wire x1="-213.36" y1="-38.1" x2="-218.44" y2="-38.1" width="0.1524" layer="91"/>
<label x="-223.52" y="-38.1" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$19" class="0">
<segment>
<pinref part="MCP1" gate="G$1" pin="V_OUT_B"/>
<wire x1="-101.6" y1="-76.2" x2="-93.98" y2="-76.2" width="0.1524" layer="91"/>
<wire x1="-93.98" y1="-76.2" x2="-76.2" y2="-76.2" width="0.1524" layer="91"/>
<pinref part="V_OUT_B" gate="G$1" pin="TP"/>
<wire x1="-93.98" y1="-78.74" x2="-93.98" y2="-76.2" width="0.1524" layer="91"/>
<junction x="-93.98" y="-76.2"/>
<wire x1="-76.2" y1="-76.2" x2="-76.2" y2="-96.52" width="0.1524" layer="91"/>
<pinref part="R4" gate="G$1" pin="1"/>
<wire x1="-76.2" y1="-96.52" x2="-58.42" y2="-96.52" width="0.1524" layer="91"/>
</segment>
</net>
<net name="SIGNAL_AFTER_VCA" class="0">
<segment>
<pinref part="IC3" gate="A" pin="-IN"/>
<wire x1="45.72" y1="55.88" x2="43.18" y2="55.88" width="0.1524" layer="91"/>
<wire x1="43.18" y1="55.88" x2="43.18" y2="50.8" width="0.1524" layer="91"/>
<wire x1="43.18" y1="50.8" x2="68.58" y2="50.8" width="0.1524" layer="91"/>
<wire x1="68.58" y1="50.8" x2="68.58" y2="58.42" width="0.1524" layer="91"/>
<pinref part="IC3" gate="A" pin="OUT"/>
<wire x1="68.58" y1="58.42" x2="60.96" y2="58.42" width="0.1524" layer="91"/>
<junction x="68.58" y="58.42"/>
<label x="71.12" y="60.96" size="1.778" layer="95"/>
<pinref part="AFTER_VCA" gate="G$1" pin="TP"/>
<wire x1="68.58" y1="58.42" x2="111.76" y2="58.42" width="0.1524" layer="91"/>
<wire x1="111.76" y1="58.42" x2="111.76" y2="60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="SIGNAL_FROM_ANALOG" class="0">
<segment>
<wire x1="-43.18" y1="-40.64" x2="-48.26" y2="-40.64" width="0.1524" layer="91"/>
<wire x1="-48.26" y1="-40.64" x2="-48.26" y2="-45.72" width="0.1524" layer="91"/>
<wire x1="-48.26" y1="-45.72" x2="-22.86" y2="-45.72" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="-45.72" x2="-22.86" y2="-38.1" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="-38.1" x2="-27.94" y2="-38.1" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="-38.1" x2="-7.62" y2="-38.1" width="0.1524" layer="91"/>
<junction x="-22.86" y="-38.1"/>
<label x="-10.16" y="-38.1" size="1.778" layer="95"/>
<pinref part="IC1" gate="A" pin="-IN"/>
<pinref part="IC1" gate="A" pin="OUT"/>
<pinref part="FROM_ANALOG" gate="G$1" pin="TP"/>
<wire x1="-7.62" y1="-38.1" x2="-5.08" y2="-38.1" width="0.1524" layer="91"/>
<wire x1="0" y1="-30.48" x2="0" y2="-38.1" width="0.1524" layer="91"/>
<wire x1="0" y1="-38.1" x2="-5.08" y2="-38.1" width="0.1524" layer="91"/>
</segment>
</net>
<net name="SIGNAL_TO_ANALOG_PCB" class="0">
<segment>
<wire x1="-43.18" y1="-63.5" x2="-48.26" y2="-63.5" width="0.1524" layer="91"/>
<wire x1="-48.26" y1="-63.5" x2="-48.26" y2="-68.58" width="0.1524" layer="91"/>
<wire x1="-48.26" y1="-68.58" x2="-22.86" y2="-68.58" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="-68.58" x2="-22.86" y2="-60.96" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="-60.96" x2="-27.94" y2="-60.96" width="0.1524" layer="91"/>
<wire x1="-22.86" y1="-60.96" x2="0" y2="-60.96" width="0.1524" layer="91"/>
<junction x="-22.86" y="-60.96"/>
<label x="-12.7" y="-60.96" size="1.778" layer="95"/>
<pinref part="IC1" gate="B" pin="-IN"/>
<pinref part="IC1" gate="B" pin="OUT"/>
<pinref part="TO_ANALOG" gate="G$1" pin="TP"/>
<wire x1="0" y1="-53.34" x2="0" y2="-60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="TO_ANALOG_PCB" class="0">
<segment>
<wire x1="-43.18" y1="-58.42" x2="-58.42" y2="-58.42" width="0.1524" layer="91"/>
<label x="-66.04" y="-58.42" size="1.778" layer="95"/>
<pinref part="IC1" gate="B" pin="+IN"/>
</segment>
<segment>
<pinref part="ANALOG_PCB" gate="G$1" pin="P$4"/>
<wire x1="111.76" y1="-33.02" x2="96.52" y2="-33.02" width="0.1524" layer="91"/>
<label x="83.82" y="-33.02" size="1.778" layer="95"/>
</segment>
</net>
<net name="SYM" class="0">
<segment>
<pinref part="U5" gate="G$1" pin="SYM"/>
<wire x1="-15.24" y1="33.02" x2="-15.24" y2="38.1" width="0.1524" layer="91"/>
<label x="-15.24" y="38.1" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="R4" gate="G$1" pin="2"/>
<pinref part="R18" gate="G$1" pin="1"/>
<wire x1="-48.26" y1="-96.52" x2="-45.72" y2="-96.52" width="0.1524" layer="91"/>
<pinref part="R2" gate="G$1" pin="2"/>
<wire x1="-45.72" y1="-96.52" x2="-43.18" y2="-96.52" width="0.1524" layer="91"/>
<wire x1="-45.72" y1="-99.06" x2="-45.72" y2="-96.52" width="0.1524" layer="91"/>
<junction x="-45.72" y="-96.52"/>
<pinref part="SYM_1" gate="G$1" pin="TP"/>
<wire x1="-45.72" y1="-96.52" x2="-45.72" y2="-88.9" width="0.1524" layer="91"/>
<label x="-45.72" y="-91.44" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
