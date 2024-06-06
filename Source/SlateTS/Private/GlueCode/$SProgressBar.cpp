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
#include "Widgets/Notifications/SProgressBar.h"

UsingCppType(SProgressBar);
UsingTSharedPtr(SProgressBar);

namespace $SProgressBar
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SProgressBar::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_STYLE_ARGUMENT(FProgressBarStyle, Style, FProgressBarStyle);
		$SLATE_ARGUMENT(EProgressBarFillType::Type, BarFillType, );
		$SLATE_ARGUMENT(EProgressBarFillStyle::Type, BarFillStyle, );
		$SLATE_ATTRIBUTE(TOptional<float>, Percent, );
		$SLATE_ATTRIBUTE(FSlateColor, FillColorAndOpacity, );
		$SLATE_ATTRIBUTE(FVector2D, BorderPadding, );
		$SLATE_ARGUMENT(const FSlateBrush*, BackgroundImage, );
		$SLATE_ARGUMENT(const FSlateBrush*, FillImage, );
		$SLATE_ARGUMENT(const FSlateBrush*, MarqueeImage, );
		$SLATE_ARGUMENT(float, RefreshRate, );
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

		SProgressBar::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SProgressBar> Widget = MakeTDecl<SProgressBar>("SProgressBar", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SProgressBar>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SProgressBar>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SProgressBar>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SProgressBar>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SProgressBar> Widget = MakeShared<SProgressBar>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SProgressBar>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SProgressBar
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SProgressBar");
		Args.Add<FProgressBarStyle>("Style", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<EProgressBarFillType::Type>("BarFillType", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EProgressBarFillStyle::Type>("BarFillStyle", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<float>>("Percent", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateColor>("FillColorAndOpacity", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FVector2D>("BorderPadding", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<const FSlateBrush*>("BackgroundImage", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<const FSlateBrush*>("FillImage", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<const FSlateBrush*>("MarqueeImage", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("RefreshRate", DTS::EArgType::SLATE_ARGUMENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SProgressBar").Super("SLeafWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SProgressBar.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SProgressBar>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SProgressBar>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SProgressBar.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SProgressBar>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SProgressBar()
	{
		GenDTS();
		RegisterTSharedPtr(SProgressBar);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SProgressBar::$SNew},
			{"SAssignNew", $SProgressBar::$SAssignNew},
			{"MakeShared", $SProgressBar::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SProgressBar";
		Def.TypeId = puerts::StaticTypeId<SProgressBar>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SLeafWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SProgressBar _AutoRegister_SProgressBar;