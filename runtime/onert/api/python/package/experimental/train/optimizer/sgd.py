from .optimizer import Optimizer


class SGD(Optimizer):
    """
    Stochastic Gradient Descent (SGD) optimizer.
    """
    def __init__(self, learning_rate=0.001, momentum=0.0):
        """
        Initialize the SGD optimizer.
        Args:
            learning_rate (float): The learning rate for optimization.
            momentum (float): Momentum factor (default: 0.0).
        """
        super().__init__(learning_rate)

        if momentum != 0.0:
            raise NotImplementedError(
                "Momentum is not supported in the current version of SGD.")
        self.momentum = momentum
        self.velocity = None