#pragma once

#include "CoreMinimal.h"
#include "DTSDefine.h"

namespace DTS
{
	struct DTSArguments
	{
		struct FArgument
		{
			FString Name;
			FString Type;
			bool bOptional = true;
			ESlateArgumentType ArgType;
		private:
			FString GetType();
		public:
			FString GenDTS();
		};

		DTSArguments(FString InName) :Name(InName) {}

		template<typename T> void Add(FString InName, ESlateArgumentType ArgType, const bool bOptional = true) { _Arguments.Add({ InName, puerts::ScriptTypeNameWithNamespace<T>::value().Data(), bOptional, ArgType }); }
		template<> void Add<FOnClicked>(FString InName, ESlateArgumentType ArgType, const bool bOptional) { _Arguments.Add({ InName, "cpp.FReply", bOptional, ArgType }); } 	
		template<> void Add<FSimpleDelegate>(FString InName, ESlateArgumentType ArgType, const bool bOptional) { _Arguments.Add({ InName, "() => void", bOptional, ArgType }); } 	
		template<> void Add<FPointerEventHandler>(FString InName, ESlateArgumentType ArgType, const bool bOptional) { _Arguments.Add({ InName, "(Geometry: UE.Geometry, PointerEvent : UE.PointerEvent) => cpp.FReply", bOptional, ArgType }); }
		template<> void Add<FOnCheckStateChanged>(FString InName, ESlateArgumentType ArgType, const bool bOptional) { _Arguments.Add({ InName, "(UE.ECheckBoxState InNewState) => void", bOptional, ArgType }); }
		template<> void Add<FOnGetContent>(FString InName, ESlateArgumentType ArgType, const bool bOptional) { _Arguments.Add({ InName, "() => cpp.TSharedRef<SWidget>", bOptional, ArgType }); }

		FString GenDTS();

	private:
		FString Name;
		TArray<FArgument> _Arguments;
	};
}