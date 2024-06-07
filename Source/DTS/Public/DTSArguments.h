#pragma once

#include "CoreMinimal.h"
#include "DTSDefine.h"
#include "Widgets/Input/SSearchBox.h"
#include "WebBrowser/Public/IWebBrowserSingleton.h"
//#include "PuertsEx.h"

namespace DTS
{
	struct DTSArguments
	{
		struct FArgument
		{
			FString Name;
			FString Type;
			bool bOptional = true;
			EArgType ArgType;
		private:
			FString GetType();
		public:
			FString GenDTS();
		};

		DTSArguments(FString InName) :Name(InName) {}

		template<typename T> void Add(FString InName, DTS::EArgType ArgType, const bool bOptional = true)
		{
			_Arguments.Add({ InName, puerts::ScriptTypeNameWithNamespace<T>::value().Data(), bOptional, ArgType });
		}
		template<> void Add<FArguments>(FString InName, DTS::EArgType ArgType, const bool bOptional)
		{
			_Arguments.Add({ InName, "() => cpp.TSharedRtr<SWidget>", bOptional, ArgType });
		}

#define ADD_TOptional(Type)\
		template<> void Add<TOptional<Type>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {\
			Add<Type>(InName, ArgType, bOptional);\
		}
		ADD_TOptional(int32);
		ADD_TOptional(FSlateSound);
		ADD_TOptional(ETextShapingMethod);
		ADD_TOptional(ETextFlowDirection);
		ADD_TOptional(ESlateCheckBoxType::Type);
		ADD_TOptional(float);
		ADD_TOptional(bool);
		ADD_TOptional(EPopupMethod);
		ADD_TOptional(FVector2D);
		ADD_TOptional(ETextOverflowPolicy);
		ADD_TOptional(EMouseCursor::Type);
		ADD_TOptional(FMargin);
		ADD_TOptional(double);
		ADD_TOptional(SSearchBox::FSearchResultData);
		ADD_TOptional(EVisibility);
		ADD_TOptional(FString);
		ADD_TOptional(FBrowserContextSettings);


#define ADD_TWeakObjectPtr(Type)\
		template<> void Add<TWeakObjectPtr<Type>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {\
			Add<Type>(InName, ArgType, bOptional);\
		}
		ADD_TWeakObjectPtr(APlayerController);

		template<> void Add<FSimpleDelegate>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "() => void", bOptional, ArgType });
		}

		template<> void Add<TDelegate<FReply()>>(FString InName, DTS::EArgType ArgType, const bool bOptional)
		{
			_Arguments.Add({ InName, "() => cpp.FReply", bOptional, ArgType });
		}
		template<> void Add<TDelegate<FReply(const FGeometry&, const FPointerEvent&)>>(FString InName, DTS::EArgType ArgType, const bool bOptional)
		{
			_Arguments.Add({ InName, "(Geometry: UE.Geometry, PointerEvent : UE.PointerEvent) => cpp.FReply", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(ECheckBoxState)>>(FString InName, DTS::EArgType ArgType, const bool bOptional)
		{
			_Arguments.Add({ InName, "(UE.ECheckBoxState: InNewState) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<TSharedRef<SWidget, ESPMode::ThreadSafe>()>>(FString InName, DTS::EArgType ArgType, const bool bOptional)
		{
			_Arguments.Add({ InName, "() => cpp.TSharedRef<SWidget>", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(bool)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(boolean: V) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(int32)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(number: V) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<bool(const TCHAR)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(string: V) => bool", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(FFrameRate)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(UE.FFrameRate: V) => void", bOptional, ArgType });
		}

		template<> void Add<FOptionalSize>(FString InName, DTS::EArgType ArgType, const bool bOptional)
		{
			_Arguments.Add({ InName, TS_number, bOptional, ArgType });
		}
		template<> void Add<SSearchBox::FSearchResultData>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "Cpp.FSearchResultData", bOptional, ArgType });
		}
		template<> void Add<FBrowserContextSettings>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "Cpp.FBrowserContextSettings", bOptional, ArgType });
		}

		FString GenDTS();

	private:
		FString Name;
		TArray<FArgument> _Arguments;
	};
}