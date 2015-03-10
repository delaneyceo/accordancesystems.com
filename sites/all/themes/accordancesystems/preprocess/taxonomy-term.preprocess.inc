<?php

/**
 * Implements hook_preprocess_taxonomy_term().
 */
function accordancesystems_preprocess_taxonomy_term(&$variables) {
  $variables['print_term_anchor'] = TRUE;

  switch ($variables['vocabulary_machine_name']) {
    case 'solutions':
      $variables['print_term_anchor'] = FALSE;
      break;

    case 'product_controller_features':
      $variables['print_term_anchor'] = FALSE;
      break;
  }
}
