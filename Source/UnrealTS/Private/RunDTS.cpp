#include "RunDTS.h"
#include "IDeclarationGenerator.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetRegistry/IAssetRegistry.h"

int32 URunDTSCommandlet::Main(const FString& CmdLineParams)
{
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(FName("AssetRegistry"));
	AssetRegistryModule.Get().SearchAllAssets(true);

	IDeclarationGenerator& DeclarationGeneratorModule = FModuleManager::LoadModuleChecked<IDeclarationGenerator>("DeclarationGenerator");
#if ENGINE_MAJOR_VERSION >= 5 && ENGINE_MINOR_VERSION > 0
	DeclarationGeneratorModule.GenReactDeclaration();
#else
	DeclarationGeneratorModule.GenReactDeclaration();
#endif
	return 0;
}
