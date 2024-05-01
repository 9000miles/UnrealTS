#include "CoreMinimal.h"

namespace StringConverter
{
	template<typename TType>
	TType Converter(std::string std_str)
	{
		return nullptr;
	}
	template<>
	FColor Converter<FColor>(std::string std_str)
	{
		FString String = FString(std_str.c_str());
		if (String.StartsWith(TEXT("#")))//"#5dc513"
		{
			return FColor::FromHex(String);
		}
		else if (String.StartsWith(TEXT("rgba")))//"rgba(128,19,115,0.3)"
		{
			FString RGBAStripped = String.Mid(5, String.Len() - 6);
			TArray<FString> RGBAValues;
			RGBAStripped.ParseIntoArray(RGBAValues, TEXT(","));

			uint8 R = FCString::Atoi(*RGBAValues[0]);
			uint8 G = FCString::Atoi(*RGBAValues[1]);
			uint8 B = FCString::Atoi(*RGBAValues[2]);
			uint8 A = FCString::Atoi(*RGBAValues[3]);

			return FColor(R, G, B, A);
		}
		else if (String.StartsWith(TEXT("rgb")))//"rgb(128,19,115)"
		{
			FString RGBAStripped = String.Mid(4, String.Len() - 5);
			TArray<FString> RGBAValues;
			RGBAStripped.ParseIntoArray(RGBAValues, TEXT(","));

			uint8 R = FCString::Atoi(*RGBAValues[0]);
			uint8 G = FCString::Atoi(*RGBAValues[1]);
			uint8 B = FCString::Atoi(*RGBAValues[2]);

			return FColor(R, G, B, 255);
		}

		return FColor();
	}
};