#include "CoreMinimal.h"
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"

#define SET_WIDGET_ARGUMENT_VARIABLE(Name);\
WidgetArgument::Set_##Name(Arguments, JsObject, #Name)

namespace WidgetArgument
{
	template<typename TArgumentType>
	void Set_Text(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Value;
		if (!JsObject.Has(VariableName, Value)) return;

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

namespace WidgetFunctionCall
{
	template<typename TType>
	TAttribute<TType> MakeAttribute(FJsObject JsObject)
	{
		if (JsObject.GetJsObject()->IsString())
		{

		}

		return TAttribute<TType>();
	}
	template<>
	TAttribute<FText> MakeAttribute(FJsObject JsObject)
	{
		if (JsObject.GetJsObject()->IsString())
		{
			v8::Local<v8::String> Value = JsObject.GetJsObject().As<v8::String>();
			FString TextString = puerts::FV8Utils::ToFString(JsObject.GetIsolate(), Value);
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

namespace StringConverter
{
	template<typename TType>
	TType Converter(std::string std_str)
	{
		return nullptr;
	}
	template<>
	FColor Converter<FColor>(std::string std_str)
	{
		FString String = FString(std_str.c_str());
		if (String.StartsWith(TEXT("#")))//"#5dc513"
		{
			return FColor::FromHex(String);
		}
		else if (String.StartsWith(TEXT("rgba")))//"rgba(128,19,115,0.3)"
		{
			FString RGBAStripped = String.Mid(5, String.Len() - 6);
			TArray<FString> RGBAValues;
			RGBAStripped.ParseIntoArray(RGBAValues, TEXT(","));

			uint8 R = FCString::Atoi(*RGBAValues[0]);
			uint8 G = FCString::Atoi(*RGBAValues[1]);
			uint8 B = FCString::Atoi(*RGBAValues[2]);
			uint8 A = FCString::Atoi(*RGBAValues[3]);

			return FColor(R, G, B, A);
		}

		return FColor();
	}
};