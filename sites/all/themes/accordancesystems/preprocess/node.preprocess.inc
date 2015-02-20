<?php

/**
 * Implements hook_preprocess_node().
 */
function accordancesystems_preprocess_node(&$variables) {
  switch ($variables['type']) {
    case 'dealer':
      if ($variables['elements']['#view_mode'] == 'dealer_listing') {
        // Change the url title to be consistent.
        if (!empty($variables['content']['field_dealer_url'])) {
          $variables['content']['field_dealer_url'][0]['#element']['title'] = 'Visit website';
        }
      }
      break;
  }
}
