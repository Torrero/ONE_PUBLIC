from onert.native.libnnfw_api_pybind import loss_reduction


class LossFunction:
    """
    Base class for loss functions with reduction type.
    """
    def __init__(self, reduction="mean"):
        """
        Initialize the Categorical Cross-Entropy loss function.
        Args:
            reduction (str): Reduction type ('mean', 'sum').
        """
        reduction_mapping = {
            "mean": loss_reduction.SUM_OVER_BATCH_SIZE,
            "sum": loss_reduction.SUM
        }

        # Validate and assign the reduction type
        if reduction not in reduction_mapping:
            raise ValueError(
                f"Invalid reduction type. Choose from {list(reduction_mapping.keys())}.")

        self.reduction = reduction_mapping[reduction]