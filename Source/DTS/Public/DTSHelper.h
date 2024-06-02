#pragma once

#include "CoreMinimal.h"
#include "DTSArguments.h"

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
	protected:
		FString _Name;
		FString _Super;
		DTSArguments _Arguments = DTSArguments("");
		TArray<Property> _Properties;
		TArray<Function> _Functions;

	public:
		Class& Name(const FString& Value) { _Name = Value; return *this; }
		Class& Super(const FString& Value) { _Super = Value; return *this; }
		Class& Arguments(const DTSArguments& Value) { _Arguments = Value; return *this; }
		Class& Properties(const TArray<Property>& Value) { _Properties = Value; return *this; }
		Class& Functions(const TArray<Function>& Value) { _Functions = Value; return *this; }

		FString GenDTS();
		FString GetName() { return _Name; };
	};

	struct WidgetClass :public Class
	{
	private:

	public:
		//FString GenDTS();
	};

	struct DTS_API FClassDTS
	{
		static void Add(Class& Target);
		static void GenDTS();
	private:
		TArray<Class> AllDts;
	public:
		static DTS::FClassDTS GenClassDTS;
	};
}
