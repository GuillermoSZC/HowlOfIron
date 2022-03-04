// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HowlOfIron/HowlOfIronGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHowlOfIronGameMode() {}
// Cross Module References
	HOWLOFIRON_API UClass* Z_Construct_UClass_AHowlOfIronGameMode_NoRegister();
	HOWLOFIRON_API UClass* Z_Construct_UClass_AHowlOfIronGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_HowlOfIron();
// End Cross Module References
	void AHowlOfIronGameMode::StaticRegisterNativesAHowlOfIronGameMode()
	{
	}
	UClass* Z_Construct_UClass_AHowlOfIronGameMode_NoRegister()
	{
		return AHowlOfIronGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AHowlOfIronGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHowlOfIronGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_HowlOfIron,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHowlOfIronGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "HowlOfIronGameMode.h" },
		{ "ModuleRelativePath", "HowlOfIronGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHowlOfIronGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHowlOfIronGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHowlOfIronGameMode_Statics::ClassParams = {
		&AHowlOfIronGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AHowlOfIronGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AHowlOfIronGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHowlOfIronGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHowlOfIronGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHowlOfIronGameMode, 1306404684);
	template<> HOWLOFIRON_API UClass* StaticClass<AHowlOfIronGameMode>()
	{
		return AHowlOfIronGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHowlOfIronGameMode(Z_Construct_UClass_AHowlOfIronGameMode, &AHowlOfIronGameMode::StaticClass, TEXT("/Script/HowlOfIron"), TEXT("AHowlOfIronGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHowlOfIronGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
