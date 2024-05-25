#include "DTSHelper.h"

FString DTS::Function::GenDTS()
{
	FString Paras;
	for (Property Para : slot._Parameters)
		Paras += FString::Printf(TEXT("%s, "), *Para.GenDTS());
	if (Paras.Len() > 0)
		Paras.RemoveAt(Paras.Len() - 2, 2);

	FString Output = FString();
	Output += slot._bVirtual ? "/** virtual **/ " : "";
	Output += slot._bStatic ? "static " : "";
	Output += slot._Name;
	Output += FString::Printf(TEXT("(%s)"), *Paras);
	FString Return = slot._Return.GenDTS();
	Output += FString::Printf(TEXT(": %s"), *Return);

	return Output;
}

FString DTS::Property::GenDTS()
{
	FString Output = FString();
	Output += _bStatic ? "static " : "";
	Output += _bReadonly ? "readonly " : "";
	Output += _Name.IsEmpty() ? "" : FString::Printf(TEXT("%s: "), *_Name);
	Output += _bRef ? FString::Printf(TEXT("$Ref<%s>"), *_Type) : _Type;
	return Output;
}

FString DTS::Class::GenDTS()
{
	FString Output;
	Output += _Arguments.GenDTS();

	Output += "\tclass ";
	Output += _Name;
	Output += _Super.IsEmpty() ? "" : FString::Printf(TEXT(" extends %s"), *_Super);
	Output += " {\n";
	{
		for (Property Property : _Properties)
		{
			Output += FString::Printf(TEXT("\t\t%s"), *Property.GenDTS());
			Output += ";\n";
		}

		for (Function Function : _Functions)
		{
			Output += FString::Printf(TEXT("\t\t%s"), *Function.GenDTS());
			Output += ";\n";
		}
	}
	Output += "\t}\n";

	return Output;
}

void DTS::FClassDTS::Add(const Class& Target)
{
	AllDts.Add(Target);
}

void DTS::FClassDTS::GenDTS()
{
	for (Class& dts : AllDts)
	{
		FString Content = dts.GenDTS();
		FString Filename = FString::Printf(TEXT("M:/UE/5.1/UnrealTSDemo/Plugins/UnrealTS/Source/SlateTS/Typing/%s.d.ts"), *dts.GetName());
		FFileHelper::SaveStringToFile(Content, *Filename);
	}
}

