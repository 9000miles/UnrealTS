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

UsingCppType(SSplitter);
UsingTSharedPtr(SSplitter);

namespace $SSplitter
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SSplitter::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_SLOT_ARGUMENT(FSlot, Slots, );
		$SLATE_STYLE_ARGUMENT(FSplitterStyle, Style, FSplitterStyle);
		$SLATE_ARGUMENT(EOrientation, Orientation, );
		$SLATE_ARGUMENT(ESplitterResizeMode::Type, ResizeMode, );
		$SLATE_ARGUMENT(float, PhysicalSplitterHandleSize, );
		$SLATE_ARGUMENT(float, HitDetectionSplitterHandleSize, );
		$SLATE_ARGUMENT(float, MinimumSlotHeight, );
		$SLATE_ATTRIBUTE(int32, HighlightedHandleIndex, );
		$SLATE_EVENT(FOnHandleHovered, OnHandleHovered, );
		$SLATE_EVENT(FSimpleDelegate, OnSplitterFinishedResizing, );
		$SLATE_EVENT(FOnGetMaxSlotSize, OnGetMaxSlotSize, );
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

		SSplitter::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SSplitter> Widget = MakeTDecl<SSplitter>("SSplitter", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SSplitter>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SSplitter>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SSplitter>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SSplitter>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SSplitter> Widget = MakeShared<SSplitter>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SSplitter>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SSplitter
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SSplitter");
		Args.Add<FSlot>("Slots", DTS::EArgType::SLATE_SLOT_ARGUMENT);
		Args.Add<FSplitterStyle>("Style", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<EOrientation>("Orientation", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<ESplitterResizeMode::Type>("ResizeMode", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("PhysicalSplitterHandleSize", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("HitDetectionSplitterHandleSize", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("MinimumSlotHeight", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<int32>("HighlightedHandleIndex", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnHandleHovered>("OnHandleHovered", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnSplitterFinishedResizing", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnGetMaxSlotSize>("OnGetMaxSlotSize", DTS::EArgType::SLATE_EVENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SSplitter").Super("SPanel")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SSplitter.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SSplitter>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SSplitter>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SSplitter.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SSplitter>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SSplitter()
	{
		GenDTS();
		RegisterTSharedPtr(SSplitter);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SSplitter::$SNew},
			{"SAssignNew", $SSplitter::$SAssignNew},
			{"MakeShared", $SSplitter::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SSplitter";
		Def.TypeId = puerts::StaticTypeId<SSplitter>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SPanel>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SSplitter _AutoRegister_SSplitter;