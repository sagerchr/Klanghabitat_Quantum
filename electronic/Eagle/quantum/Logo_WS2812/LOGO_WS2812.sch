<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.6.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="16" fill="1" visible="no" active="no"/>
<layer number="15" name="Route15" color="23" fill="1" visible="no" active="no"/>
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
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
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
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="active components" urn="urn:adsk.eagle:library:17479138">
<packages>
<package name="WS2812" urn="urn:adsk.eagle:footprint:20837289/1" library_version="11">
<smd name="P$1" x="0.915" y="-0.55" dx="0.7" dy="0.7" layer="1"/>
<smd name="P$2" x="0.915" y="0.55" dx="0.7" dy="0.7" layer="1"/>
<smd name="P$3" x="-0.915" y="0.55" dx="0.7" dy="0.7" layer="1"/>
<smd name="P$4" x="-0.915" y="-0.55" dx="0.7" dy="0.7" layer="1"/>
<wire x1="-1.1" y1="1" x2="-1.1" y2="-1" width="0.127" layer="21"/>
<wire x1="-1.1" y1="-1" x2="1.1" y2="-1" width="0.127" layer="21"/>
<wire x1="1.1" y1="-1" x2="1.1" y2="1" width="0.127" layer="21"/>
<wire x1="1.1" y1="1" x2="-1.1" y2="1" width="0.127" layer="21"/>
<wire x1="0.4" y1="-0.8" x2="0.4" y2="0.8" width="0.127" layer="21"/>
<wire x1="0.4" y1="0.8" x2="0.5" y2="0.8" width="0.127" layer="21"/>
<wire x1="0.5" y1="0.8" x2="0.5" y2="-0.8" width="0.127" layer="21"/>
<wire x1="0.5" y1="-0.8" x2="0.4" y2="-0.8" width="0.127" layer="21"/>
</package>
</packages>
<packages3d>
<package3d name="WS2812" urn="urn:adsk.eagle:package:20837291/2" type="model" library_version="11">
<description>DFN4, 2.20 X 2.00 X 0.84 mm body
&lt;p&gt;DFN4 package with body size 2.20 X 2.00 X 0.84 mm&lt;/p&gt;</description>
<packageinstances>
<packageinstance name="WS2812"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="WS2812" urn="urn:adsk.eagle:symbol:20837290/1" library_version="11">
<wire x1="5.08" y1="0" x2="5.08" y2="12.7" width="0.254" layer="94"/>
<wire x1="5.08" y1="12.7" x2="-10.16" y2="12.7" width="0.254" layer="94"/>
<wire x1="-10.16" y1="12.7" x2="-10.16" y2="0" width="0.254" layer="94"/>
<wire x1="-10.16" y1="0" x2="5.08" y2="0" width="0.254" layer="94"/>
<pin name="DO" x="10.16" y="10.16" length="middle" rot="R180"/>
<pin name="GND" x="10.16" y="2.54" length="middle" rot="R180"/>
<pin name="DI" x="-15.24" y="10.16" length="middle"/>
<pin name="VDD" x="-15.24" y="2.54" length="middle"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="WS2812" urn="urn:adsk.eagle:component:20837292/2" library_version="11">
<gates>
<gate name="G$1" symbol="WS2812" x="-5.08" y="0"/>
</gates>
<devices>
<device name="" package="WS2812">
<connects>
<connect gate="G$1" pin="DI" pad="P$3"/>
<connect gate="G$1" pin="DO" pad="P$1"/>
<connect gate="G$1" pin="GND" pad="P$2"/>
<connect gate="G$1" pin="VDD" pad="P$4"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:20837291/2"/>
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
<part name="U$1" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$2" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$3" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$4" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$5" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$6" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$7" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$8" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$9" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$10" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$11" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$12" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$13" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$14" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$15" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$16" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$17" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$18" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$19" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$20" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$21" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$22" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$23" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$24" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$25" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$26" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$27" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$28" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$29" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$30" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$31" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$32" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$33" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$34" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$35" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$36" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$37" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$38" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$39" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$40" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$41" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$42" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$43" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$44" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$45" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$46" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$47" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$48" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$49" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$50" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$51" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$52" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$53" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$54" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$55" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$56" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$57" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$58" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$59" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
<part name="U$60" library="active components" library_urn="urn:adsk.eagle:library:17479138" deviceset="WS2812" device="" package3d_urn="urn:adsk.eagle:package:20837291/2"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="25.4" y="99.06" smashed="yes"/>
<instance part="U$2" gate="G$1" x="55.88" y="99.06" smashed="yes"/>
<instance part="U$3" gate="G$1" x="83.82" y="99.06" smashed="yes"/>
<instance part="U$4" gate="G$1" x="111.76" y="99.06" smashed="yes"/>
<instance part="U$5" gate="G$1" x="139.7" y="99.06" smashed="yes"/>
<instance part="U$6" gate="G$1" x="25.4" y="83.82" smashed="yes"/>
<instance part="U$7" gate="G$1" x="55.88" y="83.82" smashed="yes"/>
<instance part="U$8" gate="G$1" x="83.82" y="83.82" smashed="yes"/>
<instance part="U$9" gate="G$1" x="111.76" y="83.82" smashed="yes"/>
<instance part="U$10" gate="G$1" x="139.7" y="83.82" smashed="yes"/>
<instance part="U$11" gate="G$1" x="25.4" y="68.58" smashed="yes"/>
<instance part="U$12" gate="G$1" x="55.88" y="68.58" smashed="yes"/>
<instance part="U$13" gate="G$1" x="83.82" y="68.58" smashed="yes"/>
<instance part="U$14" gate="G$1" x="111.76" y="68.58" smashed="yes"/>
<instance part="U$15" gate="G$1" x="139.7" y="68.58" smashed="yes"/>
<instance part="U$16" gate="G$1" x="25.4" y="53.34" smashed="yes"/>
<instance part="U$17" gate="G$1" x="55.88" y="53.34" smashed="yes"/>
<instance part="U$18" gate="G$1" x="83.82" y="53.34" smashed="yes"/>
<instance part="U$19" gate="G$1" x="111.76" y="53.34" smashed="yes"/>
<instance part="U$20" gate="G$1" x="139.7" y="53.34" smashed="yes"/>
<instance part="U$21" gate="G$1" x="25.4" y="38.1" smashed="yes"/>
<instance part="U$22" gate="G$1" x="55.88" y="38.1" smashed="yes"/>
<instance part="U$23" gate="G$1" x="83.82" y="38.1" smashed="yes"/>
<instance part="U$24" gate="G$1" x="111.76" y="38.1" smashed="yes"/>
<instance part="U$25" gate="G$1" x="139.7" y="38.1" smashed="yes"/>
<instance part="U$26" gate="G$1" x="25.4" y="22.86" smashed="yes"/>
<instance part="U$27" gate="G$1" x="55.88" y="22.86" smashed="yes"/>
<instance part="U$28" gate="G$1" x="83.82" y="22.86" smashed="yes"/>
<instance part="U$29" gate="G$1" x="111.76" y="22.86" smashed="yes"/>
<instance part="U$30" gate="G$1" x="139.7" y="22.86" smashed="yes"/>
<instance part="U$31" gate="G$1" x="25.4" y="7.62" smashed="yes"/>
<instance part="U$32" gate="G$1" x="55.88" y="7.62" smashed="yes"/>
<instance part="U$33" gate="G$1" x="83.82" y="7.62" smashed="yes"/>
<instance part="U$34" gate="G$1" x="111.76" y="7.62" smashed="yes"/>
<instance part="U$35" gate="G$1" x="139.7" y="7.62" smashed="yes"/>
<instance part="U$36" gate="G$1" x="25.4" y="-7.62" smashed="yes"/>
<instance part="U$37" gate="G$1" x="55.88" y="-7.62" smashed="yes"/>
<instance part="U$38" gate="G$1" x="83.82" y="-7.62" smashed="yes"/>
<instance part="U$39" gate="G$1" x="111.76" y="-7.62" smashed="yes"/>
<instance part="U$40" gate="G$1" x="139.7" y="-7.62" smashed="yes"/>
<instance part="U$41" gate="G$1" x="25.4" y="-22.86" smashed="yes"/>
<instance part="U$42" gate="G$1" x="55.88" y="-22.86" smashed="yes"/>
<instance part="U$43" gate="G$1" x="83.82" y="-22.86" smashed="yes"/>
<instance part="U$44" gate="G$1" x="111.76" y="-22.86" smashed="yes"/>
<instance part="U$45" gate="G$1" x="139.7" y="-22.86" smashed="yes"/>
<instance part="U$46" gate="G$1" x="25.4" y="-38.1" smashed="yes"/>
<instance part="U$47" gate="G$1" x="55.88" y="-38.1" smashed="yes"/>
<instance part="U$48" gate="G$1" x="83.82" y="-38.1" smashed="yes"/>
<instance part="U$49" gate="G$1" x="111.76" y="-38.1" smashed="yes"/>
<instance part="U$50" gate="G$1" x="139.7" y="-38.1" smashed="yes"/>
<instance part="U$51" gate="G$1" x="25.4" y="-53.34" smashed="yes"/>
<instance part="U$52" gate="G$1" x="55.88" y="-53.34" smashed="yes"/>
<instance part="U$53" gate="G$1" x="83.82" y="-53.34" smashed="yes"/>
<instance part="U$54" gate="G$1" x="111.76" y="-53.34" smashed="yes"/>
<instance part="U$55" gate="G$1" x="139.7" y="-53.34" smashed="yes"/>
<instance part="U$56" gate="G$1" x="25.4" y="-68.58" smashed="yes"/>
<instance part="U$57" gate="G$1" x="55.88" y="-68.58" smashed="yes"/>
<instance part="U$58" gate="G$1" x="83.82" y="-68.58" smashed="yes"/>
<instance part="U$59" gate="G$1" x="111.76" y="-68.58" smashed="yes"/>
<instance part="U$60" gate="G$1" x="139.7" y="-68.58" smashed="yes"/>
</instances>
<busses>
</busses>
<nets>
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
