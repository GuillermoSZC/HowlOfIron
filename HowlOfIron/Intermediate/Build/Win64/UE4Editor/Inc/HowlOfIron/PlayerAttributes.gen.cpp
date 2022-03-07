// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HowlOfIron/PlayerAttributes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerAttributes() {}
// Cross Module References
	HOWLOFIRON_API UClass* Z_Construct_UClass_UPlayerAttributes_NoRegister();
	HOWLOFIRON_API UClass* Z_Construct_UClass_UPlayerAttributes();
	GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UAttributeSet();
	UPackage* Z_Construct_UPackage__Script_HowlOfIron();
	GAMEPLAYABILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayAttribute();
	GAMEPLAYABILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayAttributeData();
// End Cross Module References
	DEFINE_FUNCTION(UPlayerAttributes::execHealthAttribute)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGameplayAttribute*)Z_Param__Result=P_THIS->HealthAttribute();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPlayerAttributes::execDamageModAttribute)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGameplayAttribute*)Z_Param__Result=P_THIS->DamageModAttribute();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPlayerAttributes::execSpeedAttribute)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FGameplayAttribute*)Z_Param__Result=P_THIS->SpeedAttribute();
		P_NATIVE_END;
	}
	void UPlayerAttributes::StaticRegisterNativesUPlayerAttributes()
	{
		UClass* Class = UPlayerAttributes::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DamageModAttribute", &UPlayerAttributes::execDamageModAttribute },
			{ "HealthAttribute", &UPlayerAttributes::execHealthAttribute },
			{ "SpeedAttribute", &UPlayerAttributes::execSpeedAttribute },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPlayerAttributes_DamageModAttribute_Statics
	{
		struct PlayerAttributes_eventDamageModAttribute_Parms
		{
			FGameplayAttribute ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlayerAttributes_DamageModAttribute_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerAttributes_eventDamageModAttribute_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayAttribute, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlayerAttributes_DamageModAttribute_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlayerAttributes_DamageModAttribute_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPlayerAttributes_DamageModAttribute_Statics::Function_MetaDataParams[] = {
		{ "Category", "Attribute Functions" },
		{ "ModuleRelativePath", "PlayerAttributes.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlayerAttributes_DamageModAttribute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPlayerAttributes, nullptr, "DamageModAttribute", nullptr, nullptr, sizeof(PlayerAttributes_eventDamageModAttribute_Parms), Z_Construct_UFunction_UPlayerAttributes_DamageModAttribute_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayerAttributes_DamageModAttribute_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPlayerAttributes_DamageModAttribute_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayerAttributes_DamageModAttribute_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPlayerAttributes_DamageModAttribute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPlayerAttributes_DamageModAttribute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPlayerAttributes_HealthAttribute_Statics
	{
		struct PlayerAttributes_eventHealthAttribute_Parms
		{
			FGameplayAttribute ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlayerAttributes_HealthAttribute_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerAttributes_eventHealthAttribute_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayAttribute, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlayerAttributes_HealthAttribute_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlayerAttributes_HealthAttribute_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPlayerAttributes_HealthAttribute_Statics::Function_MetaDataParams[] = {
		{ "Category", "Attribute Functions" },
		{ "ModuleRelativePath", "PlayerAttributes.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlayerAttributes_HealthAttribute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPlayerAttributes, nullptr, "HealthAttribute", nullptr, nullptr, sizeof(PlayerAttributes_eventHealthAttribute_Parms), Z_Construct_UFunction_UPlayerAttributes_HealthAttribute_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayerAttributes_HealthAttribute_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPlayerAttributes_HealthAttribute_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayerAttributes_HealthAttribute_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPlayerAttributes_HealthAttribute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPlayerAttributes_HealthAttribute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPlayerAttributes_SpeedAttribute_Statics
	{
		struct PlayerAttributes_eventSpeedAttribute_Parms
		{
			FGameplayAttribute ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPlayerAttributes_SpeedAttribute_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerAttributes_eventSpeedAttribute_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayAttribute, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlayerAttributes_SpeedAttribute_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlayerAttributes_SpeedAttribute_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPlayerAttributes_SpeedAttribute_Statics::Function_MetaDataParams[] = {
		{ "Category", "Attribute Functions" },
		{ "ModuleRelativePath", "PlayerAttributes.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlayerAttributes_SpeedAttribute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPlayerAttributes, nullptr, "SpeedAttribute", nullptr, nullptr, sizeof(PlayerAttributes_eventSpeedAttribute_Parms), Z_Construct_UFunction_UPlayerAttributes_SpeedAttribute_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayerAttributes_SpeedAttribute_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPlayerAttributes_SpeedAttribute_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayerAttributes_SpeedAttribute_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPlayerAttributes_SpeedAttribute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPlayerAttributes_SpeedAttribute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UPlayerAttributes_NoRegister()
	{
		return UPlayerAttributes::StaticClass();
	}
	struct Z_Construct_UClass_UPlayerAttributes_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Speed_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Speed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DamageMod_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_DamageMod;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Health;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPlayerAttributes_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAttributeSet,
		(UObject* (*)())Z_Construct_UPackage__Script_HowlOfIron,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UPlayerAttributes_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPlayerAttributes_DamageModAttribute, "DamageModAttribute" }, // 2119329285
		{ &Z_Construct_UFunction_UPlayerAttributes_HealthAttribute, "HealthAttribute" }, // 3607370410
		{ &Z_Construct_UFunction_UPlayerAttributes_SpeedAttribute, "SpeedAttribute" }, // 1462002116
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerAttributes_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "PlayerAttributes.h" },
		{ "ModuleRelativePath", "PlayerAttributes.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerAttributes_Statics::NewProp_Speed_MetaData[] = {
		{ "Category", "Abilities/Stats" },
		{ "ModuleRelativePath", "PlayerAttributes.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPlayerAttributes_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPlayerAttributes, Speed), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(Z_Construct_UClass_UPlayerAttributes_Statics::NewProp_Speed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerAttributes_Statics::NewProp_Speed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerAttributes_Statics::NewProp_DamageMod_MetaData[] = {
		{ "Category", "Abilities/Stats" },
		{ "ModuleRelativePath", "PlayerAttributes.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPlayerAttributes_Statics::NewProp_DamageMod = { "DamageMod", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPlayerAttributes, DamageMod), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(Z_Construct_UClass_UPlayerAttributes_Statics::NewProp_DamageMod_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerAttributes_Statics::NewProp_DamageMod_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerAttributes_Statics::NewProp_Health_MetaData[] = {
		{ "Category", "Abilities/Stats" },
		{ "ModuleRelativePath", "PlayerAttributes.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPlayerAttributes_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPlayerAttributes, Health), Z_Construct_UScriptStruct_FGameplayAttributeData, METADATA_PARAMS(Z_Construct_UClass_UPlayerAttributes_Statics::NewProp_Health_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerAttributes_Statics::NewProp_Health_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPlayerAttributes_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerAttributes_Statics::NewProp_Speed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerAttributes_Statics::NewProp_DamageMod,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerAttributes_Statics::NewProp_Health,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPlayerAttributes_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlayerAttributes>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPlayerAttributes_Statics::ClassParams = {
		&UPlayerAttributes::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPlayerAttributes_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerAttributes_Statics::PropPointers),
		0,
		0x003000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UPlayerAttributes_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerAttributes_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPlayerAttributes()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPlayerAttributes_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPlayerAttributes, 2795501012);
	template<> HOWLOFIRON_API UClass* StaticClass<UPlayerAttributes>()
	{
		return UPlayerAttributes::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPlayerAttributes(Z_Construct_UClass_UPlayerAttributes, &UPlayerAttributes::StaticClass, TEXT("/Script/HowlOfIron"), TEXT("UPlayerAttributes"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPlayerAttributes);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
