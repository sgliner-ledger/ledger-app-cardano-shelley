#include "common.h"
#include "assert.h"
#include "uiHelpers.h"

// Note(ppershing): In DEBUG we need to keep going
// because rendering on display takes multiple SEPROXYHAL
// exchanges until it renders the display
void assert(
        int cond,
        const char* msgStr
        #ifdef RESET_ON_CRASH
        MARK_UNUSED
        #endif
)
{
	// *INDENT-OFF*
	if (cond) return; // everything holds
	#ifdef RESET_ON_CRASH
	io_seproxyhal_se_reset();
	#else
	{
		#if defined(DEVEL) || defined(FUZZING)
		{
			PRINTF("Assertion failed %s\n", msgStr);
			#ifndef FUZZING
			ui_displayPaginatedText("Assertion failed", msgStr, NULL);
			#endif
			THROW(ERR_ASSERT);
		}
		#else
			#error "RESET_ON_CRASH should be enabled in non-devel mode!"
		#endif // DEVEL
	}
	#endif
	// *INDENT-ON*
}
