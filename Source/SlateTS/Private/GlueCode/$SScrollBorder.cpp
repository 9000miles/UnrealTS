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
#include "Widgets/Layout/SScrollBorder.h"
#include "Framework/Layout/IScrollableWidget.h"

UsingCppType(SScrollBorder);
UsingTSharedPtr(SScrollBorder);

namespace $SScrollBorder
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SScrollBorder::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_STYLE_ARGUMENT(FScrollBorderStyle, Style, FScrollBorderStyle);
		$SLATE_ATTRIBUTE(FVector2D, BorderFadeDistance, );
		$SLATE_DEFAULT_SLOT(FArguments, Content, );
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

		SScrollBorder::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedRef<IScrollableWidget> InScrollableWidget = MakeShared<IScrollableWidget>();//@TODO
		TSharedPtr<SScrollBorder> Widget = MakeTDecl<SScrollBorder>("SScrollBorder", TCHAR_TO_ANSI(*Filename), 1, RequiredArgs::MakeRequiredArgs(InScrollableWidget)) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SScrollBorder>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SScrollBorder>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SScrollBorder>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SScrollBorder>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SScrollBorder> Widget = MakeShared<SScrollBorder>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SScrollBorder>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SScrollBorder
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SScrollBorder");
		Args.Add<FScrollBorderStyle>("Style", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FVector2D>("BorderFadeDistance", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FArguments>("Content", DTS::EArgType::SLATE_DEFAULT_SLOT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SScrollBorder").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SScrollBorder.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SScrollBorder>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SScrollBorder>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SScrollBorder.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SScrollBorder>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SScrollBorder()
	{
		GenDTS();
		RegisterTSharedPtr(SScrollBorder);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SScrollBorder::$SNew},
			{"SAssignNew", $SScrollBorder::$SAssignNew},
			{"MakeShared", $SScrollBorder::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SScrollBorder";
		Def.TypeId = puerts::StaticTypeId<SScrollBorder>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SScrollBorder _AutoRegister_SScrollBorder;