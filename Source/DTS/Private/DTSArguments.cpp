#include "DTSArguments.h"

FString DTS::DTSArguments::FArgument::GetType()
{
	switch (ArgType)
	{
	case SLATE_ATTRIBUTE:
		return FString::Printf(TEXT("%s | (() => %s)"), *Type, *Type);
	case SLATE_ARGUMENT:
	case SLATE_STYLE_ARGUMENT:
	case SLATE_EVENT:
	default:
		return Type;
	}
}

FString DTS::DTSArguments::FArgument::GenDTS()
{
	if (bOptional)
		return FString::Printf(TEXT("%s?: %s"), *Name, *GetType());
	else
		return FString::Printf(TEXT("%s: %s"), *Name, *GetType());
}

FString DTS::DTSArguments::GenDTS()
{
	FString Output;
	Output += "\tnamespace ";
	Output += Name;
	Output += " {\n";
	{
		Output += "\t\tclass Arguments {\n";

		for (FArgument Argument : _Arguments)
		{
			Output += "\t\t\t";
			Output += Argument.GenDTS();
			Output += "\n";
		}

		Output += "\t\t}\n";
	}
	Output += "\t}\n";

	return Output;
}