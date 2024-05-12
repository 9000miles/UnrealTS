#pragma once


enum ESlateArgumentType
{
	SLATE_ATTRIBUTE,
	SLATE_ARGUMENT,
	SLATE_STYLE_ARGUMENT,
	SLATE_EVENT,
};

namespace WidgetHelper
{
	struct FArgumentsDTS
	{
		struct FArgument
		{
			FString Name;
			FString Type;
			bool bOptional = true;
			ESlateArgumentType ArgType;
		private:
			FString GetType();
		public:
			FString GenDTS();
		};

		void Add(FString Name, FString Type, ESlateArgumentType ArgType, const bool bOptional = true);

		FString GenDTS();

		FString Name;
		TArray<FArgument> Arguments;
	};

	struct FPropertyDTS
	{
		FString Name;
		FString Type;
		bool bRef = false;
		bool bStatic = false;
		bool bReadonly = false;

		FString GenDTS();
	};

	struct FFunctionDTS
	{
		FString Name;
		TArray<FPropertyDTS> Parameters;
		FPropertyDTS ReturnPara;
		bool bStatic = false;
		bool bVirtual = false;

		FString GenDTS();
	};

	struct FClassDTS
	{
		FString Name;
		FString Super;
		FArgumentsDTS Arguments;
		TArray<FPropertyDTS> Properties;
		TArray<FFunctionDTS> Functions;

		FString GenDTS();
	};

	struct FGenWidgetDTS
	{
		void Add(const FClassDTS& Target);
		void GenDTS();
	private:
		TArray<FClassDTS> AllDts;
	};
}

WidgetHelper::FGenWidgetDTS GenWidgetDTS;