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
#include "Widgets/Layout/SBox.h"

UsingCppType(SBox);
UsingTSharedPtr(SBox);

namespace $SBox
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SBox::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		SET_VARIABLE__SLATE_ARGUMENT(HAlign);
		SET_VARIABLE__SLATE_ARGUMENT(VAlign);
		SET_VARIABLE__SLATE_ATTRIBUTE(Padding);
		SET_VARIABLE__SLATE_DEFAULT_SLOT(Content);
		SET_VARIABLE__SLATE_ATTRIBUTE(WidthOverride);
		SET_VARIABLE__SLATE_ATTRIBUTE(HeightOverride);
		SET_VARIABLE__SLATE_ATTRIBUTE_WITH_TYPE(MinDesiredWidth, FOptionalSize);
		SET_VARIABLE__SLATE_ATTRIBUTE(MinDesiredHeight);
		SET_VARIABLE__SLATE_ATTRIBUTE(MaxDesiredWidth);
		SET_VARIABLE__SLATE_ATTRIBUTE(MaxDesiredHeight);
		SET_VARIABLE__SLATE_ATTRIBUTE(MinAspectRatio);
		SET_VARIABLE__SLATE_ATTRIBUTE(MaxAspectRatio);
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

		SBox::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SBox> Widget = MakeTDecl<SBox>("SBox", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SBox>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SBox>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SBox>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SBox>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SBox> Widget = MakeShared<SBox>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SBox>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SBox
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SBox");
		Args.Add<EHorizontalAlignment>("HAlign", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EVerticalAlignment>("VAlign", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FMargin>("Padding", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<DTS::FSlate_Default_Slot>("Content", DTS::EArgType::SLATE_DEFAULT_SLOT);
		Args.Add<FOptionalSize>("WidthOverride", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOptionalSize>("HeightOverride", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOptionalSize>("MinDesiredWidth", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOptionalSize>("MinDesiredHeight", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOptionalSize>("MaxDesiredWidth", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOptionalSize>("MaxDesiredHeight", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOptionalSize>("MinAspectRatio", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOptionalSize>("MaxAspectRatio", DTS::EArgType::SLATE_ATTRIBUTE);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SBox").Super("SPanel")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SBox>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SBox>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SBox>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SBox()
	{
		GenDTS();
		RegisterTSharedPtr(SBox);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SBox::$SNew},
			{"SAssignNew", $SBox::$SAssignNew},
			{"MakeShared", $SBox::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SBox";
		Def.TypeId = puerts::StaticTypeId<SBox>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SPanel>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SBox _AutoRegister_SBox;