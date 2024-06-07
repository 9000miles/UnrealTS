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
#include "Widgets/Views/SExpanderArrow.h"
#include "Widgets/Views/ITableRow.h"

UsingCppType(SExpanderArrow);
UsingTSharedPtr(SExpanderArrow);

namespace $SExpanderArrow
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SExpanderArrow::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ARGUMENT(const ISlateStyle*, StyleSet, );
		$SLATE_ATTRIBUTE(float, IndentAmount, );
		$SLATE_ATTRIBUTE(int32, BaseIndentLevel, );
		$SLATE_ATTRIBUTE(bool, ShouldDrawWires, );
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

		SExpanderArrow::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<class ITableRow> TableRow;//@TODO 从Info里面获取值
		TSharedPtr<SExpanderArrow> Widget = MakeTDecl<SExpanderArrow>("SExpanderArrow", TCHAR_TO_ANSI(*Filename), 1, RequiredArgs::MakeRequiredArgs(TableRow)) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SExpanderArrow>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SExpanderArrow>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SExpanderArrow>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SExpanderArrow>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SExpanderArrow> Widget = MakeShared<SExpanderArrow>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SExpanderArrow>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SExpanderArrow
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SExpanderArrow");
		Args.Add<const ISlateStyle*>("StyleSet", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("IndentAmount", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<int32>("BaseIndentLevel", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("ShouldDrawWires", DTS::EArgType::SLATE_ATTRIBUTE);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SExpanderArrow").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SExpanderArrow.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SExpanderArrow>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SExpanderArrow>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SExpanderArrow.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SExpanderArrow>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SExpanderArrow()
	{
		GenDTS();
		RegisterTSharedPtr(SExpanderArrow);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SExpanderArrow::$SNew},
			{"SAssignNew", $SExpanderArrow::$SAssignNew},
			{"MakeShared", $SExpanderArrow::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SExpanderArrow";
		Def.TypeId = puerts::StaticTypeId<SExpanderArrow>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SExpanderArrow _AutoRegister_SExpanderArrow;