#pragma once

#include "CoreMinimal.h"
#include "TypeInfo.hpp"

enum ESlateArgumentType
{
	SLATE_ATTRIBUTE,
	SLATE_ARGUMENT,
	SLATE_STYLE_ARGUMENT,
	SLATE_EVENT,
};

namespace DTS
{
	template<typename T>
	struct Array
	{
		TArray<T> Items;

		Array& operator+(const T& Element)
		{
			Items.Add(Element);
			return *this;
		}

		operator TArray<T>() const { return Items; }
	};

	struct WidgetArguments
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

		template<typename T>
		void Add(FString InName, ESlateArgumentType ArgType, const bool bOptional = true)
		{
			Arguments.Add({ InName, puerts::ScriptTypeNameWithNamespace<T>::value().Data(), bOptional, ArgType});
		}
		template<>
		void Add<FOnClicked>(FString InName, ESlateArgumentType ArgType, const bool bOptional)
		{
			Arguments.Add({ InName, "cpp.FReply", bOptional, ArgType });
		}
		template<>
		void Add<FSimpleDelegate>(FString InName, ESlateArgumentType ArgType, const bool bOptional)
		{
			Arguments.Add({ InName, "() => void", bOptional, ArgType});
		}
		template<>
		void Add<FPointerEventHandler>(FString InName, ESlateArgumentType ArgType, const bool bOptional)
		{
			Arguments.Add({ InName, "(Geometry: UE.Geometry, PointerEvent : UE.PointerEvent) => cpp.FReply", bOptional, ArgType });
		}

		FString GenDTS();

		FString Name;
		TArray<FArgument> Arguments;
	};

	struct Property
	{
	private:
		FString _Name;
		FString _Type = "void";
		bool _bRef = false;
		bool _bStatic = false;
		bool _bReadonly = false;

	public:
		Property& Name(const FString& Value) { _Name = Value; return *this; }
		Property& Type(const FString& Value) { _Type = Value; return *this; }
		Property& Out(const bool& Value) { _bRef = Value; return *this; }
		Property& Static(const bool& Value) { _bStatic = Value; return *this; }
		Property& Readonly(const bool& Value) { _bReadonly = Value; return *this; }

		FString GenDTS();
	};

	struct Function
	{
		struct Slot
		{
			friend Function;
		private:
			FString _Name;
			TArray<Property> _Parameters;
			Property _Return;
			bool _bStatic = false;
			bool _bVirtual = false;

		public:
			Slot& Name(const FString& Value) { _Name = Value; return *this; }
			Slot& Parameters(const TArray<Property>& Value) { _Parameters = Value; return *this; }
			Slot& Return(const Property& Value) { _Return = Value; return *this; }
			Slot& Static(const bool& Value) { _bStatic = Value; return *this; }
			Slot& Virtual(const bool& Value) { _bVirtual = Value; return *this; }
		};

		Function& operator[](const Slot& Value)
		{
			slot = Value;
			return *this;
		}
	private: Slot slot;
	public: FString GenDTS();
	};

	struct Class
	{
	private:
		FString _Name;
		FString _Super;
		WidgetArguments _Arguments;
		TArray<Property> _Properties;
		TArray<Function> _Functions;

	public:
		Class& Name(const FString& Value) { _Name = Value; return *this; }
		Class& Super(const FString& Value) { _Super = Value; return *this; }
		Class& Arguments(const WidgetArguments& Value) { _Arguments = Value; return *this; }
		Class& Properties(const TArray<Property>& Value) { _Properties = Value; return *this; }
		Class& Functions(const TArray<Function>& Value) { _Functions = Value; return *this; }

		FString GenDTS();
		FString GetName() { return _Name; };
	};

	struct FGenWidgetDTS
	{
		void Add(const Class& Target);
		void GenDTS();
	private:
		TArray<Class> AllDts;
	};
}

DTS::FGenWidgetDTS GenWidgetDTS;


void Plan()
{
	DTS::Class CC = DTS::Class().Name("ClassA").Super("BaseClass")
		.Arguments(DTS::WidgetArguments())
		.Properties(DTS::Array<DTS::Property>()
			+ DTS::Property().Name("P1").Type("bool").Out(false).Static(true).Readonly(true)
			+ DTS::Property().Name("P2").Type("bool").Out(false).Static(true).Readonly(true)
		)
		.Functions(DTS::Array<DTS::Function>()
			+ DTS::Function()
			[
				DTS::Function::Slot().Name("Func1")
					.Parameters(DTS::Array<DTS::Property>()
						+ DTS::Property().Name("P1").Type("bool").Out(false).Static(true).Readonly(true)
						+ DTS::Property().Name("P2").Type("bool").Out(false).Static(true).Readonly(true)
					)
					.Return(DTS::Property().Type("float"))
					.Static(true)
					.Virtual(true)
			]
			+ DTS::Function()
			[
				DTS::Function::Slot().Name("Func1")
					.Parameters(DTS::Array<DTS::Property>()
						+ DTS::Property().Name("P1").Type("bool").Out(false).Static(true).Readonly(true)
						+ DTS::Property().Name("P2").Type("bool").Out(false).Static(true).Readonly(true)
					)
					.Return(DTS::Property().Type("float"))
					.Static(true)
					.Virtual(true)
			]
		);

#if 0
#define TS_string ""
	DTS::Class DTS_STextBlock = DTS::Class().Name("STextBlock").Super("SLeafWidget")
		.Arguments(DTS::WidgetArguments())
		.Properties(DTS::Array<DTS::Property>()
			+ DTS::Property().Name("P1").Type("bool").Out(false).Static(true).Readonly(true)
			+ DTS::Property().Name("P2").Type("bool").Out(false).Static(true).Readonly(true)
		)
		.Functions(DTS::Array<DTS::Function>()
			+ DTS::Function()
			[
				DTS::Function::Slot().Name("SNew")
					.Parameters(DTS::Array<DTS::Property>()
						+ DTS::Property().Name("Arguments").Type("STextBlock.Arguments")
						+ DTS::Property().Name("Filename").Type(TS_string)
					)
					.Return(DTS::Property().Type(PUERTS_NAMESPACE::ScriptTypeName<TSharedPtr<STextBlock>>::value().Data()))
					.Static(true)
			]
			+ DTS::Function()
			[
				DTS::Function::Slot().Name("SAssignNew")
					.Parameters(DTS::Array<DTS::Property>()
						+ DTS::Property().Name("WidgetRef").Type(PUERTS_NAMESPACE::ScriptTypeName<TSharedPtr<STextBlock>>::value().Data()).Out(true)
						+ DTS::Property().Name("Arguments").Type("STextBlock.Arguments")
						+ DTS::Property().Name("Filename").Type(TS_string)
					)
					.Static(true)
			]
			+ DTS::Function()
			[
				DTS::Function::Slot().Name("MakeShared")
					.Return(DTS::Property().Type(PUERTS_NAMESPACE::ScriptTypeName<TSharedPtr<STextBlock>>::value().Data()))
					.Static(true)
			]
			+ DTS::Function()
			[
				DTS::Function::Slot().Name("GetText")
					.Return(DTS::Property().Type(TS_string))
			]
			+ DTS::Function()
			[
				DTS::Function::Slot().Name("SetText")
					.Parameters(DTS::Array<DTS::Property>()
						//+ DTS::Property().Name("Text").Type(PUERTS_NAMESPACE::ScriptTypeName<TAttribute<FText>>::value().Data())
					)
			]
		);
#endif
}