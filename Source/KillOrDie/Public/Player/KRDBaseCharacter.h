// KillOrDie. All Rights Reserved.

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "KRDBaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class KILLORDIE_API AKRDBaseCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AKRDBaseCharacter();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    void MoveForward(float Amount);
    void MoveRight(float Amount);
    
    void LookUp(float Amount);
    void TurnAround(float Amount);
};
