#pragma once

#include "CoreMinimal.h"
#include "DTSDefine.h"
#include "Widgets/Input/SSearchBox.h"
#include "WebBrowser/Public/IWebBrowserSingleton.h"
#include "AppFramework/Public/Widgets/Colors/SColorPicker.h"
#include "Framework/Text/SlateTextLayout.h"
#include "Widgets/SWindow.h"
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
		template<> void Add<FArguments>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "() => cpp.TSharedRtr<SWidget>", bOptional, ArgType });
		}
		template<> void Add<FSlot>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "cpp.WidgetSlot", bOptional, ArgType });
		}
		template<> void Add<FVector4>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "UE.Vector4", bOptional, ArgType });
		}
		template<> void Add<FSceneViewport*>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "cpp.FSceneViewport", bOptional, ArgType });
		}
		template<> void Add<APlayerController>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "UE.PlayerController", bOptional, ArgType });
		}
		//template<> void Add<EVisibility>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
		//	_Arguments.Add({ InName, "UE.PlayerController", bOptional, ArgType });
		//}

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

		/** TDelegate **/
		template<> void Add<TDelegate<FReply()>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "() => cpp.FReply", bOptional, ArgType });
		}
		template<> void Add<TDelegate<FReply(const FGeometry&, const FPointerEvent&)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(Geometry: UE.Geometry, PointerEvent : UE.PointerEvent) => cpp.FReply", bOptional, ArgType });
		}
		template<> void Add<TDelegate<FReply(const FGeometry&, const FKeyEvent&)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(Geometry: UE.Geometry, KeyEvent: UE.KeyEvent) => cpp.FReply", bOptional, ArgType });
		}
		template<> void Add<TDelegate<FReply(const FGeometry&, const FCharacterEvent&)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(Geometry: UE.Geometry, CharacterEvent: UE.CharacterEvent) => cpp.FReply", bOptional, ArgType });
		}

		template<> void Add<TDelegate<TSharedRef<SWidget, ESPMode::ThreadSafe>()>>(FString InName, DTS::EArgType ArgType, const bool bOptional)
		{
			_Arguments.Add({ InName, "() => cpp.TSharedRef<SWidget>", bOptional, ArgType });
		}
		template<> void Add<TDelegate<TSharedRef<SDockTab, ESPMode::ThreadSafe>()>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "() => cpp.TSharedRef<SDockTab>", bOptional, ArgType });
		}
		template<> void Add<TDelegate<TSharedRef<FSlateTextLayout, ESPMode::ThreadSafe>(SWidget*, const FTextBlockStyle&)>>(FString InName, DTS::EArgType ArgType, const bool bOptional)
		{
			_Arguments.Add({ InName, "(Widget: cpp.SWidget, Style: UE.TextBlockStyle) => cpp.TSharedRef<cpp.FSlateTextLayout>", bOptional, ArgType });
		}

		template<> void Add<TDelegate<TSharedPtr<SWidget, ESPMode::ThreadSafe>()>>(FString InName, DTS::EArgType ArgType, const bool bOptional)
		{
			_Arguments.Add({ InName, "() => cpp.TSharedPtr<SWidget>", bOptional, ArgType });
		}

		template<> void Add<TDelegate<bool()>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "() => bool", bOptional, ArgType });
		}
		template<> void Add<TDelegate<bool(const TCHAR)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(V: string) => bool", bOptional, ArgType });
		}
		template<> void Add<TDelegate<bool(const FText&, FText&)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(V1: string, V2: string) => bool", bOptional, ArgType });
		}
		template<> void Add<TDelegate<bool(FFrameRate)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(V: UE.FFrameRate) => bool", bOptional, ArgType });
		}
		template<> void Add<TDelegate<bool(FVector4&)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(V: UE.Vector4) => bool", bOptional, ArgType });
		}

		template<> void Add<TDelegate<void()>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "() => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(bool)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(V: boolean) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(float)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(V: number) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(const FText&)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(text: string) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(const FLinearColor&)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(Color: UE.LinearColor) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(const FTextLocation&)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(Color: UE.FTextLocation) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(const FInputChord&)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(Color: UE.InputChord) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(const TSharedRef<SWindow>&)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(Window: cpp.TSharedRef<cpp.SWindow>) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(const FText&, ETextCommit::Type)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(text: string, commitType: string) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(int32)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(V: number) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(FFrameRate)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(V: UE.FFrameRate) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(FVector4&, bool)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(V1: UE.Vector4, V2: boolean) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(FVector4&)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(V1: UE.Vector4) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(ECheckBoxState)>>(FString InName, DTS::EArgType ArgType, const bool bOptional)
		{
			_Arguments.Add({ InName, "(InNewState: UE.ECheckBoxState) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(FMenuBuilder&)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(MenuBuilder: cpp.FMenuBuilder) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(FLinearColor)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(Color: UE.LinearColor) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(TSharedRef<SDockTab>)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(DockTab: cpp.TSharedRef<SDockTab>) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(TSharedRef<SWindow>&)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(Window: cpp.TSharedRef<SWindow>) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(TSharedPtr<SDockTab>, ETabActivationCause)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(DockTab: cpp.TSharedPtr<SDockTab>, TabActivationCause: cpp.ETabActivationCause) => void", bOptional, ArgType });
		}
		template<> void Add<TDelegate<void(TSharedRef<SDockTab>, ETabActivationCause)>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "(DockTab: cpp.TSharedRef<SDockTab>, TabActivationCause: cpp.ETabActivationCause) => void", bOptional, ArgType });
		}
		/** TDelegate **/

		template<> void Add<FOptionalSize>(FString InName, DTS::EArgType ArgType, const bool bOptional)
		{
			_Arguments.Add({ InName, TS_number, bOptional, ArgType });
		}
		template<> void Add<SSearchBox::FSearchResultData>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "cpp.FSearchResultData", bOptional, ArgType });
		}
		template<> void Add<FBrowserContextSettings>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "cpp.FBrowserContextSettings", bOptional, ArgType });
		}

#define ADD_TSharedPtr(Type)\
		template<> void Add<TSharedPtr<Type>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {\
			Add<Type>(InName, ArgType, bOptional);\
		}
		ADD_TSharedPtr(SWindow);


		template<> void Add<TArray<FColor*>>(FString InName, DTS::EArgType ArgType, const bool bOptional) {
			_Arguments.Add({ InName, "UE.TArray<UE.Color>", bOptional, ArgType });
		}

		FString GenDTS();

	private:
		FString Name;
		TArray<FArgument> _Arguments;
	};
}