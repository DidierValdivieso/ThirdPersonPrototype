#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

UCLASS(Blueprintable)
class UECOURSE_API UItem : public UObject
{
	GENERATED_BODY()

public:
	/** Devuelve el nombre del objeto. */
	FName name() const
	{
		return name_;
	}

	/** Establece el nombre del objeto. */
	void set_name(FName name_to_set)
	{
		name_ = name_to_set;
	}
	
private:
	/** Nombre del objeto, editable en el editor. */
	UPROPERTY(EditAnywhere, Category = "Core", meta = (DisplayName = "Name"))
	FName name_{};

};
