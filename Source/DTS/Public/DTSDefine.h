#pragma once

#include "CoreMinimal.h"

namespace DTS
{
	enum EArgType
	{
		SLATE_NAMED_SLOT,
		SLATE_DEFAULT_SLOT,
		SLATE_ATTRIBUTE,
		SLATE_ARGUMENT,
		SLATE_STYLE_ARGUMENT,
		SLATE_EVENT,
	};

	struct FSlate_Named_Slot {};
	struct FSlate_Default_Slot {};
}

// **************************** TypeScript Type ****************************
#define TS_string "string"
#define TS_boolean "boolean"
#define TS_number "number"

struct FArguments { };