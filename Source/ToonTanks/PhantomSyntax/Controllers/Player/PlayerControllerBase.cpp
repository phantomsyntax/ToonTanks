// All rights reserved, 2021, Phantom Syntax


#include "ToonTanks/PhantomSyntax/Controllers/Player/PlayerControllerBase.h"


void APlayerControllerBase::SetPlayerEnabledState(bool SetPlayerEnabled)
{
	if (SetPlayerEnabled)
	{
		GetPawn()->EnableInput(this);
	}
	else
	{
		GetPawn()->DisableInput(this);
	}

	// Enable/disable mouse cursor accordingly
	bShowMouseCursor = SetPlayerEnabled;
}
