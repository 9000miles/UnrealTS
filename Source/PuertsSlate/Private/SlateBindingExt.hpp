
#if 1
//namespace aaaa
{

	//SLATE_DECLARE_WIDGET(STextBlock, SLeafWidget)
private:
	using Super = SLeafWidget;
	using ThisClass = STextBlock;
	using PrivateThisType = STextBlock;
	using PrivateParentType = SLeafWidget;
	template<class STextBlock, bool bIsUserWidget>
	friend struct TWidgetAllocator;
	template <typename ObjectType, ESPMode Mode>
	friend class SharedPointerInternals::TIntrusiveReferenceController;
	static const FSlateWidgetClassData& GetPrivateWidgetClass() {
		static FSlateWidgetClassData WidgetClassDataInstance = FSlateWidgetClassData(TIdentity<SLeafWidget>(), "STextBlock", &STextBlock::PrivateRegisterAttributes);
		return WidgetClassDataInstance;
	}
	static void PrivateRegisterAttributes(FSlateAttributeInitializer&);
	//public:
	static const FSlateWidgetClassData& StaticWidgetClass() {
		return GetPrivateWidgetClass();
	}
	virtual const FSlateWidgetClassData& GetWidgetClass() const override {
		return GetPrivateWidgetClass();
	}



	auto sfs = SNew(STextBlock);
	TSharedPtr<STextBlock> bsso = SNew(STextBlock);

	//SNew(STextBlock);
	MakeTDecl<STextBlock>(
		"STextBlock",
		"E:\\UE\\5.0\\PuertsAndSlate\\Plugins\\PuertsSlate\\Source\\PuertsSlate\\Private\\SlateBinding.hpp",
		140,
		RequiredArgs::MakeRequiredArgs()
	) <<= STextBlock::FArguments();

	//SLATE_BEGIN_ARGS( STextBlock )
		//public:
	struct FArguments : public TSlateBaseNamedArgs<STextBlock> {
		typedef FArguments WidgetArgsType;
		__declspec(noinline) FArguments() {}

		//SLATE_ATTRIBUTE(FText, Text)
		TAttribute< FText > _Text;
		WidgetArgsType& Text(TAttribute< FText > InAttribute) {
			_Text = MoveTemp(InAttribute);
			return static_cast<WidgetArgsType*>(this)->Me();
		}
		template< typename... VarTypes > WidgetArgsType& Text_Static(typename TAttribute< FText >::FGetter::template FStaticDelegate<VarTypes...>::FFuncPtr InFunc, VarTypes... Vars) {
			_Text = TAttribute< FText >::Create(TAttribute< FText >::FGetter::CreateStatic(InFunc, Vars...));
			return static_cast<WidgetArgsType*>(this)->Me();
		}
		WidgetArgsType& Text_Lambda(TFunction< FText(void) >&& InFunctor) {
			_Text = TAttribute< FText >::Create(Forward<TFunction< FText(void) >>(InFunctor));
			return static_cast<WidgetArgsType*>(this)->Me();
		}
		template< class UserClass, typename... VarTypes > WidgetArgsType& Text_Raw(UserClass* InUserObject, typename TAttribute< FText >::FGetter::template TConstMethodPtr< UserClass, VarTypes... > InFunc, VarTypes... Vars) {
			_Text = TAttribute< FText >::Create(TAttribute< FText >::FGetter::CreateRaw(InUserObject, InFunc, Vars...));
			return static_cast<WidgetArgsType*>(this)->Me();
		}
		template< class UserClass, typename... VarTypes > WidgetArgsType& Text(TSharedRef< UserClass > InUserObjectRef, typename TAttribute< FText >::FGetter::template TConstMethodPtr< UserClass, VarTypes... > InFunc, VarTypes... Vars) {
			_Text = TAttribute< FText >::Create(TAttribute< FText >::FGetter::CreateSP(InUserObjectRef, InFunc, Vars...));
			return static_cast<WidgetArgsType*>(this)->Me();
		}
		template< class UserClass, typename... VarTypes > WidgetArgsType& Text(UserClass* InUserObject, typename TAttribute< FText >::FGetter::template TConstMethodPtr< UserClass, VarTypes... > InFunc, VarTypes... Vars) {
			_Text = TAttribute< FText >::Create(TAttribute< FText >::FGetter::CreateSP(InUserObject, InFunc, Vars...));
			return static_cast<WidgetArgsType*>(this)->Me();
		}
		template< class UserClass, typename... VarTypes > WidgetArgsType& Text_UObject(UserClass* InUserObject, typename TAttribute< FText >::FGetter::template TConstMethodPtr< UserClass, VarTypes... > InFunc, VarTypes... Vars) {
			_Text = TAttribute< FText >::Create(TAttribute< FText >::FGetter::CreateUObject(InUserObject, InFunc, Vars...));
			return static_cast<WidgetArgsType*>(this)->Me();
		}
	};
	};
#endif