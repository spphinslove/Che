// Copyright 2023 Henry Galimberti. All Rights Reserved.


#include "TDRL_BTDecorator.h"

UTDRL_BTDecorator::UTDRL_BTDecorator()
	: Super()
{
}

FString UTDRL_BTDecorator::GetStaticDescription() const
{
	FString FlowAbortDesc;
	if (FlowAbortMode != EBTFlowAbortMode::None)
	{
		FlowAbortDesc = FString::Printf(
			TEXT("(aborts %s)%s"), *UBehaviorTreeTypes::DescribeFlowAbortMode(FlowAbortMode).ToLower(),
			LINE_TERMINATOR);
	}

	return FlowAbortDesc;
}
