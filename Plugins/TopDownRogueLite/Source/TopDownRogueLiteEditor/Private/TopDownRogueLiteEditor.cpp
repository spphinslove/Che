// Copyright 2023 Henry Galimberti. All Rights Reserved.

#include "TopDownRogueLiteEditor.h"

#define LOCTEXT_NAMESPACE "FTopDownRogueLiteEditorModule"
#undef LOCTEXT_NAMESPACE

void FTopDownRogueLiteEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

#if WITH_EDITOR
	static const FName PropertyEditor("PropertyEditor");
	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>(PropertyEditor);

#define LOCTEXT_NAMESPACE "PropertySection"
	TSharedRef<FPropertySection> Section = PropertyModule.FindOrCreateSection("Object", "TDRL", LOCTEXT("TDRL", "TDRL"));
	Section->AddCategory("TDRL");
	//Section->AddCategory("GM");
#undef LOCTEXT_NAMESPACE
#endif
}

void FTopDownRogueLiteEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}


	
IMPLEMENT_MODULE(FTopDownRogueLiteEditorModule, TopDownRogueLiteEditor)