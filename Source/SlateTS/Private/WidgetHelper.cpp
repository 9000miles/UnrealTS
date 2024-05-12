#include "WidgetHelper.h"

FString WidgetHelper::FArgumentsDTS::FArgument::GetType()
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

FString WidgetHelper::FArgumentsDTS::FArgument::GenDTS()
{
	if (bOptional)
		return FString::Printf(TEXT("%s?: %s"), *Name, *GetType());
	else
		return FString::Printf(TEXT("%s: %s"), *Name, *GetType());
}

void WidgetHelper::FArgumentsDTS::Add(FString InName, FString Type, ESlateArgumentType ArgType, const bool bOptional /*= true*/)
{
	Arguments.Add({ InName, Type, bOptional, ArgType });
}

FString WidgetHelper::FArgumentsDTS::GenDTS()
{
	FString Output;
	Output += "\tnamespace ";
	Output += Name;
	Output += " {\n";
	{
		Output += "\t\tclass Arguments {\n";

		for (FArgument Argument : Arguments)
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

FString WidgetHelper::FFunctionDTS::GenDTS()
{
	FString Paras;
	for (FPropertyDTS Para : Parameters)
		Paras += FString::Printf(TEXT("%s, "), *Para.GenDTS());
	if (Paras.Len() > 0)
		Paras.RemoveAt(Paras.Len() - 2, 2);

	FString Output = FString();
	Output += bVirtual ? "/** virtual **/ " : "";
	Output += bStatic ? "static " : "";
	Output += Name;
	Output += FString::Printf(TEXT("(%s)"), *Paras);
	FString Return = ReturnPara.GenDTS();
	Return.RemoveAt(Return.Len() - 2, 2);
	Output += FString::Printf(TEXT(": %s"), *Return);

	return Output;
}

FString WidgetHelper::FPropertyDTS::GenDTS()
{
	FString Output = FString();
	Output += bStatic ? "static " : "";
	Output += bReadonly ? "readonly " : "";
	Output += Name.IsEmpty() ? "" : FString::Printf(TEXT("%s: "), *Name);
	Output += bRef ? FString::Printf(TEXT("$Ref<%s>"), *Type) : Type;
	return Output;
}

FString WidgetHelper::FClassDTS::GenDTS()
{
	FString Output;
	Output += Arguments.GenDTS();

	Output += "\tclass ";
	Output += Name;
	Output += Super.IsEmpty() ? "" : FString::Printf(TEXT(" extends %s"), *Super);
	Output += " {\n";
	{
		for (FPropertyDTS Property : Properties)
		{
			Output += FString::Printf(TEXT("\t\t%s"), *Property.GenDTS());
			Output += ";\n";
		}

		for (FFunctionDTS Function : Functions)
		{
			Output += FString::Printf(TEXT("\t\t%s"), *Function.GenDTS());
			Output += ";\n";
		}
	}
	Output += "\t}\n";

	return Output;
}

void WidgetHelper::FGenWidgetDTS::Add(const FClassDTS& Target)
{
	AllDts.Add(Target);
}

void WidgetHelper::FGenWidgetDTS::GenDTS()
{
	for (FClassDTS& dts : AllDts)
	{
		FString Content = dts.GenDTS();
		FString Filename = FString::Printf(TEXT("M:/UE/5.1/UnrealTSDemo/Plugins/UnrealTS/Source/SlateTS/Typing/%s.d.ts"), *dts.Name);
		FFileHelper::SaveStringToFile(Content, *Filename);
	}
}
