//#pragma once
//
//#include "CoreMinimal.h"
//#include "TypeInfo.hpp"
//#include "WidgetArguments.h"
//
//
//
//void Plan()
//{
//	DTS::Class CC = DTS::Class().Name("ClassA").Super("BaseClass")
//		.Arguments(DTS::WidgetArguments("Test"))
//		.Properties(DTS::Array<DTS::Property>()
//			+ DTS::Property().Name("P1").Type("bool").Out(false).Static(true).Readonly(true)
//			+ DTS::Property().Name("P2").Type("bool").Out(false).Static(true).Readonly(true)
//		)
//		.Functions(DTS::Array<DTS::Function>()
//			+ DTS::Function()
//			[
//				DTS::Function::Slot().Name("Func1")
//					.Parameters(DTS::Array<DTS::Property>()
//						+ DTS::Property().Name("P1").Type("bool").Out(false).Static(true).Readonly(true)
//						+ DTS::Property().Name("P2").Type("bool").Out(false).Static(true).Readonly(true)
//					)
//					.Return(DTS::Property().Type("float"))
//					.Static(true)
//					.Virtual(true)
//			]
//			+ DTS::Function()
//			[
//				DTS::Function::Slot().Name("Func1")
//					.Parameters(DTS::Array<DTS::Property>()
//						+ DTS::Property().Name("P1").Type("bool").Out(false).Static(true).Readonly(true)
//						+ DTS::Property().Name("P2").Type("bool").Out(false).Static(true).Readonly(true)
//					)
//					.Return(DTS::Property().Type("float"))
//					.Static(true)
//					.Virtual(true)
//			]
//		);
//
//#if 0
//#define TS_string ""
//	DTS::Class DTS_STextBlock = DTS::Class().Name("STextBlock").Super("SLeafWidget")
//		.Arguments(DTS::WidgetArguments())
//		.Properties(DTS::Array<DTS::Property>()
//			+ DTS::Property().Name("P1").Type("bool").Out(false).Static(true).Readonly(true)
//			+ DTS::Property().Name("P2").Type("bool").Out(false).Static(true).Readonly(true)
//		)
//		.Functions(DTS::Array<DTS::Function>()
//			+ DTS::Function()
//			[
//				DTS::Function::Slot().Name("SNew")
//					.Parameters(DTS::Array<DTS::Property>()
//						+ DTS::Property().Name("Arguments").Type("STextBlock.Arguments")
//						+ DTS::Property().Name("Filename").Type(TS_string)
//					)
//					.Return(DTS::Property().Type(PUERTS_NAMESPACE::ScriptTypeName<TSharedPtr<STextBlock>>::value().Data()))
//					.Static(true)
//			]
//			+ DTS::Function()
//			[
//				DTS::Function::Slot().Name("SAssignNew")
//					.Parameters(DTS::Array<DTS::Property>()
//						+ DTS::Property().Name("WidgetRef").Type(PUERTS_NAMESPACE::ScriptTypeName<TSharedPtr<STextBlock>>::value().Data()).Out(true)
//						+ DTS::Property().Name("Arguments").Type("STextBlock.Arguments")
//						+ DTS::Property().Name("Filename").Type(TS_string)
//					)
//					.Static(true)
//			]
//			+ DTS::Function()
//			[
//				DTS::Function::Slot().Name("MakeShared")
//					.Return(DTS::Property().Type(PUERTS_NAMESPACE::ScriptTypeName<TSharedPtr<STextBlock>>::value().Data()))
//					.Static(true)
//			]
//			+ DTS::Function()
//			[
//				DTS::Function::Slot().Name("GetText")
//					.Return(DTS::Property().Type(TS_string))
//			]
//			+ DTS::Function()
//			[
//				DTS::Function::Slot().Name("SetText")
//					.Parameters(DTS::Array<DTS::Property>()
//						//+ DTS::Property().Name("Text").Type(PUERTS_NAMESPACE::ScriptTypeName<TAttribute<FText>>::value().Data())
//					)
//			]
//		);
//#endif
//}