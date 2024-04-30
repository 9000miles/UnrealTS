#include "CoreMinimal.h"
#include "JsObject.h"
#include "v8.h"

#define SET_WIDGET_ARGUMENT_VARIABLE(Name);\
WidgetArgument::Set_##Name(Arguments, JsObject, #Name)

namespace WidgetArgument
{
	template<typename TArgumentType>
	void Set_Text(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Descriptor;
		if (!JsObject.Has(VariableName, Descriptor)) return;

		if (Descriptor->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.Text(FText::FromString(TextString));
		}
		else if (Descriptor->IsFunction())
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
	void Set_HighlightText(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Descriptor;
		if (!JsObject.Has(VariableName, Descriptor)) return;

		if (Descriptor->IsString())
		{
			FString TextString = FString(JsObject.Get<std::string>(VariableName).c_str());
			Arguments.HighlightText(FText::FromString(TextString));
		}
		else if (Descriptor->IsFunction())
		{
			auto Func = JsObject.Get<std::function<char* ()>>(VariableName);
			TAttribute<FText>::FGetter Getter;
			Getter.BindLambda([Func]()
				{
					const char* Result = Func();
					return Result ? FText::FromString(Result) : FText();
				});
			Arguments._HighlightText.Bind(Getter);
		}
	}
	template<typename TArgumentType>
	void Set_ColorAndOpacity(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Descriptor;
		if (!JsObject.Has(VariableName, Descriptor)) return;

		if (Descriptor->IsString())
		{
			FString String = FString(JsObject.Get<std::string>(VariableName).c_str());
			if (String.StartsWith(TEXT("#")))//"#5dc513"
			{
				FColor Color = FColor::FromHex(String);
				Arguments.ColorAndOpacity(Color);
			}
			else if (String.StartsWith(TEXT("rgba")))//"rgba(128,19,115,0.3)"
			{
				//FString String = TEXT("rgba(128,19,115,0.3)");
				// 分割字符串并提取RGB值
				FString RGBAStripped = String.Mid(5, String.Len() - 6); // 去掉"rgba("和")"
				TArray<FString> RGBAValues;
				RGBAStripped.ParseIntoArray(RGBAValues, TEXT(","));

				// 提取RGB值并转换为uint8
				uint8 R = FCString::Atoi(*RGBAValues[0]);
				uint8 G = FCString::Atoi(*RGBAValues[1]);
				uint8 B = FCString::Atoi(*RGBAValues[2]);
				uint8 A = FCString::Atoi(*RGBAValues[3]);

				// 创建FColor对象，这里忽略alpha值
				FColor Color(R, G, B, A);
				Arguments.ColorAndOpacity(Color);
			}
		}
		else if (Descriptor->IsObject())
		{
			FSlateColor ColorAndOpacity = JsObject.Get<FSlateColor>(VariableName);
			Arguments.ColorAndOpacity(ColorAndOpacity);
		}
	}
	template<typename TArgumentType>
	void Set_OnClicked(TArgumentType& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Descriptor;
		if (!JsObject.Has(VariableName, Descriptor)) return;

		auto Func = JsObject.Get<std::function<void()>>(VariableName);
		Arguments._OnClicked.BindLambda([Func]() { Func(); return FReply::Handled(); });
	}

	void Set_OnClicked1(SButton::FArguments& Arguments, FJsObject JsObject, const char* VariableName)
	{
		v8::Local<v8::Value> Descriptor;
		if (JsObject.Has(VariableName, Descriptor))
		{
			auto ClickFunc = JsObject.Get<std::function<void()>>(VariableName);
			//FOnClicked  Delegate = FOnClicked::CreateLambda([ClickFunc]() { ClickFunc(); return FReply::Handled(); });
			//Arguments.OnClicked_Lambda(Delegate);
			//Arguments.OnClicked_Lambda([ClickFunc]() { ClickFunc(); return FReply::Handled(); });
			Arguments._OnClicked.BindLambda([ClickFunc]() { ClickFunc(); return FReply::Handled(); });
			//Arguments._OnClicked= Delegate;
		};
	}

};