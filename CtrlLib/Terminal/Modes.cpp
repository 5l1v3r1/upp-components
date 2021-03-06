#include "Terminal.h"

#define LLOG(x)	 // RLOG("Terminal: " << x)
#define LDUMP(x) // RLOG("Terminal: Mode: " << #x << " = " << modes[x])

namespace Upp {

void Terminal::SetMode(const VTInStream::Sequence& seq, bool enable)
{
	for(const String& s : seq.parameters) {		// Multiple terminal modes can be set/reset at once.
		int modenum = StrInt(s);
		switch(FindModeId(modenum, seq.mode, clevel)) {
		case KAM:
			ANSIkam(enable);
			break;
		case CRM:
			ANSIcrm(enable);
			break;
		case IRM:
			ANSIirm(enable);
			break;
		case ERM:
			ANSIerm(enable);
			break;
		case SRM:
			ANSIsrm(enable);
			break;
		case LNM:
			ANSIlnm(enable);
			break;
		case DECCKM:
			DECckm(enable);
			break;
		case DECANM:
			DECanm(enable);
			break;
		case DECCOLM:
			DECcolm(enable);
			break;
		case DECSCLM:
			DECsclm(enable);
			break;
		case DECSCNM:
			DECscnm(enable);
			break;
		case DECOM:
			DECom(enable);
			break;
		case DECAWM:
			DECawm(enable);
			break;
		case DECARM:
			DECarm(enable);
			break;
		case DECTCEM:
			DECtcem(enable);
			break;
		case DECLRMM:
			DEClrmm(enable);
			break;
		case DECBKM:
			DECbkm(enable);
			break;
		case DECSDM:
			DECsdm(enable);
			break;
		case XTASCM:
			XTascm(enable);
			break;
		case XTBRPM:
			XTbrpm(enable);
			break;
		case XTREWRAPM:
			XTrewrapm(enable);
			break;
		case XTX10MM:
			XTx10mm(enable);
			break;
		case XTX11MM:
			XTx11mm(enable);
			break;
		case XTSGRMM:
			XTsgrmm(enable);
			break;
		case XTUTF8MM:
			XTutf8mm(enable);
			break;
		case XTSRCM:
			XTsrcm(enable);
			break;
		case XTDRAGM:
			XTdragm(enable);
			break;
		case XTANYMM:
			XTanymm(enable);
			break;
		case XTFOCUSM:
			XTfocusm(enable);
			break;
		case XTALTESCM:
			XTaltkeym(enable);
			break;
		case XTASBM:
			XTasbm(modenum, enable);
			break;
		case XTSPREG:
		case GATM:
		case SRTM:
		case VEM:
		case HEM:
		case PUM:
		case FEAM:
		case FETM:
		case MATM:
		case TTM:
		case SATM:
		case TSM:
		case EBM:
			// Permanently set or reset.
			break;
		default:
			LLOG(Format("Unhandled %[0:ANSI;private]s mode: %d", seq.mode, modenum));
			break;
		}
	}
}

void Terminal::ReportMode(const VTInStream::Sequence& seq)
{
	int modenum = seq.GetInt(1, 0);
	int mid = FindModeId(modenum, seq.mode, clevel);  // Only one mode at a time can be reported

	// Possible reply codes:
	// ====================
	// 0: Mode not recognized
	// 1: Set
	// 2: Reset
	// 3: Permanently set
	// 4: Permanently reset

	int reply = 0;

	if(mid >= 0)
		switch(mid) {
		case GATM:		// Currently we dont actively support these ANSI (ECMA-48) modes.
		case SRTM:
		case VEM:
		case HEM:
		case PUM:
		case FEAM:
		case FETM:
		case MATM:
		case TTM:
		case SATM:
		case TSM:
		case EBM:
			reply = 4;
			break;
		case XTSPREG:	// We don't support shared color registers for sixel images.
			reply = 3;
			break;
		default:
			reply = modes[mid] ? 1 : 2;
			break;
		}
	PutCSI(Format("%[1:?;]s%d;%d`$y", seq.mode == '?', modenum, reply));
}

void Terminal::ANSIkam(bool b)
{
	modes.Set(KAM, b);
	LDUMP(KAM);
}

void Terminal::ANSIcrm(bool b)
{
	modes.Set(CRM, b);
	LDUMP(CRM);
}

void Terminal::ANSIirm(bool b)
{
	modes.Set(IRM, b);
	LDUMP(IRM);
}

void Terminal::ANSIsrm(bool b)
{
	modes.Set(SRM, b);
	LDUMP(SRM);
}

void Terminal::ANSIerm(bool b)
{
	modes.Set(ERM, b);
	LDUMP(ERM);
}

void Terminal::ANSIlnm(bool b)
{
	modes.Set(LNM, b);
	LDUMP(LNM);
}

void Terminal::DECom(bool b)
{
	modes.Set(DECOM, b);
	page->Displaced(b);
	page->MoveTopLeft();
	LDUMP(DECOM);
}

void Terminal::DECckm(bool b)
{
	modes.Set(DECCKM, b);
	LDUMP(DECCKM);
}

void Terminal::DECanm(bool b)
{
	// According to DEC'S internal VT52 emulation document
	// (EL-00070-0A, p. A-45), exiting the VT52 mode always
	// sets the device conformance level to 1 (VT1xx mode).
	// This is also consistent with vttest/xterm's behavior.

	modes.Set(DECANM, b);
	if(b) {
		clevel = LEVEL_1;
		Restore(false);
	}
	else {
		clevel = LEVEL_0;
		Backup(false);
		page->SetTabs(8);
		gsets = GSets(CHARSET_TOASCII);
	}
	LDUMP(DECANM);
}

void Terminal::DECawm(bool b)
{
	modes.Set(DECAWM, b);
	page->AutoWrap(b);
	if(!b && modes[XTREWRAPM]) // Disabling the DECAWM also disables the reverse wrap.
		XTrewrapm(b);
	LDUMP(DECAWM);
}

void Terminal::DECarm(bool b)
{
	modes.Set(DECARM, b);
	LDUMP(DECARM);
}

void Terminal::DECkpam(bool b)
{
	modes.Set(DECKPAM, b);
	LDUMP(DECKPAM);
}

void Terminal::DECcolm(bool b)
{
	modes.Set(DECCOLM, b);
	DECom(false);
	page->ErasePage();
	SetColumns(b ? 132 : 80);
	LDUMP(DECCOLM);
}

void Terminal::DECsclm(bool b)
{
	modes.Set(DECSCLM, b);
	LDUMP(DECSCLM);
}

void Terminal::DECscnm(bool b)
{
	modes.Set(DECSCNM, b);
	page->Invalidate();
	Ctrl::Refresh();
	LDUMP(DECSCNM);
}

void Terminal::DECtcem(bool b)
{
	modes.Set(DECTCEM, b);
	caret.WhenAction();
	LDUMP(DECTCEM);
}

void Terminal::DEClrmm(bool b)
{
	modes.Set(DECLRMM, b);
	if(!b) page->ResetMargins();
	LDUMP(DECLRMM);
}

void Terminal::DECbkm(bool b)
{
	modes.Set(DECBKM, b);
	LDUMP(DECBKM);
}

void Terminal::DECsdm(bool b)
{
	modes.Set(DECSDM, b);
	LDUMP(DECSDM);
}

void Terminal::XTascm(bool b)
{
	modes.Set(XTASCM, b);
	LDUMP(XTASCM);
}

void Terminal::XTbrpm(bool b)
{
	modes.Set(XTBRPM, b);
	LDUMP(XTBRPM);
}

void Terminal::XTrewrapm(bool b)
{
	// Let reverse wrap require auto wrapping.
	
	if((reversewrap && modes[DECAWM]) || !b) {
		modes.Set(XTREWRAPM, b);
		page->ReverseWrap(b);
		LDUMP(XTREWRAPM);
	}
}

void Terminal::XTsrcm(bool b)
{
	modes.Set(XTSRCM, b);
	b ? Backup() : Restore(); // This mode is used in conjunction with the private mode 1047.
	LDUMP(XTSRCM);
}

void Terminal::XTasbm(int mode, bool b)
{
	modes.Set(XTASBM, b);
	if(mode == 47) {
		AlternateScreenBuffer(b);
	}
	else
	if(mode == 1047) {
		if(!b) page->ErasePage();
		AlternateScreenBuffer(b);
	}
	else
	if(mode == 1049) {
		if(b) Backup();
		AlternateScreenBuffer(b);
		if(b) page->ErasePage();
		else Restore();
	}
	SwapPage();
	LDUMP(XTASBM);
}

void Terminal::XTx10mm(bool b)
{
	modes.Set(XTX10MM, b);
	LDUMP(XTX10MM);
}

void Terminal::XTx11mm(bool b)
{
	modes.Set(XTX11MM, b);
	LDUMP(XTX11MM);
}

void Terminal::XTsgrmm(bool b)
{
	modes.Set(XTSGRMM, b);
	LDUMP(XTSGRMM);
}

void Terminal::XTutf8mm(bool b)
{
	modes.Set(XTUTF8MM, b);
	LDUMP(XTUTF8MM);
}

void Terminal::XTdragm(bool b)
{
	modes.Set(XTDRAGM, b);
	LDUMP(XTDRAGM);
}

void Terminal::XTfocusm(bool b)
{
	modes.Set(XTFOCUSM, b);
	LDUMP(XTFOCUSM);
}

void Terminal::XTaltkeym(bool b)
{
	modes.Set(XTALTESCM, b);
	LDUMP(XTALTESCM);
}

void Terminal::XTanymm(bool b)
{
	modes.Set(XTANYMM, b);
	LDUMP(XTANYMM);
}

}