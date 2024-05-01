#include "CoreMinimal.h"
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"

#define SET_WIDGET_ARGUMENT_VARIABLE(Name);\
WidgetArgument::Set_##Name(Arguments, JsObject, #Name)

namespace WidgetArgument
{
	template<typename TArgumentType>
	void Set_Text(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;



		//v8::Local<v8::Object> JsValue1 = JsObject.GetJsObject();
		//v8::Local<v8::String> Type1 = JsValue1->TypeOf(JsObject.GetIsolate());
		//FString TypeString1 = puerts::FV8Utils::ToFString(JsObject.GetIsolate(), Type1);

		//Arguments._Text = WidgetAttribute::MakeAttribute_4<FText>(JsObject, Value);
		//return;

		//auto Context = GContext.Get(JsObject.GetIsolate());


		//v8::Object StringValue = Value.As<v8::Object>();
		//v8::Local<v8::Object> StringValue = v8::Local<v8::Local<v8::Object>>::Cast(*Value);

		v8::Local<v8::Object> Object = Value.As<v8::Object>();
		FJsObject JsText = FJsObject(JsObject.GetContext(), Object);


		//FJsObject ArgJsObject = FJsObject(JsObject.GetContext(), Value);
		Arguments._Text = WidgetAttribute::MakeAttribute_3<FText>(JsText);
		//Arguments._Text = WidgetAttribute::MakeAttribute1<FText>(JsObject.GetIsolate(), JsObject.GetContext(), Value);
		return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.Text(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._Text.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_TextStyle(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_Font(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_StrikeBrush(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_ColorAndOpacity(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			std::string std_str = JsObject.Get<std::string>(VariableName);
			FColor Color = StringConverter::Converter<FColor>(std_str);
			Arguments.ColorAndOpacity(Color);
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FSlateColor>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					FSlateColor ColorRet = Function.Func_CallBack<FSlateColor>([](v8::Local<v8::Context> Context, v8::Local<v8::Value> MaybeRet)
						{
							if (MaybeRet->IsString())
							{
								std::string std_str = puerts::converter::Converter<std::string>::toCpp(Context, MaybeRet);
								FColor Color = StringConverter::Converter<FColor>(std_str);
								return FSlateColor(Color);
							}
							if (MaybeRet->IsObject())
							{
								// @TODO 判断对象类型，是否是FLinearColor实例
								FLinearColor LinearColor = puerts::converter::Converter<FLinearColor>::toCpp(Context, MaybeRet);
								return FSlateColor(LinearColor);

								// 如果不是则从{ R: number, G: number, B:number, A: number }取值
							}

							return FSlateColor();
						});

					return ColorRet;
				});
			Arguments._ColorAndOpacity.Bind(Getter);
		}
		else if (Value->IsObject())
		{
			FLinearColor ColorAndOpacity = JsObject.Get<FLinearColor>(VariableName);
			Arguments.ColorAndOpacity(ColorAndOpacity);
		}
	}
	template<typename TArgumentType>
	void Set_ShadowOffset(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_ShadowColorAndOpacity(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_HighlightColor(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_HighlightShape(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_HighlightText(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_WrapTextAt(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_AutoWrapText(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_WrappingPolicy(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_TransformPolicy(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_Margin(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_LineHeightPercentage(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_Justification(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_MinDesiredWidth(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_TextShapingMethod(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_TextFlowDirection(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_LineBreakPolicy(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_OverflowPolicy(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_SimpleTextMode(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_OnDoubleClicked(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		if (Value->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Value->IsFunction())
		{
			auto Function = JsObject.Get<FJsObject>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}



	template<typename TArgumentType>
	void Set_OnClicked(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

		auto Func = JsObject.Get<std::function<void()>>(VariableName);
		Arguments._OnClicked.BindLambda([Func]() { Func(); return FReply::Handled(); });
	}

};

namespace WidgetAttribute
{
	template<typename TType>
	TAttribute<TType> MakeAttribute_4(FJsObject& JsObject, v8::Local<v8::Value> Value) { return TAttribute<TType>(); }
	template<>
	TAttribute<FText> MakeAttribute_4(FJsObject& InJsObject, v8::Local<v8::Value> InValue)
	{
		v8::Local<v8::Object> JsValue1 = InJsObject.GetJsObject();
		v8::Local<v8::String> Type1 = JsValue1->TypeOf(InJsObject.GetIsolate());
		FString TypeString1 = puerts::FV8Utils::ToFString(InJsObject.GetIsolate(), Type1);

		FJsObject JsObject = InJsObject;
		v8::Local<v8::Object> JsValue = InValue.As<v8::Object>();
		if (InValue->IsUndefined())
		{
			v8::Local<v8::Object> Object = InValue.As<v8::Object>();
			JsObject = FJsObject(InJsObject.GetContext(), Object);
			JsValue = JsObject.GetJsObject();
		}

		v8::Local<v8::String> Type = JsValue->TypeOf(InJsObject.GetIsolate());
		FString TypeString = puerts::FV8Utils::ToFString(InJsObject.GetIsolate(), Type);

		if (JsValue->IsString())
		{
			FString TextString = puerts::FV8Utils::ToFString(JsObject.GetIsolate(), JsValue);
			FText Text = FText::FromString(TextString);
			return TAttribute<FText>(Text);
		}
		else if (JsValue->IsFunction())
		{
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([&JsObject]()
				{
					std::string Ret = JsObject.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			return TAttribute<FText>::Create(Getter);
		}
		return TAttribute<FText>();
	}


	template<typename TType>
	TAttribute<TType> MakeAttribute_3(FJsObject& JsObject) { return TAttribute<TType>(); }
	template<>
	TAttribute<FText> MakeAttribute_3(FJsObject& JsObject)
	{

		v8::Local<v8::Object> Value = JsObject.GetJsObject();

		//v8::Local<v8::Object> JsValue1 = JsObject.GetJsObject();
		v8::Local<v8::String> Type1 = Value->TypeOf(JsObject.GetIsolate());
		FString TypeString1 = puerts::FV8Utils::ToFString(JsObject.GetIsolate(), Type1);

		if (Value->IsString())
		{
			FString TextString = puerts::FV8Utils::ToFString(JsObject.GetIsolate(), Value);
			FText Text = FText::FromString(TextString);
			return TAttribute<FText>(Text);
		}
		else if (Value->IsFunction())
		{
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([JsObject]()
				{
					std::string Ret = JsObject.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			return TAttribute<FText>::Create(Getter);
		}
		return TAttribute<FText>();
	}

	template<typename TType>
	TAttribute<TType> MakeAttribute1(v8::Isolate* Isolate, v8::Local<v8::Context> Context, v8::Local<v8::Value> Value) { return TAttribute<TType>(); }
	template<>
	TAttribute<FText> MakeAttribute1(v8::Isolate* Isolate, v8::Local<v8::Context> Context, v8::Local<v8::Value> Value)
	{
		if (Value->IsString())
		{
			FString TextString = puerts::FV8Utils::ToFString(Isolate, Value);
			FText Text = FText::FromString(TextString);
			return TAttribute<FText>(Text);
		}
		else if (Value->IsFunction())
		{
			v8::Local<v8::Function> Function = Value.As<v8::Function>();
			FJsObject JsObject = FJsObject(Context, Function);
			std::string Ret = JsObject.Func<std::string>();

			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function, &Context, Isolate]()
				{
					v8::MaybeLocal<v8::Value> MaybeRet = Function->Call(Context, v8::Undefined(Isolate), 0, nullptr);
					std::string std_str = puerts::converter::Converter<std::string>::toCpp(Context, MaybeRet.ToLocalChecked());
					FString String = UTF8_TO_TCHAR(std_str.c_str());
					return FText::FromString(String);
				});
			return TAttribute<FText>::Create(Getter);

			Getter.BindLambda([Value, &Context]()
				{
					v8::Local<v8::Function> Function = Value.As<v8::Function>();
					FJsObject JsObject = FJsObject(Context, Function);
					std::string Ret = JsObject.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			return TAttribute<FText>::Create(Getter);

			//v8::Local<v8::Context> Context = Isolate->GetIncumbentContext();
			//v8::Local<v8::Function> Function = Value.As<v8::Function>();
			//TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function, Context, Isolate]()
				{
					v8::Isolate::Scope IsolateScope(Isolate);
					v8::HandleScope HandleScope(Isolate);
					//auto Context = GContext.Get(Isolate);
					v8::Context::Scope ContextScope(Context);

					v8::MaybeLocal<v8::Value> MaybeRet = Function->Call(Context, v8::Undefined(Isolate), 0, nullptr);
					std::string std_str = puerts::converter::Converter<std::string>::toCpp(Context, MaybeRet.ToLocalChecked());
					FString String = UTF8_TO_TCHAR(std_str.c_str());
					return FText::FromString(String);
				});
			return TAttribute<FText>::Create(Getter);
		}

		return TAttribute<FText>();
	}


	template<typename TType>
	TAttribute<TType> MakeAttribute0(FJsObject JsObject) { return TAttribute<TType>(); }
	template<>
	TAttribute<FText> MakeAttribute0(FJsObject JsObject)
	{
		return MakeAttribute1<FText>(JsObject.GetIsolate(), JsObject.GetContext(), JsObject.GetJsObject());
	}

	template<typename TType>
	TAttribute<TType> MakeAttribute(FJsObject JsObject) { return TAttribute<TType>(); }
	template<>
	TAttribute<FText> MakeAttribute(FJsObject JsObject)
	{
		if (JsObject.GetJsObject()->IsString())
		{
			FString TextString = puerts::FV8Utils::ToFString(JsObject.GetIsolate(), JsObject.GetJsObject());
			FText Text = FText::FromString(TextString);
			return TAttribute<FText>(Text);
		}
		else if (JsObject.GetJsObject()->IsFunction())
		{
			auto Function = JsObject;
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Function]()
				{
					std::string Ret = Function.Func<std::string>();
					FString String = UTF8_TO_TCHAR(Ret.c_str());
					return FText::FromString(String);
				});
			return TAttribute<FText>::Create(Getter);
		}

		return TAttribute<FText>();
	}
};
