topic "Specifications";
[l288;i1120;a17;O9;~~~.1408;2 $$1,0#10431211400427159095818037425705:param]
[a83;*R6 $$2,5#31310162474203024125188417583966:caption]
[H4;b83;*4 $$3,5#07864147445237544204411237157677:title]
[i288;O9;C2 $$4,6#40027414424643823182269349404212:item]
[b42;a42;2 $$5,5#45413000475342174754091244180557:text]
[l288;b17;a17;2 $$6,6#27521748481378242620020725143825:desc]
[l321;C@5;1 $$7,7#20902679421464641399138805415013:code]
[b2503;2 $$8,0#65142375456100023862071332075487:separator]
[*@(0.0.255)2 $$9,0#83433469410354161042741608181528:base]
[C2 $$10,0#37138531426314131251341829483380:class]
[l288;a17;*1 $$11,11#70004532496200323422659154056402:requirement]
[i417;b42;a42;O9;~~~.416;2 $$12,12#10566046415157235020018451313112:tparam]
[b167;C2 $$13,13#92430459443460461911108080531343:item1]
[i288;a42;O9;C2 $$14,14#77422149456609303542238260500223:item2]
[*@2$(0.128.128)2 $$15,15#34511555403152284025741354420178:NewsDate]
[l321;*C$7;2 $$16,16#03451589433145915344929335295360:result]
[l321;b83;a83;*C$7;2 $$17,17#07531550463529505371228428965313:result`-line]
[l160;*C+117 $$18,5#88603949442205825958800053222425:package`-title]
[2 $$19,0#53580023442335529039900623488521:gap]
[C2 $$20,20#70211524482531209251820423858195:class`-nested]
[b50;2 $$21,21#03324558446220344731010354752573:Par]
[H8;b73;*+150 $$22,5#07864147445237544204111237153677:subtitle]
[2 $$0,0#00000000000000000000000000000000:Default]
[{_}%EN-US 
[s2; Technical Specifications&]
[s5; This document is to be written...&]
[s22;%- Table of contents&]
[s0;%- &]
[s0; 1. Terminal Emulation Modes&]
[s0; 2. Terminal I/O Modes&]
[s0; 3. Terminal Charsets and Legacy Charsets Support&]
[s0; 4. Tables&]
[s0;i150;O9; -|4.1 Supported Control Characters&]
[s0;i150;O9; -|4.2 Supported Terminal Modes&]
[s0;i150;O9; -|4.3 Supported Escape Sequences&]
[s0;i150;O9; -|4.4 Supported Command Sequences&]
[s0;i150;O9; -|4.5 Supported Device Control Strings&]
[s0;i150;O9; -|4.6 Supported Operating System Commands&]
[s5; 5. Further Readings&]
[s0; 6. Acknowledgements&]
[s5; &]
[ {{1353:689:6831:1127<32;h3;@(165)-3 [s0;= [* Supported Control Characters (C0`-C1)]]
::@2-2 [s0;%- ]
::-1 [s0;%- ]
:: [s0;%- ]
::@(229) [s0;= [*C Mnemonic]]
:: [s0;= [*C Byte]]
:: [s0;= [*C Description]]
:: [s0;= [*C Device Level]]
::@2 [s0; [*@3 NUL]]
:: [s0;= [C 0x00]]
:: [s0; Ignored.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 ENQ]]
:: [s0;= [C 0x05]]
:: [s0; Terminal status request. (Answerback message is sent as a response.)]
:: [s0;= [C Level 0]]
:: [s0; [*@3 BEL]]
:: [s0;= [C 0x07]]
:: [s0; Audio or visual bell.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 BS ]]
:: [s0;= [C 0x08]]
:: [s0; Backspace.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 HT]]
:: [s0;= [C 0x09]]
:: [s0; Horizontal tab. Moves the cursor to next tab stop.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 LF]]
:: [s0;= [C 0x0A]]
:: [s0; Line feed.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 VT]]
:: [s0;= [C 0x0B]]
:: [s0; Vertical tab. Treated as line feed.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 FF]]
:: [s0;= [C 0x0C]]
:: [s0; Form feed. Treated as line feed.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 CR]]
:: [s0;= [C 0x0D]]
:: [s0; Carraige return.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 LS0]]
:: [s0;= [C 0x0E]]
:: [s0; Locking shift 0. Invokes and locks the G0 charset into GL.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 LS1]]
:: [s0;= [C 0x0F]]
:: [s0; Locking shift 1. Invokes and locks the G1 charset into GL.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 XON]]
:: [s0;= [C 0x11]]
:: [s0; Resume data transter.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 XOFF]]
:: [s0;= [C 0x13]]
:: [s0; Pause data transter.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 DEL]]
:: [s0;= [C 0x7F]]
:: [s0; Ignored.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 IND]]
:: [s0;= [C 0x84]]
:: [s0; Index.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 NEL]]
:: [s0;= [C 0x85]]
:: [s0; Next line.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 HTS]]
:: [s0;= [C 0x88]]
:: [s0; Sets a tab at the active cursor position.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 RI]]
:: [s0;= [C 0x8D]]
:: [s0; Reverse index.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 SS2]]
:: [s0;= [C 0x8E]]
:: [s0; Single shift 2. Temporarily invokes the G2 charset into GL.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 SS3]]
:: [s0;= [C 0x8F]]
:: [s0; Singls shift 3. Temporarily invokes the G3 charset into GL.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 SPA]]
:: [s0;= [C 0x96]]
:: [s0; Start of protected area. (ECMA`-48)]
:: [s0;= [C Level 2]]
:: [s0; [*@3 EPA]]
:: [s0;= [C 0x97]]
:: [s0; End of protected area. (ECMA`-48)]
:: [s0;= [C Level 2]]
:: [s0; [*@3 DECID]]
:: [s0;= [C 0x9A]]
:: [s0; Return terminal ID.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 ST]]
:: [s0;= [C 0x9C]]
:: [s0; String terminator.]
:: [s0;= [C Level 1]]}}&]
[s0;=C &]
[s0;=C &]
[ {{1436:706:5601:1155:1102h15;@(165)-4 [s0;= [* Supported Terminal Modes]]
::@2-3 [s0;%- ]
::-2 [s0;%- ]
::-1 [s0;%- ]
:: [s0;%- ]
::@(229) [s0;= [*C Mnemonic]]
:: [s0;= [*C Mode ID]]
:: [s0;= [*C Description]]
:: [s0;= [*C Type]]
:: [s0;= [*C Device Level]]
::@2 [s0; [*@3 KAM]]
:: [s0;= [C 2]]
:: [s0; Keyboard action mode.]
:: [s0;= [C ANSI]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 CRM]]
:: [s0;= [C 3]]
:: [s0; Show/hide control characters.]
:: [s0;= [C ANSI]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 IRM]]
:: [s0;= [C 4]]
:: [s0; Insert/replace characters.]
:: [s0;= [C ANSI]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 ERM]]
:: [s0;= [C 6]]
:: [s0; Erasure mode.]
:: [s0;= [C ANSI]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 SRM]]
:: [s0;= [C 12]]
:: [s0; Send/receive mode. (Local echo.)]
:: [s0;= [C ANSI]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 LNM]]
:: [s0;= [C 20]]
:: [s0; Line feed/new line mode.]
:: [s0;= [C ANSI]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DECCKM]]
:: [s0;= [C 1]]
:: [s0; Cursor keys mode.]
:: [s0;= [C DEC private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DECANM]]
:: [s0;= [C 2]]
:: [s0; Leave ANSI mode. (Enter VT52 mode.)]
:: [s0;= [C DEC private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DECCOLM]]
:: [s0;= [C 3]]
:: [s0; 80/132 columns mode.]
:: [s0;= [C DEC private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DECSCLM]]
:: [s0;= [C 4]]
:: [s0; Scrolling mode.]
:: [s0;= [C DEC private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DECSCNM]]
:: [s0;= [C 5]]
:: [s0; Normal/inverse video mode.]
:: [s0;= [C DEC private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DECOM]]
:: [s0;= [C 6]]
:: [s0; Origin mode.]
:: [s0;= [C DEC private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DECAWM]]
:: [s0;= [C 7]]
:: [s0; Autowrap mode.]
:: [s0;= [C DEC private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DECARM]]
:: [s0;= [C 8]]
:: [s0; Autorepeat mode.]
:: [s0;= [C DEC private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DECTCEM]]
:: [s0;= [C 25]]
:: [s0; Show/hide caret.]
:: [s0;= [C DEC private]]
:: [s0;= [C Level 2]]
:: [s0; [*@3 DECBKM]]
:: [s0;= [C 67]]
:: [s0; Send backspace when backarrow key is pressed.]
:: [s0;= [C DEC private]]
:: [s0;= [C Level 3]]
:: [s0; [*@3 DECLRMM]]
:: [s0;= [C 69]]
:: [s0; Enable/disable horizontal margins.]
:: [s0;= [C DEC private]]
:: [s0;= [C Level 4]]
:: [s0; [*@3 XTX10MM]]
:: [s0;= [C 9]]
:: [s0; X10 mouse button tracking mode. (Compatibility mode.)]
:: [s0;= [C xterm private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 XTASBM]]
:: [s0;= [C 47]]
:: [s0; Alternate screen buffer mode. (Ver. 1)]
:: [s0;= [C xterm private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 XTX11MM]]
:: [s0;= [C 1000]]
:: [s0; X11 mouse button tracking mode. (Normal mode.)]
:: [s0;= [C xterm private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 XTDRAGM]]
:: [s0;= [C 1002]]
:: [s0; X11 mouse motion tracking mode.]
:: [s0;= [C xterm private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 XTANYMM]]
:: [s0;= [C 1003]]
:: [s0; X11 mouse motion tracking mode. (Any motion event.)]
:: [s0;= [C xterm private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 XTFOCUSM]]
:: [s0;= [C 1004]]
:: [s0; Focus in/out mode.]
:: [s0;= [C xterm private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 XTUTF8MM]]
:: [s0;= [C 1005]]
:: [s0; Enable/disable UTF8 mouse tracking coordinates.]
:: [s0;= [C xterm private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 XTSGRMM]]
:: [s0;= [C 1006]]
:: [s0; Enable/disable SGR mouse tracking coordinates.]
:: [s0;= [C xterm private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 XTASCM]]
:: [s0;= [C 1007]]
:: [s0; Alternate scroll mode]
:: [s0;= [C xterm private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 XTASBM]]
:: [s0;= [C 1047]]
:: [s0; Alternate screen buffer mode. (Ver. 2)]
:: [s0;= [C xterm private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 XTSRCM]]
:: [s0;= [C 1048]]
:: [s0; Save/restore cursor.]
:: [s0;= [C xterm private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 XTASBM]]
:: [s0;= [C 1049]]
:: [s0; Alternate screen buffer mode. (Ver. 3)]
:: [s0;= [C xterm private]]
:: [s0;= [C Level 1]]
:: [s0; [*@3 XTBRPM]]
:: [s0;= [C 2004]]
:: [s0; Bracketed paste mode.]
:: [s0;= [C xterm private]]
:: [s0;= [C Level 1]]}}&]
[s0;=C &]
[s0;=C &]
[s0;%- &]
[ {{2413:6482:1105h42;@(165)-2 [s0;= [* Supported Escape Sequences]]
::@2-1 [s0;%- ]
:: [s0;%- ]
::@(229) [s0;= [*C Mnemonic]]
:: [s0;= [*C Description]]
:: [s0;= [*C Device Level]]
::@2 [s0; [*@3 ANSICL1]]
:: [s0; Select ANSI conformance level 1]
:: [s0;= [C Level 2]]
:: [s0; [*@3 ANSICL2]]
:: [s0; Select ANSI conformance level 2]
:: [s0;= [C Level 2]]
:: [s0; [*@3 ANSICL3]]
:: [s0; Select ANSI conformance level 3]
:: [s0;= [C Level 2]]
:: [s0; [*@3 DECALN]]
:: [s0; Display alignment test.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DECBI]]
:: [s0; Back index.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 DECFI]]
:: [s0; Forward index.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 DECKPAM]]
:: [s0; Keypad application mode.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 DECKPNM]]
:: [s0; Keypad numeric mode.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 DECRC]]
:: [s0; Restore cursor.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DECSC]]
:: [s0; Save cursor.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 LS1R]]
:: [s0; Locking shift 1 right. Invokes and locks the G1 charset into 
GR]
:: [s0;= [C Level 2]]
:: [s0; [*@3 LS2]]
:: [s0; Locking shift 2 left. Invokes and locks the G2 charset into 
GL]
:: [s0;= [C Level 2]]
:: [s0; [*@3 LS2R]]
:: [s0; Locking shift 2 right. Invokes and locks the G2 charset into 
GR]
:: [s0;= [C Level 2]]
:: [s0; [*@3 LS3]]
:: [s0; Locking shift 3 left Invokes and locks the G3 charset into GL]
:: [s0;= [C Level 2]]
:: [s0; [*@3 LS3R]]
:: [s0; Locking shift 3 right. Invokes and locks the G3 charset into 
GR]
:: [s0;= [C Level 2]]
:: [s0; [*@3 RIS]]
:: [s0; Perform hard reset.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 S7C1T]]
:: [s0; Put terminal into 7`-bits mode.]
:: [s0;= [C Level 2]]
:: [s0; [*@3 S8C1T]]
:: [s0; Put terminal into 8`-bits mode.]
:: [s0;= [C Level 2]]
:: [s0; [*@3 SCS`_DEFAULT]]
:: [s0; Select default charset.]
:: [s0;= [C Level 3]]
:: [s0; [*@3 SCS`_G0`_ASCII]]
:: [s0; Invoke US`-ASCII charset into G0.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 SCS`_G1`_ASCII]]
:: [s0; Invoke US`-ASCII charset into G1.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 SCS`_G2`_ASCII]]
:: [s0; Invoke US`-ASCII charset into G2.]
:: [s0;= [C Level 2]]
:: [s0; [*@3 SCS`_G3`_ASCII]]
:: [s0; Invoke US`-ASCII charset into G3.]
:: [s0;= [C Level 2]]
:: [s0; [*@3 SCS`_G0`_DEC`_ACS]]
:: [s0; Invoke DEC standard ROM charset into G0. (Stubbed)]
:: [s0;= [C Level 1]]
:: [s0; [*@3 SCS`_G1`_DEC`_ACS]]
:: [s0; Invoke DEC standard ROM charset into G1. (Stubbed)]
:: [s0;= [C Level 1]]
:: [s0; [*@3 SCS`_G0`_DEC`_DCS]]
:: [s0; Invoke DEC line`-drawing charset into G0.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 SCS`_G1`_DEC`_DCS]]
:: [s0; Invoke DEC line`-drawing charset into G1.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 SCS`_G2`_DEC`_DCS]]
:: [s0; Invoke DEC line`-drawing charset into G2.]
:: [s0;= [C Level 2]]
:: [s0; [*@3 SCS`_G3`_DEC`_DCS]]
:: [s0; Invoke DEC line`-drawing charset into G3.]
:: [s0;= [C Level 2]]
:: [s0; [*@3 SCS`_G0`_DEC`_MCS]]
:: [s0; Invoke DEC supplemental charset into G0.]
:: [s0;= [C Level 2]]
:: [s0; [*@3 SCS`_G1`_DEC`_MCS]]
:: [s0; Invoke DEC supplemental charset into G1.]
:: [s0;= [C Level 2]]
:: [s0; [*@3 SCS`_G2`_DEC`_MCS]]
:: [s0; Invoke DEC supplemental charset into G2.]
:: [s0;= [C Level 2]]
:: [s0; [*@3 SCS`_G3`_DEC`_MCS]]
:: [s0; Invoke DEC supplemental charset into G3.]
:: [s0;= [C Level 2]]
:: [s0; [*@3 SCS`_G0`_DEC`_TCS]]
:: [s0; Invoke DEC technical charset into G0.]
:: [s0;= [C Level 3]]
:: [s0; [*@3 SCS`_G1`_DEC`_TCS]]
:: [s0; Invoke DEC technical charset into G1.]
:: [s0;= [C Level 3]]
:: [s0; [*@3 SCS`_G2`_DEC`_TCS]]
:: [s0; Invoke DEC technical charset into G2.]
:: [s0;= [C Level 3]]
:: [s0; [*@3 SCS`_G3`_DEC`_TCS]]
:: [s0; Invoke DEC technical charset into G3.]
:: [s0;= [C Level 3]]
:: [s0; [*@3 SCS`_G1`_LATIN1]]
:: [s0; Invoke DEC Latin`-1 charset into G1.]
:: [s0;= [C Level 3]]
:: [s0; [*@3 SCS`_G2`_LATIN1]]
:: [s0; Invoke DEC Latin`-1 charset into G2.]
:: [s0;= [C Level 3]]
:: [s0; [*@3 SCS`_G3`_LATIN1]]
:: [s0; Invoke DEC Latin`-1 charset into G3.]
:: [s0;= [C Level 3]]
:: [s0; [*@3 SCS`_UTF8]]
:: [s0; Selects UTF`-8 charset.]
:: [s0;= [C Level 3]]
:: [s0; [*@3 VT52`_CUB]]
:: [s0; [/ VT52 mode:] Move backward.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 VT52`_CUD]]
:: [s0; [/ VT52 mode:] Move downward.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 VT52`_CUF]]
:: [s0; [/ VT52 mode:] Move forward.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 VT52`_CUP]]
:: [s0; [/ VT52 mode:] Direct cursor addressing.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 VT52`_CUU]]
:: [s0; [/ VT52 mode:] Move upward.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 VT52`_DA]]
:: [s0; [/ VT52 mode: ]Device identify.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 VT52`_DCS`_ON]]
:: [s0; [/ VT52 mode:] Drawing characters: On.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 VT52`_DCS`_OFF]]
:: [s0; [/ VT52 mode:] Drawing characters: Off.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 VT52`_DECANM]]
:: [s0; [/ VT52 mode:] Enter ANSI mode. (Leave VT52 mode.)]
:: [s0;= [C Level 0]]
:: [s0; [*@3 VT52`_HOME]]
:: [s0; [/ VT52 mode:] Move home.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 VT52`_ED]]
:: [s0; [/ VT52 mode:] Erase to end of screen.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 VT52`_EL]]
:: [s0; [/ VT52 mode:] Erase to end of line.]
:: [s0;= [C Level 0]]
:: [s0; [*@3 VT52`_RI]]
:: [s0; [/ VT52 mode:] Reverse index.]
:: [s0;= [C Level 0]]}}&]
[s0;=C &]
[s0;=C &]
[s0;%- &]
[ {{2413:6472:1115h37;@(165)-2 [s0;= [* Supported Command Sequences]]
::@2-1 [s0;%- ]
:: [s0;%- ]
::@(229) [s0;= [*C Mnemonic]]
:: [s0;= [*C Description]]
:: [s0;= [*C Device Level]]
::@2 [s0; [*@3 CBT]]
:: [s0; Cursor backward tabulation.]
:: [s0;= [C Level 3]]
:: [s0; [*@3 CHA]]
:: [s0; Cursor horizontal absolute.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 CHT]]
:: [s0; Cursor horizontal tabulation.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 CNL]]
:: [s0; Move to next line. (No scroll.)]
:: [s0;= [C Level 4]]
:: [s0; [*@3 CPL]]
:: [s0; Move to previous line. (No scroll.)]
:: [s0;= [C Level 4]]
:: [s0; [*@3 CUB]]
:: [s0; Move backward.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 CUD]]
:: [s0; Move downward.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 CUF]]
:: [s0; Move forward.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 CUP]]
:: [s0; Cursor position.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 CUU]]
:: [s0; Move upward.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DA1]]
:: [s0; Send primary device attributes.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DA2]]
:: [s0; Send secondary device attributes.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DA3]]
:: [s0; Send tertiary device attributes.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 DCH]]
:: [s0; Delete character.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DECCARA]]
:: [s0; Change attributes in rectangular area]
:: [s0;= [C Level 4]]
:: [s0; [*@3 DECDC]]
:: [s0; Delete column.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 DECCRA]]
:: [s0; Copy rectangular area.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 DECERA]]
:: [s0; Erase rectangular area.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 DECFRA]]
:: [s0; Fill rectangular area.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 DECIC]]
:: [s0; Insert column.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 DECLL]]
:: [s0; Set programmable LEDs.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DECRARA]]
:: [s0; Reverse attributes in rectangular area.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 DECRQM]]
:: [s0; Request mode.]
:: [s0;= [C Level 2]]
:: [s0; [*@3 DECREQTPARM]]
:: [s0; Request terminal parameters.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DECRQCRA]]
:: [s0; Request rectangular area checksum.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 DECRQPSR]]
:: [s0; Request presentation state report]
:: [s0;= [C Level 3]]
:: [s0; [*@3 DECSACE]]
:: [s0; Select rectangular area attribute change extent.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 DECSCA]]
:: [s0; Set character protection attribute.]
:: [s0;= [C Level 2]]
:: [s0; [*@3 DECSCL]]
:: [s0; Select device conformance level.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DECSCPP]]
:: [s0; Set columns per page.]
:: [s0;= [C Level 3]]
:: [s0; [*@3 DECSCUSR]]
:: [s0; Set cursor style]
:: [s0;= [C Level 4]]
:: [s0; [*@3 DECSGR]]
:: [s0; Select graphics rendition. (DEC)]
:: [s0;= [C Level 2]]
:: [s0; [*@3 DECSED]]
:: [s0; Selectively erase in display.]
:: [s0;= [C Level 2]]
:: [s0; [*@3 DECSEL]]
:: [s0; Selectively erase in line.]
:: [s0;= [C Level 2]]
:: [s0; [*@3 DECSERA]]
:: [s0; Selectively erase rectangular area.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 DECSLPP]]
:: [s0; Set lines per page.]
:: [s0;= [C Level 3]]
:: [s0; [*@3 DECSLRM]]
:: [s0; Set horizontal margins.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 DECSNLS]]
:: [s0; Set number of lines per screen.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 DECST8C]]
:: [s0; Set a tab at every 8 columns.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 DECSTBM]]
:: [s0; Set vertical margins]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DECSTR]]
:: [s0; Soft reset.]
:: [s0;= [C Level 2]]
:: [s0; [*@3 DECTST]]
:: [s0; Device confidence tests]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DL]]
:: [s0; Delete line.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 DSR]]
:: [s0; Device status report.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 ECH]]
:: [s0; Erase character.]
:: [s0;= [C Level 2]]
:: [s0; [*@3 ED]]
:: [s0; Erase in display.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 EL]]
:: [s0; Erase in line.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 HPA]]
:: [s0; Horizontal position absolute.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 HPR]]
:: [s0; Horizontal position relative.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 HVP]]
:: [s0; Cursor horizontal and vertical position.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 ICH]]
:: [s0; Insert character.]
:: [s0;= [C Level 2]]
:: [s0; [*@3 IL]]
:: [s0; Insert line.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 REP]]
:: [s0; Repeat last character.]
:: [s0;= [C Level 3]]
:: [s0; [*@3 RM]]
:: [s0; Reset mode.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 SCORC]]
:: [s0; SCO restore cursor.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 SCOSC]]
:: [s0; SCO save cursor.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 SD]]
:: [s0; Scroll down.]
:: [s0;= [C Level 3]]
:: [s0; [*@3 SGR]]
:: [s0; Select graphics rendition. (ANSI)]
:: [s0;= [C Level 1]]
:: [s0; [*@3 SL]]
:: [s0; Scroll/shift left.]
:: [s0;= [C Level 3]]
:: [s0; [*@3 SM]]
:: [s0; Set mode.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 SR]]
:: [s0; Scroll/shift right.]
:: [s0;= [C Level 3]]
:: [s0; [*@3 SU]]
:: [s0; Scroll up.]
:: [s0;= [C Level 3]]
:: [s0; [*@3 TBC]]
:: [s0; Clear tabs.]
:: [s0;= [C Level 1]]
:: [s0; [*@3 VPA]]
:: [s0; Vertical position absolute.]
:: [s0;= [C Level 4]]
:: [s0; [*@3 VPR]]
:: [s0; Vertical position relative.]
:: [s0;= [C Level 4]]}}&]
[s2; &]
[s0;%- &]
[ {{2413:6492:1095h37;@(165)-2 [s0;= [* Supported Device Control Strings]]
::@2-1 [s0;%- ]
:: [s0;%- ]
::@(229) [s0;= [*C Mnemonic]]
:: [s0;= [*C Description]]
:: [s0;= [*C Device Level]]
::@2 [s0; [*@3 DECRQSS]]
:: [s0; Request control function strings]
:: [s0;= [C Level 4]]
:: [s0; [*@3 DECRSPS]]
:: [s0; Restore presentation state]
:: [s0;= [C Level 3]]
:: [s0; [*@3 DECUDK]]
:: [s0; Set user`-defined keys]
:: [s0;= [C Level 2]]}}&]
[s5; &]
[s0; ]]