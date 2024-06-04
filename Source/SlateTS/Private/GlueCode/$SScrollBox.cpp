#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "DTSDefine.h"
#include "TypeInfo.hpp"
#include "UEDataBinding.hpp"
#include "Helper/WidgetHelper.hpp"
#include "DTSHelper.h"
#include "DTSDefine.h"
#include "PuertsEx.h"

UsingCppType(SScrollBox);
UsingTSharedPtr(SScrollBox);

namespace $SScrollBox
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SScrollBox::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_SLOT_ARGUMENT(Slots);
		$SLATE_STYLE_ARGUMENT(Style);
		$SLATE_STYLE_ARGUMENT(ScrollBarStyle);
		$SLATE_ARGUMENT(ExternalScrollbar);
		$SLATE_ARGUMENT(Orientation);
		$SLATE_ARGUMENT(ScrollBarVisibility);
		$SLATE_ARGUMENT(ScrollBarAlwaysVisible);
		$SLATE_ARGUMENT(ScrollBarDragFocusCause);
		$SLATE_ARGUMENT(ScrollBarThickness);
		$SLATE_ARGUMENT(ScrollBarPadding);
		$SLATE_ARGUMENT(AllowOverscroll);
		$SLATE_ARGUMENT(BackPadScrolling);
		$SLATE_ARGUMENT(FrontPadScrolling);
		$SLATE_ARGUMENT(AnimateWheelScrolling);
		$SLATE_ARGUMENT(WheelScrollMultiplier);
		$SLATE_ARGUMENT(NavigationDestination);
		$SLATE_ARGUMENT(NavigationScrollPadding);
		$SLATE_ARGUMENT(ScrollWhenFocusChanges);
		$SLATE_EVENT(OnUserScrolled);
		$SLATE_ARGUMENT(ConsumeMouseWheel);
	}

	static void $SNew(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		const uint8 InfoLength = Info.Length();
		if (InfoLength <= 1) { puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!"); return; }

		uint8 ExposeIndex = InfoLength == 3 ? 0 : -1;
		uint8 ArgumentsIndex = InfoLength == 3 ? 1 : 0;
		uint8 FilenameIndex = InfoLength == 3 ? 2 : 1;

		SScrollBox::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SScrollBox> Widget = MakeTDecl<SScrollBox>("SScrollBox", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SScrollBox>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SScrollBox>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SScrollBox>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SScrollBox>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SScrollBox> Widget = MakeShared<SScrollBox>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SScrollBox>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SScrollBox
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SScrollBox");
		Args.Add<FSlot>("Slots", DTS::EArgType::SLATE_SLOT_ARGUMENT);
		Args.Add<FScrollBoxStyle>("Style", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FScrollBarStyle>("ScrollBarStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<TSharedPtr<SScrollBar>>("ExternalScrollbar", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EOrientation>("Orientation", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EVisibility>("ScrollBarVisibility", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("ScrollBarAlwaysVisible", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EFocusCause>("ScrollBarDragFocusCause", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FVector2D>("ScrollBarThickness", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FMargin>("ScrollBarPadding", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EAllowOverscroll>("AllowOverscroll", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("BackPadScrolling", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("FrontPadScrolling", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("AnimateWheelScrolling", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("WheelScrollMultiplier", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EDescendantScrollDestination>("NavigationDestination", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("NavigationScrollPadding", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EScrollWhenFocusChanges>("ScrollWhenFocusChanges", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FOnUserScrolled>("OnUserScrolled", DTS::EArgType::SLATE_EVENT);
		Args.Add<EConsumeMouseWheel>("ConsumeMouseWheel", DTS::EArgType::SLATE_ARGUMENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SScrollBox").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SScrollBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SScrollBox>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SScrollBox>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SScrollBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SScrollBox>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SScrollBox()
	{
		GenDTS();
		RegisterTSharedPtr(SScrollBox);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SScrollBox::$SNew},
			{"SAssignNew", $SScrollBox::$SAssignNew},
			{"MakeShared", $SScrollBox::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SScrollBox";
		Def.TypeId = puerts::StaticTypeId<SScrollBox>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SScrollBox _AutoRegister_SScrollBox;