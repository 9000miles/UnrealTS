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
#include "Widgets/Layout/SUniformWrapPanel.h"

UsingCppType(SUniformWrapPanel);
UsingTSharedPtr(SUniformWrapPanel);

namespace $SUniformWrapPanel
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SUniformWrapPanel::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_SLOT_ARGUMENT(FSlot, Slots, );
		$SLATE_ATTRIBUTE(FMargin, SlotPadding, );
		$SLATE_ATTRIBUTE(float, MinDesiredSlotWidth, );
		$SLATE_ATTRIBUTE(float, MinDesiredSlotHeight, );
		$SLATE_ATTRIBUTE(float, MaxDesiredSlotWidth, );
		$SLATE_ATTRIBUTE(float, MaxDesiredSlotHeight, );
		$SLATE_ATTRIBUTE(bool, EvenRowDistribution, );
		$SLATE_ATTRIBUTE(EHorizontalAlignment, HAlign, );
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

		SUniformWrapPanel::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SUniformWrapPanel> Widget = MakeTDecl<SUniformWrapPanel>("SUniformWrapPanel", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SUniformWrapPanel>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SUniformWrapPanel>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SUniformWrapPanel>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SUniformWrapPanel>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SUniformWrapPanel> Widget = MakeShared<SUniformWrapPanel>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SUniformWrapPanel>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SUniformWrapPanel
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SUniformWrapPanel");
		Args.Add<FSlot>("Slots", DTS::EArgType::SLATE_SLOT_ARGUMENT);
		Args.Add<FMargin>("SlotPadding", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("MinDesiredSlotWidth", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("MinDesiredSlotHeight", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("MaxDesiredSlotWidth", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("MaxDesiredSlotHeight", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("EvenRowDistribution", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<EHorizontalAlignment>("HAlign", DTS::EArgType::SLATE_ATTRIBUTE);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SUniformWrapPanel").Super("SPanel")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SUniformWrapPanel.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SUniformWrapPanel>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SUniformWrapPanel>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SUniformWrapPanel.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SUniformWrapPanel>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SUniformWrapPanel()
	{
		GenDTS();
		RegisterTSharedPtr(SUniformWrapPanel);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SUniformWrapPanel::$SNew},
			{"SAssignNew", $SUniformWrapPanel::$SAssignNew},
			{"MakeShared", $SUniformWrapPanel::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SUniformWrapPanel";
		Def.TypeId = puerts::StaticTypeId<SUniformWrapPanel>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SPanel>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SUniformWrapPanel _AutoRegister_SUniformWrapPanel;